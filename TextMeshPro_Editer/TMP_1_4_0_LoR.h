#pragma once

#include "TMP_1_4_0.h"

// TMP 1.4.0 Library Of Ruina


struct TMP_FontAsset_LoR
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
    std::vector<PPtrObject> fallbackFontAssets; // Ç±ÇÍÇ™ëùÇ¶ÇƒÇ¢ÇÈ
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

    friend Serializer& operator<<(Serializer& s, const TMP_FontAsset_LoR& o)
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
        s << o.fallbackFontAssets;
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

    friend Deserializer& operator>>(Deserializer& d, TMP_FontAsset_LoR& o)
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
        d >> o.fallbackFontAssets;
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
