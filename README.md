# NEURON
Neuron is a multi voice delay unit to use in an audio effect chain. 
It is meant to operate similar to a regular chorus unit, however, 
parameters provided allows it more extreme behavior. Each voice is effected by a 
modulated delay time with a uniqe rate contolled by an oscillator, 
thus is each voice given a doppler effect which can be adjusted to taste.

# Input
- Realtime audio (stereo)

# Output
- Realtime audio (stereo)

# Parameters
- Left Delay: Pre delay time for left channel in milliseconds.
- Right Delay: Pre delay time for right channel in milliseconds.
- Left Feedback: Feedback for left channel in percent.
- Right Feedback: Feedback for right channel in percent.
    Note: Even though 100% is displayed feedback is capped at 99% to prevent
    users from damaging their ears as it reinforces itself.
- Voices: The number of delay units working in unison with a maximum of 16 units.
- Dry/Wet: Ratio in percent of the signal is effected by the Neuron plugin.
- Depth: Percentage of the depth range available, 0.5 to 10 percent, of which the
    effect of the oscillator has on the delay time.
- Speed: Percentage of the available frequency rate range, 5 to 30 hz, in which 
    the voices oscillators can operate. To give each voice a uniqe rate, a 
    frequency of 0.2hz multiplied by voice number is added, i.e voice n has a 
    rate of (rate + 0.2 * n) hz, where n in {0,1,...15}.

# Presets (Plug-In Host sessions)
- Init: The initial settings for Neuron with an apple AUMIDISyth connected.
- PlainChorus: Standard chorus settings.
- MetallicReverb: Utilizes a lot of feedback with low depth and speed to give 
    the signal a tail.
- StereoSpread: Gives the signal a stereo spread with the Haas Effect.
- Choir: Utilizes all voices with full depth to distinct the voices and a lot of 
feedback as well as a 1 ms difference between right and left channel to give 
the signal width and a reverb illusion and stereo spread.
- Vibrato: A single voice gives the signal vibrato by having a high oscillation 
    depth.

# Future Work
- Neruon aspired to increasingly compress the output signal more and more as the
    chorus mix approaches 100%. However, this feature was de prioritized however 
    as it turned out to be too ambitious to achieve within the given time frame 
    of the project but is essential to implement to make Neuron distinguish 
    itself from other plugins.
- Stereo spread of voices (panning)
- Possibly add distortion to color the signal even more than what the 
    compression would provide.

# Known Bugs
none
