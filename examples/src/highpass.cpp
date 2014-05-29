#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "AngrySparrow.h"
#include "example.h"

using namespace AngrySparrow;
std::vector<float> targetVec, cutoffVec;
HighPass highpass(&targetVec, &cutoffVec);
Noise noise(&targetVec);
Ramp ramp(&cutoffVec, 100.0, 8000.0, 5.0);
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
  cutoffVec.assign(vectorSize, 0);
  targetVec.assign(vectorSize, 0);

  // order of execution
  dsp.addToChain(&ramp);
  dsp.addToChain(&noise);
  dsp.addToChain(&highpass);
  
  setup(&generator);
  return 0;
}