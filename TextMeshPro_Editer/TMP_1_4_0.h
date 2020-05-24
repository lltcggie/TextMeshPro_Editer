#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>
#include "Serializer_Deserializer.h"

// 置換用正規表現メモ
// ^.+\s
// s << o.

// TMP 1.4.0

struct PPtrObject
{
    int32_t m_FileID;
    int64_t m_PathID;

    friend Serializer& operator<<(Serializer& s, const PPtrObject& o)
    {
        s << o.m_FileID;
        s << o.m_PathID;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, PPtrObject& o)
    {
        d >> o.m_FileID;
        d >> o.m_PathID;
        return d;
    }
};

struct FaceInfo
{
    std::string m_FamilyName;
    std::string m_StyleName;
    int32_t m_PointSize;
    float m_Scale;
    float m_LineHeight;
    float m_AscentLine;
    float m_CapLine;
    float m_MeanLine;
    float m_BaseLine;
    float m_DescentLine;
    float m_SupersscriptOffset;
    float m_SupersscriptSize;
    float m_SubsscriptOffset;
    float m_SubsscriptSize;
    float m_UnderlineOffset;
    float m_UnderlineThickness;
    float m_StrikethroughSize;
    float m_StrikethroughThickness;
    float m_TabSize;

    friend Serializer& operator<<(Serializer& s, const FaceInfo& o)
    {
        s << o.m_FamilyName;
        s << o.m_StyleName;
        s << o.m_PointSize;
        s << o.m_Scale;
        s << o.m_LineHeight;
        s << o.m_AscentLine;
        s << o.m_CapLine;
        s << o.m_MeanLine;
        s << o.m_BaseLine;
        s << o.m_DescentLine;
        s << o.m_SupersscriptOffset;
        s << o.m_SupersscriptSize;
        s << o.m_SubsscriptOffset;
        s << o.m_SubsscriptSize;
        s << o.m_UnderlineOffset;
        s << o.m_UnderlineThickness;
        s << o.m_StrikethroughSize;
        s << o.m_StrikethroughThickness;
        s << o.m_TabSize;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, FaceInfo& o)
    {
        d >> o.m_FamilyName;
        d >> o.m_StyleName;
        d >> o.m_PointSize;
        d >> o.m_Scale;
        d >> o.m_LineHeight;
        d >> o.m_AscentLine;
        d >> o.m_CapLine;
        d >> o.m_MeanLine;
        d >> o.m_BaseLine;
        d >> o.m_DescentLine;
        d >> o.m_SupersscriptOffset;
        d >> o.m_SupersscriptSize;
        d >> o.m_SubsscriptOffset;
        d >> o.m_SubsscriptSize;
        d >> o.m_UnderlineOffset;
        d >> o.m_UnderlineThickness;
        d >> o.m_StrikethroughSize;
        d >> o.m_StrikethroughThickness;
        d >> o.m_TabSize;
        return d;
    }
};

struct GlyphMetrices
{
    float m_Width;
    float m_Height;
    float m_HorizontalBearingX;
    float m_HorizontalBearingY;
    float m_HorizontalAdvance;

    friend Serializer& operator<<(Serializer& s, const GlyphMetrices& o)
    {
        s << o.m_Width;
        s << o.m_Height;
        s << o.m_HorizontalBearingX;
        s << o.m_HorizontalBearingY;
        s << o.m_HorizontalAdvance;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, GlyphMetrices& o)
    {
        d >> o.m_Width;
        d >> o.m_Height;
        d >> o.m_HorizontalBearingX;
        d >> o.m_HorizontalBearingY;
        d >> o.m_HorizontalAdvance;
        return d;
    }
};

struct GlyphRect
{
    int32_t m_X;
    int32_t m_Y;
    int32_t m_Width;
    int32_t m_Height;

    friend Serializer& operator<<(Serializer& s, const GlyphRect& o)
    {
        s << o.m_X;
        s << o.m_Y;
        s << o.m_Width;
        s << o.m_Height;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, GlyphRect& o)
    {
        d >> o.m_X;
        d >> o.m_Y;
        d >> o.m_Width;
        d >> o.m_Height;
        return d;
    }
};

struct Glyph
{
    int32_t m_Index;
    GlyphMetrices m_Metrices;
    GlyphRect m_GlyphRect;
    float m_Scale;
    int32_t m_AtlasIndex;

    friend Serializer& operator<<(Serializer& s, const Glyph& o)
    {
        s << o.m_Index;
        s << o.m_Metrices;
        s << o.m_GlyphRect;
        s << o.m_Scale;
        s << o.m_AtlasIndex;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, Glyph& o)
    {
        d >> o.m_Index;
        d >> o.m_Metrices;
        d >> o.m_GlyphRect;
        d >> o.m_Scale;
        d >> o.m_AtlasIndex;;
        return d;
    }
};

struct TMP_Character
{
    int32_t m_ElementType;
    int32_t m_Unicode;
    int32_t m_GlyphIndex;
    float m_Scale;

    friend Serializer& operator<<(Serializer& s, const TMP_Character& o)
    {
        s << o.m_ElementType;
        s << o.m_Unicode;
        s << o.m_GlyphIndex;
        s << o.m_Scale;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, TMP_Character& o)
    {
        d >> o.m_ElementType;
        d >> o.m_Unicode;
        d >> o.m_GlyphIndex;
        d >> o.m_Scale;
        return d;
    }
};

struct FaceInfo_Legacy
{
    std::string Name;
    float PointSize;
    float Scale;
    int32_t CharacterCount;
    float LineHeight;
    float Baseline;
    float Ascender;
    float CapHeight;
    float Descender;
    float CenterLine;
    float SuperscriptOffset;
    float SubscriptOffset;
    float SubSize;
    float Underline;
    float UnderlineThickness;
    float strikethrough;
    float strikethroughThickness;
    float TabWidth;
    float Padding;
    float AtlasWidth;
    float AtlasHeight;

    friend Serializer& operator<<(Serializer& s, const FaceInfo_Legacy& o)
    {
        s << o.Name;
        s << o.PointSize;
        s << o.Scale;
        s << o.CharacterCount;
        s << o.LineHeight;
        s << o.Baseline;
        s << o.Ascender;
        s << o.CapHeight;
        s << o.Descender;
        s << o.CenterLine;
        s << o.SuperscriptOffset;
        s << o.SubscriptOffset;
        s << o.SubSize;
        s << o.Underline;
        s << o.UnderlineThickness;
        s << o.strikethrough;
        s << o.strikethroughThickness;
        s << o.TabWidth;
        s << o.Padding;
        s << o.AtlasWidth;
        s << o.AtlasHeight;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, FaceInfo_Legacy& o)
    {
        d >> o.Name;
        d >> o.PointSize;
        d >> o.Scale;
        d >> o.CharacterCount;
        d >> o.LineHeight;
        d >> o.Baseline;
        d >> o.Ascender;
        d >> o.CapHeight;
        d >> o.Descender;
        d >> o.CenterLine;
        d >> o.SuperscriptOffset;
        d >> o.SubscriptOffset;
        d >> o.SubSize;
        d >> o.Underline;
        d >> o.UnderlineThickness;
        d >> o.strikethrough;
        d >> o.strikethroughThickness;
        d >> o.TabWidth;
        d >> o.Padding;
        d >> o.AtlasWidth;
        d >> o.AtlasHeight;
        return d;
    }
};

struct TMP_Glyph
{
    int32_t id;
    float x;
    float y;
    float width;
    float height;
    float xOffset;
    float yOffset;
    float xAdvance;
    float scale;

    friend Serializer& operator<<(Serializer& s, const TMP_Glyph& o)
    {
        s << o.id;
        s << o.x;
        s << o.y;
        s << o.width;
        s << o.height;
        s << o.xOffset;
        s << o.yOffset;
        s << o.xAdvance;
        s << o.scale;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, TMP_Glyph& o)
    {
        d >> o.id;
        d >> o.x;
        d >> o.y;
        d >> o.width;
        d >> o.height;
        d >> o.xOffset;
        d >> o.yOffset;
        d >> o.xAdvance;
        d >> o.scale;
        return d;
    }
};

struct KerningPair
{
    uint8_t m_FirstGlyph;
    // TODO: 必要になったら書く

    friend Serializer& operator<<(Serializer& s, const KerningPair& o)
    {
        // TODO: 必要になったら書く
        assert(0);
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, KerningPair& o)
    {
        // TODO: 必要になったら書く
        assert(0);
        return d;
    }
};

struct KerningTable
{
    std::vector<KerningPair> kerningPairs;

    friend Serializer& operator<<(Serializer& s, const KerningTable& o)
    {
        s << o.kerningPairs;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, KerningTable& o)
    {
        d >> o.kerningPairs;
        return d;
    }
};

struct TMP_GlyphValueRecord
{
    float m_XPlacement;
    float m_YPlacement;
    float m_XAdvance;
    float m_YAdvance;

    friend Serializer& operator<<(Serializer& s, const TMP_GlyphValueRecord& o)
    {
        s << o.m_XPlacement;
        s << o.m_YPlacement;
        s << o.m_XAdvance;
        s << o.m_YAdvance;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, TMP_GlyphValueRecord& o)
    {
        d >> o.m_XPlacement;
        d >> o.m_YPlacement;
        d >> o.m_XAdvance;
        d >> o.m_YAdvance;
        return d;
    }
};

struct TMP_GlyphAdjustmentRecord
{
    uint32_t m_GlyphIndex;
    TMP_GlyphValueRecord m_GlyphValueRecord;

    friend Serializer& operator<<(Serializer& s, const TMP_GlyphAdjustmentRecord& o)
    {
        s << o.m_GlyphIndex;
        s << o.m_GlyphValueRecord;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, TMP_GlyphAdjustmentRecord& o)
    {
        d >> o.m_GlyphIndex;
        d >> o.m_GlyphValueRecord;
        return d;
    }
};

struct TMP_GlyphPairAdjustmentRecord
{
    TMP_GlyphAdjustmentRecord m_FirstAdjustmentRecord;
    TMP_GlyphAdjustmentRecord m_SecondAdjustmentRecord;
    int32_t m_FeatureLookupFlags;

    friend Serializer& operator<<(Serializer& s, const TMP_GlyphPairAdjustmentRecord& o)
    {
        s << o.m_FirstAdjustmentRecord;
        s << o.m_SecondAdjustmentRecord;
        s << o.m_FeatureLookupFlags;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, TMP_GlyphPairAdjustmentRecord& o)
    {
        d >> o.m_FirstAdjustmentRecord;
        d >> o.m_SecondAdjustmentRecord;
        d >> o.m_FeatureLookupFlags;
        return d;
    }
};

struct TMP_FontFeatureTable
{
    std::vector<TMP_GlyphPairAdjustmentRecord> m_GlyphPairAdjustmentRecords;

    friend Serializer& operator<<(Serializer& s, const TMP_FontFeatureTable& o)
    {
        s << o.m_GlyphPairAdjustmentRecords;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, TMP_FontFeatureTable& o)
    {
        d >> o.m_GlyphPairAdjustmentRecords;
        return d;
    }
};

struct FontAssetCreationSettings
{
    std::string sourceFontFileName;
    std::string sourceFontFileGUID;
    int32_t pointSizeSamplingMode;
    int32_t pointSize;
    int32_t padding;
    int32_t packingMode;
    int32_t atlasWidth;
    int32_t atlasHeight;
    int32_t characterSetSelectionMode;
    std::string characterSequence;
    std::string referencedFontAssetGUID;
    std::string referencedTextAssetGUID;
    int32_t fontStyle;
    float fontStyleModifier;
    int32_t renderMode;
    uint8_t includeFontFeatures;

    friend Serializer& operator<<(Serializer& s, const FontAssetCreationSettings& o)
    {
        s << o.sourceFontFileName;
        s << o.sourceFontFileGUID;
        s << o.pointSizeSamplingMode;
        s << o.pointSize;
        s << o.padding;
        s << o.packingMode;
        s << o.atlasWidth;
        s << o.atlasHeight;
        s << o.characterSetSelectionMode;
        s << o.characterSequence;
        s << o.referencedFontAssetGUID;
        s << o.referencedTextAssetGUID;
        s << o.fontStyle;
        s << o.fontStyleModifier;
        s << o.renderMode;
        s << o.includeFontFeatures;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, FontAssetCreationSettings& o)
    {
        d >> o.sourceFontFileName;
        d >> o.sourceFontFileGUID;
        d >> o.pointSizeSamplingMode;
        d >> o.pointSize;
        d >> o.padding;
        d >> o.packingMode;
        d >> o.atlasWidth;
        d >> o.atlasHeight;
        d >> o.characterSetSelectionMode;
        d >> o.characterSequence;
        d >> o.referencedFontAssetGUID;
        d >> o.referencedTextAssetGUID;
        d >> o.fontStyle;
        d >> o.fontStyleModifier;
        d >> o.renderMode;
        d >> o.includeFontFeatures;
        return d;
    }
};

struct TMP_FontWeightPair
{
    PPtrObject regularTypeface;
    PPtrObject italicTypeface;

    friend Serializer& operator<<(Serializer& s, const TMP_FontWeightPair& o)
    {
        s << o.regularTypeface;
        s << o.italicTypeface;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, TMP_FontWeightPair& o)
    {
        d >> o.regularTypeface;
        d >> o.italicTypeface;
        return d;
    }
};

struct TMP_FontAsset
{
    PPtrObject m_GameObject;
    uint8_t m_Enabled;
    PPtrObject m_Script;
    std::string m_Name;
    int32_t hashCode;
    PPtrObject material;
    int32_t meterialHashCode;
    std::string m_Version;
    std::string m_SourceFontFileGUID;
    PPtrObject m_SourceFontFile;
    int32_t mAtlasPopuatuionMode;
    FaceInfo m_FaceInfo;
    std::vector<Glyph> m_GlyphTable;
    std::vector<TMP_Character> m_CharacterTable;
    std::vector<PPtrObject> m_AtlasTextures;
    int32_t m_AtlasTextureIndex;
    std::vector<GlyphRect> m_UsedGlyphRects;
    std::vector<GlyphRect> m_FreeGlyphRects;
    FaceInfo_Legacy m_fontInfo;
    PPtrObject atlas;
    int32_t m_AtlasWidth;
    int32_t m_AtlasHeight;
    int32_t m_AtlasPadding;
    int32_t m_AtlasRenderMode;
    std::vector<TMP_Glyph> m_glyphInfoList;
    KerningTable m_KerningTable;
    TMP_FontFeatureTable m_FontFeatureTable;
    std::vector<PPtrObject> fallbackFontAssets;
    std::vector<TMP_FontAsset> m_FallbackFontAssetTable;
    FontAssetCreationSettings m_CreationSettings;
    std::vector<TMP_FontWeightPair> m_FontWeightTable;
    std::vector<TMP_FontWeightPair> fontWeights;
    float normalStyle;
    float normalSpacingOffset;
    float boldStyle;
    float boldSpacing;
    uint8_t italicStyle;
    uint8_t tabSize;

    friend Serializer& operator<<(Serializer& s, const TMP_FontAsset& o)
    {
        s << o.m_GameObject;
        s << o.m_Enabled;
        s << o.m_Script;
        s << o.m_Name;
        s << o.hashCode;
        s << o.material;
        s << o.meterialHashCode;
        s << o.m_Version;
        s << o.m_SourceFontFileGUID;
        s << o.m_SourceFontFile;
        s << o.mAtlasPopuatuionMode;
        s << o.m_FaceInfo;
        s << o.m_GlyphTable;
        s << o.m_CharacterTable;
        s << o.m_AtlasTextures;
        s << o.m_AtlasTextureIndex;
        s << o.m_UsedGlyphRects;
        s << o.m_FreeGlyphRects;
        s << o.m_fontInfo;
        s << o.atlas;
        s << o.m_AtlasWidth;
        s << o.m_AtlasHeight;
        s << o.m_AtlasPadding;
        s << o.m_AtlasRenderMode;
        s << o.m_glyphInfoList;
        s << o.m_KerningTable;
        s << o.m_FontFeatureTable;
        s << o.m_FallbackFontAssetTable;
        s << o.m_CreationSettings;
        s << o.m_FontWeightTable;
        s << o.fontWeights;
        s << o.normalStyle;
        s << o.normalSpacingOffset;
        s << o.boldStyle;
        s << o.boldSpacing;
        s << o.italicStyle;
        s << o.tabSize;
        return s;
    }

    friend Deserializer& operator>>(Deserializer& d, TMP_FontAsset& o)
    {
        d >> o.m_GameObject;
        d >> o.m_Enabled;
        d >> o.m_Script;
        d >> o.m_Name;
        d >> o.hashCode;
        d >> o.material;
        d >> o.meterialHashCode;
        d >> o.m_Version;
        d >> o.m_SourceFontFileGUID;
        d >> o.m_SourceFontFile;
        d >> o.mAtlasPopuatuionMode;
        d >> o.m_FaceInfo;
        d >> o.m_GlyphTable;
        d >> o.m_CharacterTable;
        d >> o.m_AtlasTextures;
        d >> o.m_AtlasTextureIndex;
        d >> o.m_UsedGlyphRects;
        d >> o.m_FreeGlyphRects;
        d >> o.m_fontInfo;
        d >> o.atlas;
        d >> o.m_AtlasWidth;
        d >> o.m_AtlasHeight;
        d >> o.m_AtlasPadding;
        d >> o.m_AtlasRenderMode;
        d >> o.m_glyphInfoList;
        d >> o.m_KerningTable;
        d >> o.m_FontFeatureTable;
        d >> o.m_FallbackFontAssetTable;
        d >> o.m_CreationSettings;
        d >> o.m_FontWeightTable;
        d >> o.fontWeights;
        d >> o.normalStyle;
        d >> o.normalSpacingOffset;
        d >> o.boldStyle;
        d >> o.boldSpacing;
        d >> o.italicStyle;
        d >> o.tabSize;
        return d;
    }
};
