
#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void setParams (const float attack, const float decay, const float sustain, const float release);
    
private:
    juce::ADSR::Parameters adsrParams;
};
