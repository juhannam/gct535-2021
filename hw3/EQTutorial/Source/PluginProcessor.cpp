/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.
 
    Apr-11-2017    Created by Soonbeom Choi, KAIST
    Apr-12-2017    Modified by Juhan Nam, KAIST as starter code for GCT535 homework
    Apr-22-2021    Modified by Minsuk Choi, KAIST
 
  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
EqtutorialAudioProcessor::EqtutorialAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
    // initialize member variables
    _gain(1.0f),
    _Q(1.0f),
    _fc(1000.0f),
    _fs(44100.0f),
    _z_ff1{0.0f,0.0f},
    _z_fb1{0.0f,0.0f}
{
    // update filter coefficients
    updateCoefficients();
}

EqtutorialAudioProcessor::~EqtutorialAudioProcessor()
{
}

//==============================================================================
const String EqtutorialAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool EqtutorialAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool EqtutorialAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double EqtutorialAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int EqtutorialAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int EqtutorialAudioProcessor::getCurrentProgram()
{
    return 0;
}

void EqtutorialAudioProcessor::setCurrentProgram (int index)
{
}

const String EqtutorialAudioProcessor::getProgramName (int index)
{
    return String();
}

void EqtutorialAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void EqtutorialAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    _fs = sampleRate;
}

void EqtutorialAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool EqtutorialAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void EqtutorialAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; i++)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    bufferSize = buffer.getNumSamples();
    
    for (int ch = 0; ch < totalNumInputChannels; ch++)
    {
        const float* inBuffer = buffer.getReadPointer (ch);
        float* outBuffer = buffer.getWritePointer (ch);
        
        //
        // **** Note that inBuffer and outBuffer point to the same buffer. This is very very important !!! ****
        //
        for (int n = 0; n < buffer.getNumSamples(); n++)
        {
            //
            // One-Pole One-Zero Filter Difference Equation
            //
            // Instead of writing the output directly to outBuffer, use a temporary variable.
            // Otherwise, you override the outBuffer to inBuffer at the time index
            float output = (_b0*inBuffer[n] + _b1*_z_ff1[ch] - _a1*_z_fb1[ch] )/_a0;
            _z_fb1[ch] = output;
            _z_ff1[ch] = inBuffer[n];
            outBuffer[n] = output;
        }
    }
}

//==============================================================================
bool EqtutorialAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* EqtutorialAudioProcessor::createEditor()
{
    return new EqtutorialAudioProcessorEditor (*this);
}

//==============================================================================
void EqtutorialAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void EqtutorialAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new EqtutorialAudioProcessor();
}
 
void EqtutorialAudioProcessor::setParameters(double gain, int fc, float Q)
{
    _gain = gain;
    _fc = fc;
    _Q = Q;

    updateCoefficients();
}

int EqtutorialAudioProcessor::getSampleRate()
{
    return _fs;
}


float EqtutorialAudioProcessor::getGain()
{
    return _gain;
}

float EqtutorialAudioProcessor::getCenterFrequency()
{
    return _fc;
}

// not used for now
float EqtutorialAudioProcessor::getQ()
{
    return _Q;
}


void EqtutorialAudioProcessor::updateCoefficients()
{
    //
    // One-Pole One-Zero Bass Shelving Filter
    //
    // Mapping user parameters to filter coefficients
    //
    
    float gain = pow(10.0f, _gain/20.0f);  // dB to linear
    float theta = 2.0f*double_Pi*_fc/_fs;
    float gain_rt = sqrt(gain);

    _b0 = gain*tan(theta*0.5f) + gain_rt;
    _b1 = gain*tan(theta*0.5f) - gain_rt;
    
    _a0 = tan(theta*0.5f) + gain_rt;
    _a1 = tan(theta*0.5f) - gain_rt;
}

