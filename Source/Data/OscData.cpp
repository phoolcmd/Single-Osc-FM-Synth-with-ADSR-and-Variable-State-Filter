
#include "OscData.h"

void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
   
    fmOsc.prepare(spec);
    gain.prepare(spec);
    prepare (spec);
  
 ;
}

void OscData::setWaveType (const int oscSelection)
{
    switch (oscSelection)
    {
        // Sine
        case 0:
            initialise ([](float x) { return std::sin (x); });
            break;
            
        // Saw
        case 1:
            initialise ([] (float x) { return x / juce::MathConstants<float>::pi; });
            break;
          
        // Square
        case 2:
            initialise ([] (float x) { return x < 0.0f ? -1.0f : 1.0f; });
            break;
            
        default:
            // You shouldn't be here!
            jassertfalse;
            break;
    }
}

void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber) + fmModulator);
    lastMidiNote = midiNoteNumber;
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    for (int ch = 0; ch < block.getNumChannels(); ++ch)
    {
        for (int s = 0; s < block.getNumSamples(); ++s)
        {
            fmModulator = fmOsc.processSample(block.getSample(ch, s)) * fmDepth;
        }
    }
    process(juce::dsp::ProcessContextReplacing<float>(block));
}

void OscData::updateFm(const float oscGain, const float freq, const float depth)
{
    fmOsc.setFrequency(freq);
    fmDepth = depth;
    gain.setGainDecibels(oscGain);
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(lastMidiNote) + fmModulator);


}