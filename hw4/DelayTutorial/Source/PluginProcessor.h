/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

    XXX-XX-2017    Created by Soonbeom Choi, KAIST
    XXX-XX-2017    Modified by Juhan Nam, KAIST as starter code for GCT535 homework
    May-07-2021    Modified by Minsuk Choi, KAIST
    
  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#define MAX_DELAY 5*44100
#define PI        3.14159265358979323846264338327950288

//==============================================================================
/**
*/
class MyDelayAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    MyDelayAudioProcessor();
    ~MyDelayAudioProcessor();

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
    
    void setParameters(float delayTime, float FeedbackGain, float wetDry, float LFORate, float LFODepth);

    float getDelayTime();
    float getWetDry();
    float getFeedbackGain();
    float getLFORate();
    float getLFODepth();
    
    void processBlockDelay(AudioSampleBuffer& buffer, int totalNumInputChannels);
    void processBlockChorus(AudioSampleBuffer& buffer, int totalNumInputChannels);
    void processBlockFlanger(AudioSampleBuffer& buffer, int totalNumInputChannels);
    
    void loadDefaultPreset();
    
    enum EffectType
    {
        DELAY,
        CHORUS,
        FLANGER
    };

    void selectEffectType(EffectType type);
    
private:
    // user parameters
    float _feedbackGain;        // 0.0 ~ 1.0
    float _delayTime;           // 0.0 ~ 2.0 (seconds)
    float _wetDry;              // 0.0 ~ 1.0 
    float _lfo_rate;            // 0.0 ~ 10 Hz
    float _lfo_depth;           // 0.0 ~ 0.01
    
    // LFO
    float _lfo_phase[2];
    float _lfo_phase_inc;
    float _delayTimeLFO;
    
    // max delay
    float _delayline[2][MAX_DELAY];
    
    // internal parameter
    float _fs;                  // sampling rate
    int _writePointer[2];
    float _delayTimeSamples[2];    // delayTime in samples
    
    // delay, chorus and flanger
    EffectType _effect_type;

    void updateCoefficients();

    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyDelayAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
