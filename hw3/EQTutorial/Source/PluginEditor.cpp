/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

    Apr-11-2017    Created by Soonbeom Choi, KAIST
    Apr-12-2017    Modified by Juhan Nam, KAIST as starter code for GCT535 homework
    Apr-22-2021    Modified by Minsuk Choi, KAIST

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
EqtutorialAudioProcessorEditor::EqtutorialAudioProcessorEditor (EqtutorialAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), pluginGUI(&p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(pluginGUI);
    setSize (400, 300);
}

EqtutorialAudioProcessorEditor::~EqtutorialAudioProcessorEditor()
{
}

//==============================================================================
void EqtutorialAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
}

void EqtutorialAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
