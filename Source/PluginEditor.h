/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/OscComponent.h"
#include "UI/FilterComponent.h"
#include "UI/AdsrComponent.h"

//==============================================================================
/**
*/
class BasicSynthAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    BasicSynthAudioProcessorEditor(BasicSynthAudioProcessor&);
    ~BasicSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    BasicSynthAudioProcessor& audioProcessor;
    OscComponent osc1;
    AdsrComponent adsr;
    FilterComponent filter;
    AdsrComponent modAdsr;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicSynthAudioProcessorEditor)
};
