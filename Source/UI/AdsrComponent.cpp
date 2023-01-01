/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 7 Feb 2021 2:28:49pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent (juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId)
{
    componentName = name;
    setSliderParams (attackSlider, attackLabel, attackAttachment, attackId, apvts);
    setSliderParams (decaySlider, decayLabel, decayAttachment, decayId, apvts);
    setSliderParams (sustainSlider, sustainLabel, sustainAttachment, sustainId, apvts);
    setSliderParams (releaseSlider, releaseLabel, releaseAttachment, releaseId, apvts);
}

AdsrComponent::~AdsrComponent()
{
}

void AdsrComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    auto bounds = getLocalBounds();
    g.setColour (juce::Colours::green);
    g.drawRoundedRectangle (bounds.toFloat().reduced (10.0f), 5.0f, 2.0f);
    
    g.setColour (juce::Colours::green);
    g.setFont (fontHeight);
    g.setFont (g.getCurrentFont().boldened());
    g.drawText (componentName, 20, 15, 100, 25, juce::Justification::left);
}

void AdsrComponent::resized()
{
    const auto bounds = getLocalBounds().reduced (10);
    const auto padding = 5;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight() - 70;
    const auto sliderSize = 70;
    const auto sliderStartX = 15;
    const auto sliderStartY = 60;
    const auto labelStartY = 45;
    const auto labelWidth = 70;
    const auto labelHeight = 18;
    const auto labelOffset = 10;
    
    attackLabel.setBounds (sliderStartX - labelOffset, labelStartY, labelWidth, labelHeight);
    attackSlider.setBounds (sliderStartX, sliderStartY, sliderSize, sliderSize);
    
    decayLabel.setBounds (attackSlider.getRight() + padding - labelOffset, labelStartY, labelWidth, labelHeight);
    decaySlider.setBounds (attackSlider.getRight() + padding, sliderStartY, sliderSize, sliderSize);
    
    sustainLabel.setBounds (decaySlider.getRight() + padding - labelOffset, labelStartY, labelWidth, labelHeight);
    sustainSlider.setBounds (decaySlider.getRight() + padding, sliderStartY, sliderSize, sliderSize);
    
    releaseLabel.setBounds (sustainSlider.getRight() + padding - labelOffset, labelStartY, labelWidth, labelHeight);
    releaseSlider.setBounds (sustainSlider.getRight() + padding, sliderStartY, sliderSize, sliderSize);
}

using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

void AdsrComponent::setSliderParams (juce::Slider& slider, juce::Label& label, std::unique_ptr<SliderAttachment>& attachment, juce::String paramId, juce::AudioProcessorValueTreeState& apvts)
{
    slider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::white);
    slider.setColour(juce::Slider::thumbColourId, juce::Colours::green);

    slider.setTextBoxIsEditable(true);
    slider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, textBoxWidth, textBoxHeight);
    addAndMakeVisible (slider);
    
    label.setFont (fontHeight);
    label.setColour(juce::Label::textColourId, juce::Colours::green);
    label.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (label);
    
    attachment = std::make_unique<SliderAttachment>(apvts,  paramId,  slider);
}
