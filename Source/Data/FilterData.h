
#pragma once

#include "OscData.h"
#include <JuceHeader.h>


class FilterData 
{
public:
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);
    void updateParameters(const int filterType, const float filterCutoff, const float filterResonance, const float modulator = 1.0f);
    void setLfoParams (const float freq, const float depth);
    void process(juce::AudioBuffer<float>& buffer);
    float processNextSample (int channel, float inputValue);
    void reset();

private:
    juce::dsp::StateVariableTPTFilter<float> filter;
    OscData lfo;
};
