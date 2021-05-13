# Homework #3: Due May 9

### Instruction
The problem includes JUCE programming. You should use the JUCE framework for your own implementation of a plug-in.

Here are some *crucial* instruction to set up your JUCE environment. You have to set these up to build your EQTutorial project properly.
1. You will need the older version of VST2 SDK to build this project. Please download VST SDK 3.6.10 here: https://web.archive.org/web/20181016150224/https://download.steinberg.net/sdk_downloads/vstsdk3610_11_06_2018_build_37.zip and add VST\_SDK/VST2\_SDK as the global path of VST (Legacy) SDK on Projucer. You can find the global path setting at Projucer\>Global Paths... on upper menu bar.

2. You have to set the paths to JUCE modules in Global Paths setting. Please set the global paths to JUCE and JUCE Modules as your path that you installed JUCE.

3. You have to install Xcode (macOS) or Visual Studio (Windows) to build and compile the project. This project is tested on Xcode Version 12.4 (macOS) and Visual Studio 2019 (Windows 10).

4. If you're using Windows and Visual Studio 2019, you need to comment out some lines in the source code of Visual Studio to resolve error regarding to the copying files during the build. Lines can be found on 1480-1482, in 'Microsoft.CppCommon.targets', which can be found in C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Microsoft\VC\v160. If you can't find the lines or file, please check out the error message during the project build. 

Further instruction to install and setting up the environment will be given in TA session.

### Deliverable 
You should submit following three items:
<ul>
<li>PluginProcessor.h</li>
<li>PluginProcessor.cpp</li>
<li>EQTutorial.vst or EQTutorial.component (macOS) | EQTutorial.dll (Windows)</li>
</ul>

Result plug-in files can be found in following directories. If you can't find them, please check https://docs.juce.com/master/tutorial_app_plugin_packaging.html for more information.
<ul>
<li>~/Library/Audio/Plug-Ins/VST/EQTutorial.vst (macOS)</li>
<li>~/Library/Audio/Plug-Ins/Components/EQTutorial.component (macOS)</li>
<li>\(path to your EQ Tutorial Project)/Builds/MacOSX/build/Debug/EQTutorial.vst (macOS)</li>
<li>\(path to your EQ Tutorial Project)/Builds/MacOSX/build/Debug/EQTutorial.component (macOS)</li>
<li>C:\Program Files\VstPlugins\EQTutorial.dll (Windows)</li>
<li>\(path to your EQ Tutorial Project)\Builds\VisualStudio2019\build\Debug\EQTutorial.dll (Windows)</li>
</ul>

Please compress them as a single zip file named as '(student id)\_(name).zip' and submit it via KLMS. (e.g. 20210000\_JohnDoe.zip)

## Problem #1: Bi-quad EQ Plug-in (100 pts.)

1. Use attached 'biquad.ipynb' to check out how the bi-quad EQ modifies the white noise. Try out different fc, Q and GdB. Also, you can use your own audio file rather than the white noise. 

2. Open 'EQTutorial.jucer' to open the JUCE project. It includes an implementation of one-pole one-zero filter.

3. Modify following parts in 'PluginProcessor.h' and 'PluginProcessor.cpp' to implement a bi-quad EQ filter, as example given in 'biquad.ipynb'. Note the instructions below.

(PluginProcessor.h)
```
private:
    // input parameters
    float _gain, _Q, _fc, _fs;
    
    // delay elements
    float _z_ff1[2], _z_fb1[2];

    // filter coefficients
    float _b0, _b1, _a0, _a1;
```
\* Add delay elements and filter coefficients.

(PluginProcessor.cpp)
```
EqtutorialAudioProcessor::EqtutorialAudioProcessor()
...
    // initialize variables
    _gain(1.0f),
    _Q(1.0f),
    _fc(1000.0f),
    _fs(44100.0f),
    _z_ff1{0.0f,0.0f},
    _z_fb1{0.0f,0.0f}
```
\* Initialize the added delay elements and filter coefficients.

```
void EqtutorialAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
...
            //
            // One-Pole One-Zero Filter Difference Equation
            //
            // Instead of writing the output directly to outBuffer, use a temporary variable.
            // Otherwise, you override the outBuffer to inBuffer at the time index
            float output = (_b0*inBuffer[n] + _b1*_z_ff1[ch] - _a1*_z_fb1[ch] )/_a0;
            _z_fb1[ch] = output;
            _z_ff1[ch] = inBuffer[n];
            outBuffer[n] = output;
```
\* Replace the equation for one-pole one-zero filter to two-pole two-zero filter.

```
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
```
\* Modify the relation between the user parameters and filter coefficients for the proper bi-quad EQ filter.

4. Build the implementation and check out the result plug-in with DAW. Verify your result by comparing it with the result from 'biquad.ipynb'.
