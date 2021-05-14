/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.
    
    XXX-XX-2017    Created by Soonbeom Choi, KAIST
    XXX-XX-2017    Modified by Juhan Nam, KAIST as starter code for GCT535 homework
    May-07-2021    Modified by Minsuk Choi, KAIST

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
MyDelayAudioProcessor::MyDelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif

{
    
    _feedbackGain = 0.0f;
    _delayTime = 0.0f;
    _wetDry = 0.0f;
    _fs = 44100.0f;
    _lfo_rate = 0.1f;
    _lfo_depth = 0.002f;
    _lfo_phase_inc = 0.0f;
    _effect_type = DELAY;
    _delayTimeLFO = 0.0f;

    for (int ch=0; ch < 2 ; ch++) {
        
        _writePointer[ch] = 0;
        _delayTimeSamples[ch] = 0.0f;
        _lfo_phase[ch] = 0.0f;
        
        for (int n=0; n < MAX_DELAY; n++) {
            _delayline[ch][n] = 0.0f;
        }
        
    }
}

MyDelayAudioProcessor::~MyDelayAudioProcessor()
{
}

//==============================================================================
const String MyDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MyDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MyDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double MyDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MyDelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MyDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MyDelayAudioProcessor::setCurrentProgram (int index)
{
}

const String MyDelayAudioProcessor::getProgramName (int index)
{
    return String();
}

void MyDelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MyDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    _fs = sampleRate;
    
    
    // clean up delayline
    for (int ch=0; ch < 2 ; ch++) {
        //_writePointer[ch] = 0;
        //_delayTimeSamples[ch] = 0.0f;
        //_lfo_phase[ch] = 0.0f;
        
        for (int n=0; n < MAX_DELAY; n++) {
            _delayline[ch][n] = 0.0f;
        }
    }
}

void MyDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MyDelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MyDelayAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
    
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    switch ( _effect_type ) {
        case DELAY:
            processBlockDelay(buffer, totalNumInputChannels);
            break;
        case CHORUS:
            processBlockChorus(buffer, totalNumInputChannels);
            break;
        case FLANGER:
            processBlockFlanger(buffer, totalNumInputChannels);
            break;
    }
}

void MyDelayAudioProcessor::processBlockDelay(AudioSampleBuffer& buffer, int totalNumInputChannels)
{
    for (int ch = 0; ch < totalNumInputChannels; ++ch)
    {
        const float* inBuffer = buffer.getReadPointer (ch);
        float* outBuffer = buffer.getWritePointer (ch);
        
        // MODIFY THIS FEEDFORWARD DELAY WITH YOUR OWN CODE WITH FEEDBACK COMPONENT 
        for (int n = 0; n < buffer.getNumSamples(); n++)
        {
            float outputPointer= (float)_writePointer[ch] - _delayTimeSamples[ch];
            if (outputPointer < 0.0) {
                outputPointer = outputPointer + (float)MAX_DELAY;
            }
            int readPointer = (int)outputPointer;
            float readPointerFrac  = outputPointer - (float)readPointer;
            
            if ( readPointer >= MAX_DELAY ) {
                readPointer = readPointer - MAX_DELAY;
            }
            
            float tap_out = 0.0f;
            float input = inBuffer[n];
            
            if (readPointer == (MAX_DELAY-1)) {
                tap_out = (1.0f - readPointerFrac)*_delayline[ch][MAX_DELAY-1] + readPointerFrac*_delayline[ch][0];
            }
            else {
                tap_out = (1.0f - readPointerFrac)*_delayline[ch][readPointer] + readPointerFrac*_delayline[ch][readPointer+1];
            }
            
            _delayline[ch][_writePointer[ch]] = input;
            
            // update write pointer
            _writePointer[ch] = _writePointer[ch] + 1;
            if (_writePointer[ch] >= MAX_DELAY ) {
                _writePointer[ch] = _writePointer[ch] - MAX_DELAY;
            }
            outBuffer[n] = _wetDry*tap_out + (1.0f -_wetDry)*input;
        }
    }
}

void MyDelayAudioProcessor::processBlockChorus(AudioSampleBuffer& buffer, int totalNumInputChannels)
{
    for (int ch = 0; ch < totalNumInputChannels; ++ch)
    {
        
        const float* inBuffer = buffer.getReadPointer (ch);
        float* outBuffer = buffer.getWritePointer (ch);
        
        for (int n = 0; n < buffer.getNumSamples(); n++)
        {
            // REPLACE THIS WITH YOUR OWN CODE
            outBuffer[n] = inBuffer[n];
        }
    }
}
    

void MyDelayAudioProcessor::processBlockFlanger(AudioSampleBuffer& buffer, int totalNumInputChannels)
{
    for (int ch = 0; ch < totalNumInputChannels; ++ch)
    {
        
        const float* inBuffer = buffer.getReadPointer (ch);
        float* outBuffer = buffer.getWritePointer (ch);
        
        for (int n = 0; n < buffer.getNumSamples(); n++)
        {
            // REPLACE THIS WITH YOUR OWN CODE
            outBuffer[n] = inBuffer[n];
        }
    }
}


//==============================================================================
bool MyDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MyDelayAudioProcessor::createEditor()
{
    return new MyDelayAudioProcessorEditor (*this);
}

//==============================================================================
void MyDelayAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MyDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}



void MyDelayAudioProcessor::updateCoefficients()
{
    _delayTimeSamples[0] = _fs* _delayTime;
    _delayTimeSamples[1] = _fs* _delayTime;
}

void MyDelayAudioProcessor::setParameters(float delayTime, float FeedbackGain, float wetDry, float LFORate, float LFODepth)
{
    _delayTime = delayTime;
    _feedbackGain = FeedbackGain;
    _wetDry = wetDry/100.0f; // 100% -> 1.0 scale

    
    _lfo_rate = LFORate;
    _lfo_depth = LFODepth;
    _delayTimeLFO = _delayTime + 0.0025f;
    
    _lfo_phase_inc = 2.0f*PI*_lfo_rate/_fs;

    updateCoefficients();

    printf("%f, %f, %f, %f, %f \n", _wetDry, _delayTime, _feedbackGain, _lfo_rate, _lfo_depth );
}

void MyDelayAudioProcessor::loadDefaultPreset()
{
    switch ( _effect_type ) {
        case DELAY:
            _delayTime = 0.3f;
            _feedbackGain = 0.7;
            _wetDry = 0.5f;
            break;
        case CHORUS:
            _delayTime = 0.03f;
            _lfo_rate = 1.5f;
            _lfo_depth = 0.001f;
            _wetDry = 1.0f;
            break;
        case FLANGER:
            _delayTime = 0.02f;
            _delayTimeLFO = 0.0225f;
            _lfo_rate = 0.3f;
            _lfo_depth = 0.002f;
            _wetDry = 1.0f;
            break;
    }
    
}

float MyDelayAudioProcessor::getDelayTime()
{
    return _delayTime;
}

float MyDelayAudioProcessor::getWetDry()
{
    return _wetDry*100.0;
}


float MyDelayAudioProcessor::getFeedbackGain()
{
    return _feedbackGain;
}

float MyDelayAudioProcessor::getLFORate()
{
    return _lfo_rate;
}

float MyDelayAudioProcessor::getLFODepth()
{
    return _lfo_depth;
}

void MyDelayAudioProcessor::selectEffectType(EffectType type)
{
    _effect_type = type;
    
    loadDefaultPreset();
    
    printf("%f, %f, %f, %f, %f \n",_delayTime, _feedbackGain, _wetDry, _lfo_rate, _lfo_depth );
}


//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MyDelayAudioProcessor();
}



