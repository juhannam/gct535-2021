/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

    Apr-11-2017    Created by Soonbeom Choi, KAIST
    Apr-12-2017    Modified by Juhan Nam, KAIST as starter code for GCT535 homework
    Apr-22-2021    Modified by Minsuk Choi, KAIST

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class EqtutorialAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    EqtutorialAudioProcessor();
    ~EqtutorialAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void setParameters(double gain, int fc, float Q);
    int getSampleRate();
    
    int bufferSize;

    float getGain();
    float getCenterFrequency();
    float getQ(); // not used for now


private:
    //==============================================================================
    
    // input parameters
    float _gain, _Q, _fc, _fs;

    // delay elements
    float _z_ff1[2], _z_fb1[2];
    
    // filter coefficients
    float _b0, _b1, _a0, _a1;
    
    // mapping user parameters to filter coefficients
    void updateCoefficients();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EqtutorialAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
