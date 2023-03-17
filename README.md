# FM Synthesizer with ADSR and Variable State Filter
This is a basic synthesizer built using the JUCE API. It features a single oscillator FM synth with ADSR envelope, variable state filter, and modulation envelope. This synthesizer is suitable for producing a wide range of sounds, from classic bell-like FM timbres to more complex, evolving textures.

![image](https://user-images.githubusercontent.com/121768237/226000177-d5ceb799-3b00-4b47-807a-7840c3a5fc44.png)

# Building from Source
To build this synthesizer from source, you'll need to follow these steps:

1. Download and install the Projucer IDE from the [JUCE Website](https://juce.com/download/).
2. Set up your development environment by installing XCode on Mac or Visual Studio on Windows.
3. Open the **'Simpletron Synth.jucer'** file in Projucer.
4. Export the project to your desired build format (XCode or Visual Studio) and build the project.
# Overview
The FM Synthesizer with ADSR and Variable State Filter is a single oscillator synthesizer built using the JUCE API. It features the following components:

- A single oscillator with adjustable frequency and depth controls.
- An ADSR envelope with adjustable attack, decay, sustain, and release times.
- A variable state filter with adjustable cutoff frequency and resonance controls.
- A modulation envelope with adjustable attack, decay, sustain, and release times.

# Programming Concepts
During the development of this synthesizer, several key programming concepts were learned and implemented. These include:

- **Object-oriented programming:** The FM Synthesizer was designed with an object-oriented approach, which allowed for easy management of complex functionality, such as the modulation algorithm and envelope generation.
- **Signal processing:** The synthesis of the audio signal involves manipulating digital signals in real time. Signal processing techniques, such as filtering, modulation, and envelope shaping, were used to achieve the desired sound.
- **Event-driven programming:** The user interface of the FM Synthesizer is event-driven, meaning that it responds to user actions, such as clicking on a button or adjusting a knob. Event-driven programming was used to create an intuitive and interactive user experience.
- **API integration:** The FM Synthesizer was built using the JUCE API, which provided a comprehensive set of libraries and tools for audio plugin development. The integration of the JUCE API allowed for efficient and reliable implementation of key features, such as the filter and envelope algorithms.
