
#pragma once

#include "OscData.h"
#include <JuceHeader.h>


class FilterData : public juce::dsp::StateVariableTPTFilter<float>
{
public:
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);
    void setParams (const int filterType, const float filterCutoff, const float filterResonance, const float modulator);
    void setLfoParams (const float freq, const float depth);
    void process(juce::AudioBuffer<float>& buffer);
    float processNextSample (int channel, float inputValue);
    void reset();
private:
    void selectFilterType (const int type);
    juce::dsp::StateVariableTPTFilter<float> filter;
    OscData lfo;
};
