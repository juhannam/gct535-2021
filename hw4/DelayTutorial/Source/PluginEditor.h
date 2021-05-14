/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

    XXX-XX-2017    Created by Soonbeom Choi, KAIST
    XXX-XX-2017    Modified by Juhan Nam, KAIST as starter code for GCT535 homework
    May-07-2021    Modified by Minsuk Choi, KAIST
    
  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "PluginGUI.h"


//==============================================================================
/**
*/
class MyDelayAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    MyDelayAudioProcessorEditor (MyDelayAudioProcessor&);
    ~MyDelayAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MyDelayAudioProcessor& processor;
    PluginGUI pluginGUI;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyDelayAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
