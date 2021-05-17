# Homework #4: Due May 23

### Instruction
The problem includes JUCE programming. You should use the JUCE framework for your own implementation of a plug-in.

Here are some *crucial* instruction to set up your JUCE environment. You have to set these up to build your project properly.
1. You will need the older version of VST2 SDK to build this project. Please download VST SDK 3.6.10 here: https://web.archive.org/web/20181016150224/https://download.steinberg.net/sdk_downloads/vstsdk3610_11_06_2018_build_37.zip and add VST\_SDK/VST2\_SDK as the global path of VST (Legacy) SDK on Projucer. You can find the global path setting at Projucer\>Global Paths... on upper menu bar.

2. You have to set the paths to JUCE modules in Global Paths setting. Please set the global paths to JUCE and JUCE Modules as your path that you installed JUCE.

3. You have to install Xcode (macOS) or Visual Studio (Windows) to build and compile the project. This project is tested on Xcode Version 12.4 (macOS) and Visual Studio 2019 (Windows 10).

4. If you're using Windows and Visual Studio 2019, you need to comment out some lines in the source code of Visual Studio to resolve error regarding to the copying files during the build. Lines can be found on 1480-1482, in 'Microsoft.CppCommon.targets', which can be found in C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Microsoft\VC\v160. If you can't find the lines or file, please check out the error message during the project build. 

Please check out the previous TA session material for more information.

### Deliverable 
You should submit following three items:
<ul>
<li>PluginProcessor.h</li>
<li>PluginProcessor.cpp</li>
<li>DelayTutorial.vst or DelayTutorial.component (macOS) | DelayTutorial.dll (Windows)</li>
</ul>

Result plug-in files can be found in following directories. If you can't find them, please check https://docs.juce.com/master/tutorial_app_plugin_packaging.html for more information.
<ul>
<li>~/Library/Audio/Plug-Ins/VST/DelayTutorial.vst (macOS)</li>
<li>~/Library/Audio/Plug-Ins/Components/DelayTutorial.component (macOS)</li>
<li>\(path to your Delay Tutorial Project)/Builds/MacOSX/build/Debug/DelayTutorial.vst (macOS)</li>
<li>\(path to your Delay Tutorial Project)/Builds/MacOSX/build/Debug/DelayTutorial.component (macOS)</li>
<li>C:\Program Files\VstPlugins\DelayTutorial.dll (Windows)</li>
<li>\(path to your Delay Tutorial Project)\Builds\VisualStudio2019\build\Debug\DelayTutorial.dll (Windows)</li>
</ul>

Please compress them as a single zip file named as '(student id)\_(name).zip' and submit it via KLMS. (e.g. 20210000\_JohnDoe.zip)

## Problem #1: Delay-based Audio Effects  (100 pts.)

1. In this homework, you are going to implement 3 delay-based effects: feedback delay, chorus, and flanger. You can refer to the lecture slide '07-2 Delay-based Effects' for this homework.

2. Check out the practice code '06. Delay-based Audio Effects.ipynb' at https://github.com/juhannam/gct535-2021/tree/main/practice to understand how feedback delay, chorus and flanger works. Replace the wav file to given 'guitar.wav' or your own sample, and run 'delay', 'chorus' and 'flanger' functions and check the results.

3. Open the JUCE project file 'DelayTutorial.jucer' and build it. The feedforward delay is already implemented as 'processBlockDelay' function in 'PluginProcessor.cpp'. Load the result plug-in on DAW and check it.

4. Implement a feedback delay based on 'delay' function in '06. Delay-based Audio Effects.ipynb' by modifying below part in 'PluginProcessor.cpp', but **with wet/dry coefficient** like the function of feedforward delay effect implemented in JUCE code. You can easily adding the feedback loop to the implemented feedforward delay. Don't forget to consider the feedback gain. *You don't have to consider the LFO parameters for feedback delay. Please ignore them.*

```
void MyDelayAudioProcessor::processBlockDelay(AudioSampleBuffer& buffer, int totalNumInputChannels)
```

5. Implement a chorus as 'chorus' function in '06. Delay-based Audio Effects.ipynb', **with wet/dry coefficient** by modifying below part in 'PluginProcessor.cpp'. 

```
void MyDelayAudioProcessor::processBlockChorus(AudioSampleBuffer& buffer, int totalNumInputChannels)
```

6. Implement a chorus as 'chorus' function in '06. Delay-based Audio Effects.ipynb', **with wet/dry coefficient**  by modifying below part in 'PluginProcessor.cpp'. 

```
void MyDelayAudioProcessor::processBlockFlanger(AudioSampleBuffer& buffer, int totalNumInputChannels)
```

7. Build your implementation and check out the result plug-in with DAW. Verify your results by comparing them with the results from '06. Delay-based Audio Effects.ipynb'.
