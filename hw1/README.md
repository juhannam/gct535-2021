# Homework #1: Due Mar 28

### Instruction
The problem sets include short answers and Python programming. Organize your answers, figures and supporting comments using a word editor convenient for you (e.g., MS Word, Latex). You should use the Jupyter notebook for Python programming. You can set up the Jupyter notebook environment following the instruction as [this link](https://github.com/juhannam/gct535-2021/tree/main/practice). 

### Deliverable 
You should submit two items: the report and .ipynb file. Please compress them as a single file (e.g. zip) and submit it via KLMS.


## Problem #1: Sampling and Quantization (20 pts.)

1. Given a continuous-time signal $x(t) = sin(8000*\pi*t)+sin(14000*\pi*t)+sin(16000*\pi*t)$, you sampled it with a sampling rate 10000 Hz. Then, what are the resulting frequencies of the sinusoids in the discrete-time domain? (10pts.)
 
2. You want to compose a song for your dog and record it with your computer. Assuming that the dynamic range that your special and audibly-super-sensitive dog can hear is 200dB and your song is also extremely dynamic to cover all the range, what will be the appropriate number of bits when you store the recording into a fixed-point uncompressed file  (e.g. wav file)?  (10pts.)


## Problem #2: Sinusoids, Windows, Zero-padding and DFT (50 pts.)

First, generate a sinusoidal waveform with 440Hz frequency and 8kHz sampling rate (1 second long). Verify the result by plotting the waveform and playing it back. 

1. Segment the sinusoid with a 20ms-long rectangular window (size 160 samples) and perform DFT (size 256 samples) on the segment with zero-padding.  Plot the magnitude response in dB and phase response (10pts.) 

2. Repeat 1 with Hann window. Discuss the difference in the magnitude response. (10 pts.)

3. Repeat 2 with zero-padding such that FFT size becomes 1024. Discuss the difference in the magnitude response. (10 pts.)

4. You will see that magnitude response is even (symmetric with regard to y-axis) and phase response is odd (symmetric with regard to x-axis and y-axis). Discuss the reason (10pts.)


## Problem #3: Short-time Fourier Transform (60 pts.)

1. Implement a short-time Fourier transform function as follows (30pts.):

```
def stft(x, window, hop_size, fft_size):
 
# x: input samples (1-D vector)
# window: a window vector (e.g. window = hann(1024) where 1024 is the window size )
# hop_size: must be less than window size
# y: 2-D STFT matrix (complex numbers)

    ### Your Implementation of STFT ###


    return y
```

2. Load the provided glockenspiel WAV file and plot the spectrogram using your STFT function. Plot the spectrogram with two different window sizes such that one has high-time resolution and the other high frequency resolution. Describe what you observe (10 pts.)


3. Record your voice using Audacity (about 2-3 sec) and store it as a .wav file. Repeat b), particularly paying attention to vowel sounds.  (10 pts.)


4. Choose a music audio file (less than 10 seconds) and plot the spectrogram. Again, adjust the STFT parameters and see how they change the spectrogram. Compare your visual observation to what you hear in terms of musical element such as melodic or rhythm patterns. (10 pts.)




