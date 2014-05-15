AngrySparrow
============

My private C++ sound synthesis library.


Characteristics
- GPL v3
- Light weight
- Float 32 bit based
- Full sample/vector based
- Open Source
- Header Only, all inline 
- No dependencies

## Design
- All unit generators, including oscillators, do not have internal buffer for signal. Thus, the user must allocate a vector for signal output and provide a pointer to the vector to the unit generators
- It is users responsibility to allocate appropriate size of memories to the vector and free them if unnecessary


Examples require RtAudio 4.1.1 or above by McGill university
The example folder include static shared library compiled for MacOSX
See the following website for details.
https://www.music.mcgill.ca/~gary/rtaudio/

- Suitable to use with oF
- No audio sample reader/writer
- Documented with Doxygen

