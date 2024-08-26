# Anatomy

Components of a modular synth:
- Module
    - MIDI to Voltage
    - Voltage to Voltage
    - MIDI Generators
    - Voltage Generators
- Controller

In the main file, the client can chain nodes together.
This is done through a controller (acts like the matrix in Serum).
The controller is passed into the PortAudio callback function.

In a typical synth, the MIDI input (owned by the controller), is pushed into 
a MIDI to Voltage module, whose output voltage is pushed into an effect,
whose output voltage is pushed into the controller's output.

## Nodes
*Receiving Input*
Each node has one or more circular buffers used for input.
Each is either a circular buffer of MIDI messages, or a circular buffer of floats (waveform positions)
A input-producer will notify the receiver when data is pushed to the buffer.

*Processing*
The node will then do some processing, which will depend on the input data,
the BPM set by the controller, and the sample rate set by the controller.

*Pushing Output*
There is only one output, but it can be split and pushed into multiple receivers.
If the output is to be played as a sound, then it is pushed into the controller's output.

### Parameter List
Each node

## Controller

