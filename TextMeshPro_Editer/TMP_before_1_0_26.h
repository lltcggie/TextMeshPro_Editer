#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>
#include "Serializer_Deserializer.h"

// 置換用正規表現メモ
// ^.+\s
// s << o.

// TMP 1.0.26以前(Stranded Deepで使われているバージョン)

namespace TMP_before_1_0_26
{
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
        uint32_t AscII_Left;
        uint32_t AscII_Right;
        float xOffset;

        friend Serializer& operator<<(Serializer& s, const KerningPair& o)
        {
            s << o.AscII_Left;
            s << o.AscII_Right;
            s << o.xOffset;
            return s;
        }

        friend Deserializer& operator>>(Deserializer& d, KerningPair& o)
        {
            d >> o.AscII_Left;
            d >> o.AscII_Right;
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

    struct FontCreationSettings
    {
        std::string fontSourcePath;
        int32_t fontSizingMode;
        int32_t fontSize;
        int32_t fontPadding;
        int32_t fontPackingMode;
        int32_t fontAtlasWidth;
        int32_t fontAtlasHeight;
        int32_t fontCharacterSet;
        int32_t fontStyle;
        float fontStyleModifier;
        int32_t fontRenderMode;
        int8_t fontKerning;

        friend Serializer& operator<<(Serializer& s, const FontCreationSettings& o)
        {
            s << o.fontSourcePath;
            s << o.fontSizingMode;
            s << o.fontSize;
            s << o.fontPadding;
            s << o.fontPackingMode;
            s << o.fontAtlasWidth;
            s << o.fontAtlasHeight;
            s << o.fontCharacterSet;
            s << o.fontStyle;
            s << o.fontStyleModifier;
            s << o.fontRenderMode;
            s << o.fontKerning;
            return s;
        }

        friend Deserializer& operator>>(Deserializer& d, FontCreationSettings& o)
        {
            d >> o.fontSourcePath;
            d >> o.fontSizingMode;
            d >> o.fontSize;
            d >> o.fontPadding;
            d >> o.fontPackingMode;
            d >> o.fontAtlasWidth;
            d >> o.fontAtlasHeight;
            d >> o.fontCharacterSet;
            d >> o.fontStyle;
            d >> o.fontStyleModifier;
            d >> o.fontRenderMode;
            d >> o.fontKerning;
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
        int32_t fontAssetType;
        FaceInfo m_fontInfo;
        PPtrObject atlas;
        std::vector<TMP_Glyph> m_glyphInfoList;
        KerningTable m_kerningInfo;
        KerningPair m_kerningPair;
        std::vector<PPtrObject> fallbackFontAssets;
        FontCreationSettings fontCreationSettings;
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
