#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "AngrySparrow.h"
#include "example.h"

using namespace AngrySparrow;
std::vector<float> targetVec, coefVec;
OnePole onepole(&targetVec, &coefVec);
Noise noise(&targetVec);
Ramp ramp(&coefVec, 1.0, 0.0, 5.0);
DSP dsp;

int generator( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData ){
  float *buffer = (float *) outputBuffer;
  if ( status )
    std::cout << "Stream underflow detected!" << std::endl;

  dsp.run();

  for (int i=0; i<nBufferFrames; i++ ) {
      *buffer++ = targetVec[i] * 0.1;
      *buffer++ = targetVec[i] * 0.1;
  }
  return 0;
}

int main(){
  coefVec.assign(vectorSize, 0);
  targetVec.assign(vectorSize, 0);

  // order of execution
  dsp.addToChain(&ramp);
  dsp.addToChain(&noise);
  dsp.addToChain(&onepole);
  
  setup(&generator);
  return 0;
}