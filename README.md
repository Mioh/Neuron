# audioprogramming
Neuron is a multi voice delay unit. It is meant to operate as a regular chorus unit,
however, parameters provided allows it more extreme behaviour.

INPUT
Realtime audio (stereo)

OUTPUT
Realtime audio (stereo)

PARAMETERS
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

FUTURE WORK
- Neruon aspired to increasingly compress the output signal more and more as the 
chorus mix approaches 100%, this feature was deprioretised however as it turned
out to be too ambitious to achieve within the given time frame of the project. 