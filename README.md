# NEURON
Neuron is a multi voice delay unit. It is meant to operate as a regular chorus unit,
however, parameters provided allows it more extreme behavior.

# Input
- Realtime audio (stereo)

# Output
- Realtime audio (stereo)

# Parameters
- Left Delay: Pre delay time for left channel in milliseconds
- Right Delay: Pre delay time for right channel in milliseconds
- Left Feedback: Feedback for left channel in percent.
- Right Feedback: Feedback for right channel in percent.
    Note: Even though 100% is displayed the percentage is set to 99% to prevent
    users from damaging their ears as the feedback reinforces itself.
- Voices: The number of delay units working in unison.
- Dry/Wet: Ratio in percent of the signal affected by the Neuron plugin.
- Depth: Percentage of the effect that the ocillator has on the delay time.
    Note: Not actual percentage but percentage of available depth.
- Speed: Percentage of the frequency span available for the ocillator's phase.

# Presets (Plug-In Host)
- Choir: Utilizes all voices with full depth to distinct the voices and a lot of feedback as well as a 1 ms difference between right and left channel to give the signal width and a reverb illusion.
- Init: The initial settings for Neuron with an apple AUMIDISyth connected.
- PlainChorus: Standard chorus settings.
- ReverbLike: Utilizes a lot of feedback with low depth and speed to give a reverb illusion.
- StereoSpread: Gives the signal a stereo spread.
- Vibrato: A single voice gives the signal vibrato by having heigh a high depth.


# Future Work
- Neruon aspired to increasingly compress the output signal more and more as the
chorus mix approaches 100%, this feature was de prioritized however as it turned
out to be too ambitious to achieve within the given time frame of the project.
- Stereo spread of voices (panning)
