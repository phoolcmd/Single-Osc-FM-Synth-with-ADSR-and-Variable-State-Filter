#pragma once
#include <JuceHeader.h>
class MyLookAndFeel : public juce::LookAndFeel_V4
{
public:
    juce::Font getComboBoxFont(juce::ComboBox& box) override
    {
        return myCustomFont;
    }


    juce::Font getLabelFont(juce::Label& label) override
    {
        return myCustomFont;
    }

private:
    juce::Font myCustomFont{ juce::Typeface::createSystemTypefaceFor(BinaryData::my_font_ttf, BinaryData::my_font_ttfSize) };
};