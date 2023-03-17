/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <JuceHeader.h>
#include <juce_graphics/juce_graphics.h>

//==============================================================================
BasicSynthAudioProcessorEditor::BasicSynthAudioProcessorEditor(BasicSynthAudioProcessor& p)
: AudioProcessorEditor (&p)
, audioProcessor (p)
, osc1 (audioProcessor.apvts, "OSC1", "OSC1GAIN", "OSC1FMFREQ", "OSC1FMDEPTH")
, adsr ("Amp Envelope", audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE")
, filter(audioProcessor.apvts, "FILTERTYPE", "FILTERCUTOFF", "FILTERRESONANCE")
, modAdsr("Mod Envelope", audioProcessor.apvts, "MODATTACK", "MODDECAY","MODSUSTAIN", "MODRELEASE")
{
    setSize(700, 275);

    addAndMakeVisible (osc1);
    addAndMakeVisible (filter);
    addAndMakeVisible (adsr);
    addAndMakeVisible(modAdsr);
    
    osc1.setName ("Oscillator");
    filter.setName ("Filter");

}

BasicSynthAudioProcessorEditor::~BasicSynthAudioProcessorEditor()
{
}

//==============================================================================
void BasicSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void BasicSynthAudioProcessorEditor::resized()
{
    const auto oscWidth = 350;
    const auto oscHeight = 120;
    osc1.setBounds (0, 0, oscWidth, oscHeight);
    adsr.setBounds (0, osc1.getBottom(), 350, 150);
    filter.setBounds(osc1.getRight(), 0, 350, 120);
    modAdsr.setBounds(adsr.getRight(), filter.getBottom(), 350, 150);
}


