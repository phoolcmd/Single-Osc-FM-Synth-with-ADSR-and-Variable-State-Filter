/*
  ==============================================================================

    OscComponent.cpp
    Created: 14 Feb 2021 6:51:39pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent (juce::AudioProcessorValueTreeState& apvts, juce::String oscId, juce::String gainId, juce::String fmFreqId, juce::String fmDepthId)
{
    juce::StringArray oscChoices { "Sine", "Saw", "Square" };
    oscSelector.addItemList (oscChoices, 1);
    oscSelector.setSelectedItemIndex (0);
    oscSelector.setColour(juce::ComboBox::backgroundColourId, juce::Colours::black);
    oscSelector.setColour(juce::ComboBox::textColourId, juce::Colours::green);


    addAndMakeVisible (oscSelector);
    
    oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, oscId, oscSelector);
    
    setSliderParams (gainSlider, gainLabel, gainAttachment, gainId, apvts);
    setSliderParams (fmFreqSlider, fmFreqLabel, fmFreqAttachment, fmFreqId, apvts);
    setSliderParams (fmDepthSlider, fmDepthLabel, fmDepthAttachment, fmDepthId, apvts);
}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    auto bounds = getLocalBounds();
    g.setColour (juce::Colours::green);
    g.drawRoundedRectangle (bounds.toFloat().reduced (10.0f), 5.0f, 2.0f);
    
    g.setColour (juce::Colours::green);
    g.setFont (fontHeight);
    g.setFont (g.getCurrentFont().boldened());
    g.drawText("Oscillator", 20, 15, 100, 25, juce::Justification::left);
}

void OscComponent::resized()
{
    const auto dialSize = 70;
    const auto labelWidth = 70;
    const auto labelHeight = 18;
    
    oscSelector.setBounds (18, 40, 100, 25);
    
    gainLabel.setBounds (120, 15, labelWidth, labelHeight);
    gainSlider.setBounds (120, 30, dialSize, dialSize);
    
    
    fmFreqLabel.setBounds (190, 15, labelWidth, labelHeight);
    fmFreqSlider.setBounds (190, 30, dialSize, dialSize);
    
    fmDepthLabel.setBounds (260, 15, labelWidth, labelHeight);
    fmDepthSlider.setBounds (260, 30, dialSize, dialSize);
}

using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

void OscComponent::setSliderParams (juce::Slider& slider, juce::Label& label, std::unique_ptr<sliderAttachment>& attachment, juce::String paramId, juce::AudioProcessorValueTreeState& apvts)
{
    slider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::white);
    slider.setColour(juce::Slider::thumbColourId, juce::Colours::green);


    slider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, textBoxWidth, textBoxHeight);
    slider.setTextBoxIsEditable(true);
    addAndMakeVisible (slider);
    label.setFont (fontHeight);
    label.setColour(juce::Label::textColourId, juce::Colours::green);
    label.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (label);
    
    attachment = std::make_unique<SliderAttachment>(apvts, paramId, slider);
}
