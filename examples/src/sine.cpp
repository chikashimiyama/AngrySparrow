#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "AngrySparrow.h"
#include "example.h"

using namespace AngrySparrow;
std::vector<float> targetVec,freqVec;
Sine sine(&targetVec, &freqVec);
DSP dsp;

int generator( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData )
{
  unsigned int i, j;
  float *buffer = (float *) outputBuffer;
  if ( status )
    std::cout << "Stream underflow detected!" << std::endl;

  dsp.run();
  for (int i = 0; i < nBufferFrames; ++i){
    *buffer++ = targetVec[i] * 0.1;
    *buffer++ = targetVec[i] * 0.1;
  }
  return 0;
}

int main(){
  targetVec.assign(vectorSize, 0.0);
  freqVec.assign(vectorSize, 440);
  dsp.addToChain(&sine);
  setup(&generator);
  return 0;
}