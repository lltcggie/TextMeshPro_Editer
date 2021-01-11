#include <iostream>
#include "TMP_1_0_26.h"
#include "TMP_1_4_0.h"
#include "TMP_1_4_0_LoR.h"
#include <vector>
#include <stdio.h>
#include <algorithm>


std::vector<uint8_t> readFile(const char* fname)
{
	FILE* fp = fopen(fname, "rb");
	if (!fp) {
		return std::vector<uint8_t>();
	}

	fseek(fp, 0, SEEK_END);
	const auto size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	std::vector<uint8_t> buf;
	buf.resize(size);
	fread(buf.data(), 1, size, fp);
	fclose(fp);

	return buf;
}

bool writeFile(const char* fname, const std::vector<uint8_t>& data)
{
	FILE* fp = fopen(fname, "wb");
	if (!fp) {
		return false;
	}

	fwrite(data.data(), 1, data.size(), fp);
	fclose(fp);

	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 4) {
		printf("%s src dst out\n", argv[0]);
		return 1;
	}

	TMP_1_4_0::TMP_FontAsset src;
	TMP_1_4_0_LoR::TMP_FontAsset dst;

	{
		std::vector<uint8_t> buf = readFile(argv[1]);
		Deserializer d;
		d.setData(buf);
		d >> src;
	}

	{
		std::vector<uint8_t> buf = readFile(argv[2]);
		Deserializer d;
		d.setData(buf);
		d >> dst;
	}

	dst.mAtlasPopuatuionMode = src.mAtlasPopuatuionMode;
	dst.m_FaceInfo = src.m_FaceInfo;
	dst.m_GlyphTable = src.m_GlyphTable;
	dst.m_CharacterTable = src.m_CharacterTable;
	dst.m_UsedGlyphRects = src.m_UsedGlyphRects;
	dst.m_FreeGlyphRects = src.m_FreeGlyphRects;
	dst.m_fontInfo = src.m_fontInfo;
	dst.m_AtlasWidth = src.m_AtlasWidth;
	dst.m_AtlasHeight = src.m_AtlasHeight;
	dst.m_AtlasPadding = src.m_AtlasPadding;
	dst.m_AtlasRenderMode = src.m_AtlasRenderMode;
	dst.m_glyphInfoList = src.m_glyphInfoList;
	dst.m_KerningTable = src.m_KerningTable;
	dst.m_FontFeatureTable = src.m_FontFeatureTable;
	dst.m_FontWeightTable = src.m_FontWeightTable;
	dst.fontWeights = src.fontWeights;
	dst.normalStyle = src.normalStyle;
	dst.normalSpacingOffset = src.normalSpacingOffset;
	dst.boldStyle = src.boldStyle;
	dst.boldSpacing = src.boldSpacing;
	dst.italicStyle = src.italicStyle;
	dst.tabSize = src.tabSize;

	{
		Serializer s;
		s << dst;
		writeFile(argv[3], s.getData());
	}

	return 0;
}
