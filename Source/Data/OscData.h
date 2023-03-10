
#pragma once

#include <JuceHeader.h>

class OscData : public juce::dsp::Oscillator<float>
{
public:
    void prepareToPlay (juce::dsp::ProcessSpec& spec);
    void setWaveType(const int oscSelection);
    void setWaveFrequency(const int midiNoteNumber);
    void updateFm(const float oscGain, const float freq, const float depth);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& block);
private:
    juce::dsp::Oscillator<float> fmOsc { [](float x) { return std::sin (x); }};
    juce::dsp::Gain<float> gain;
    int lastMidiNote { 0 };
    float fmDepth { 0.0f };
    float fmModulator { 0.0f };
};

// return std::sin (x); //Sine Wave
// return x / MathConstants<float>::pi; // Saw Wave
// return x < 0.0f ? -1.0f : 1.0f;  // Square Wave
