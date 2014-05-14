#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "AngrySparrow.h"
#include "example.h"

using namespace AngrySparrow;
std::vector<float> targetVec, freqVec;
Sine sine(&targetVec, &freqVec);
Ramp ramp(&freqVec, 880, 440, 44100 );

int generator( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData )
{
  unsigned int i, j;
  float *buffer = (float *) outputBuffer;
  if ( status )
    std::cout << "Stream underflow detected!" << std::endl;

  ramp.performDSP();
  sine.performDSP(); // create sine wave
  int x = 0;
  for (int i = 0; i < nBufferFrames; ++i){
    buffer[x++] = targetVec[i] * 0.1;
    buffer[x++] = targetVec[i] * 0.1;
  }
  return 0;
}

int main(){
  targetVec.assign(vectorSize, 0.0);
  freqVec.assign(vectorSize, 440);
  setup(&generator);
  return 0;
}