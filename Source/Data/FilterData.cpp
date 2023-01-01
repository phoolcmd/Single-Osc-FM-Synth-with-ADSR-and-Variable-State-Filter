
#include "FilterData.h"

void FilterData::setParams (const int filterType, const float filterCutoff, const float filterResonance, const float modulator)
{
    selectFilterType (filterType);
    float modFreq = filterCutoff * modulator;
    //return 20hz if frequency falls below 20hz - return 20,000hz if frequency goes above 20,000hz
    modFreq = std::fmin(std::fmax(modFreq, 20.0f), 20000.0f);
    filter.setCutoffFrequency (modFreq);
    filter.setResonance (filterResonance);
    

}

void FilterData::setLfoParams (const float freq, const float depth)
{
    //lfo.setGain (juce::Decibels::gainToDecibels (depth));
    lfo.setFrequency (freq);
}

void FilterData::prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels)
{
    filter.reset();

    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    
    filter.prepare (spec);
    lfo.prepareToPlay (sampleRate, samplesPerBlock, outputChannels);
}


void FilterData::selectFilterType (const int filterType)
{    
    switch (filterType)
    {
        case 0:
            setType (juce::dsp::StateVariableTPTFilterType::lowpass);
            break;
            
        case 1:
            setType (juce::dsp::StateVariableTPTFilterType::bandpass);
            break;
            
        case 2:
            setType (juce::dsp::StateVariableTPTFilterType::highpass);
            break;
            
        default:
            setType (juce::dsp::StateVariableTPTFilterType::lowpass);
            break;
    }
}

void FilterData::process(juce::AudioBuffer<float>& buffer)
{
    juce::dsp::AudioBlock<float> block { buffer };
    filter.process (juce::dsp::ProcessContextReplacing<float>(block));
}

float FilterData::processNextSample (int channel, float inputValue)
{
    return processSample (channel, inputValue);
}
void FilterData::reset()
{
    filter.reset();
}
