#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AdsrComponent : public juce::Component
{
public:
    AdsrComponent (juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId);
    ~AdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    void setSliderParams (juce::Slider& slider, juce::Label& label, std::unique_ptr<SliderAttachment>& attachment, juce::String paramId, juce::AudioProcessorValueTreeState& apvts);
    
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;
    
    juce::Label attackLabel { "Attack", "A" };
    juce::Label decayLabel { "Decay", "D" };
    juce::Label sustainLabel { "Sustain", "S" };
    juce::Label releaseLabel { "Release", "R" };

    juce::String componentName{ "" };
        
    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> decayAttachment;
    std::unique_ptr<SliderAttachment> sustainAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;
    
    static constexpr float fontHeight { 20.0f };
    static constexpr int textBoxWidth { 35 };
    static constexpr int textBoxHeight { 20 };
    juce::Font myCustomFont = juce::Typeface::createSystemTypefaceFor(BinaryData::my_font_ttf, BinaryData::my_font_ttfSize);

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};
