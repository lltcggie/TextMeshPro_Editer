#pragma once

#include "TMP_before_1_0_26.h"

// 置換用正規表現メモ
// ^.+\s
// s << o.

// TMP 1.0.26

namespace TMP_1_0_26
{
    struct FaceInfo
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

        friend Serializer& operator<<(Serializer& s, const FaceInfo& o)
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

        friend Deserializer& operator>>(Deserializer& d, FaceInfo& o)
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

    struct KerningPair
    {
        uint32_t m_FirstGlyph;
        TMP_GlyphValueRecord m_FirstGlyphAdjustments;
        uint32_t m_SecondGlyph;
        TMP_GlyphValueRecord m_SecondGlyphAdjustments;
        float xOffset;

        friend Serializer& operator<<(Serializer& s, const KerningPair& o)
        {
            s << o.m_FirstGlyph;
            s << o.m_FirstGlyphAdjustments;
            s << o.m_SecondGlyph;
            s << o.m_SecondGlyphAdjustments;
            s << o.xOffset;
            return s;
        }

        friend Deserializer& operator>>(Deserializer& d, KerningPair& o)
        {
            d >> o.m_FirstGlyph;
            d >> o.m_FirstGlyphAdjustments;
            d >> o.m_SecondGlyph;
            d >> o.m_SecondGlyphAdjustments;
            d >> o.xOffset;
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

    struct TMP_FontAsset
    {
        TMP_before_1_0_26::PPtrObject m_GameObject;
        uint8_t m_Enabled;
        TMP_before_1_0_26::PPtrObject m_Script;
        std::string m_Name;
        int32_t hashCode;
        TMP_before_1_0_26::PPtrObject material;
        int32_t meterialHashCode;
        int32_t fontAssetType;
        FaceInfo m_fontInfo;
        TMP_before_1_0_26::PPtrObject atlas;
        std::vector<TMP_before_1_0_26::TMP_Glyph> m_glyphInfoList;
        KerningTable m_kerningInfo;
        KerningPair m_kerningPair;
        std::vector<TMP_before_1_0_26::PPtrObject> fallbackFontAssets;
        TMP_before_1_0_26::FontCreationSettings fontCreationSettings;
        std::vector<TMP_before_1_0_26::TMP_FontWeightPair> fontWeights;
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
            s << o.fontAssetType;
            s << o.m_fontInfo;
            s << o.atlas;
            s << o.m_glyphInfoList;
            s << o.m_kerningInfo;
            s << o.m_kerningPair;
            s << o.fallbackFontAssets;
            s << o.fontCreationSettings;
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
            d >> o.fontAssetType;
            d >> o.m_fontInfo;
            d >> o.atlas;
            d >> o.m_glyphInfoList;
            d >> o.m_kerningInfo;
            d >> o.m_kerningPair;
            d >> o.fallbackFontAssets;
            d >> o.fontCreationSettings;
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
}
