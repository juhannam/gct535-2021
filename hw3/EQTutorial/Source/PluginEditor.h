/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

    Apr-11-2017    Created by Soonbeom Choi, KAIST
    Apr-12-2017    Modified by Juhan Nam, KAIST as starter code for GCT535 homework
    Apr-22-2021    Modified by Minsuk Choi, KAIST

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
class EqtutorialAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    EqtutorialAudioProcessorEditor (EqtutorialAudioProcessor&);
    ~EqtutorialAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    EqtutorialAudioProcessor& processor;
    PluginGUI pluginGUI;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EqtutorialAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
