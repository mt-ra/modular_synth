# Modular Synth
An audio synthesizer (library?).

I made this on Debian. Portability was not a priority.

## Current State of the Project:
I made a module called TestSquare, (which actually produces a saw wave)
When the app is run, it should output a saw sound.
However I can't get it to compile just yet

## Dependencies
### Boost
In the Makefile, set the `BOOST_INCLUDE` variable to the directory where Boost is installed

### PortAudio
These Makefile variables may also change depending on where you have PortAudio installed
`PORTAUDIO_INCLUDE` is the directory containing the "portaudio.h" file
`PORTAUDIO_LIB` variable is the path to the "libportaudio.a" file

In my case, I just installed portaudio directly into the project's lib folder

### Additional Libraries
Make sure that you have these as well
`LDFLAGS := -lrt -lasound -ljack -pthread`
