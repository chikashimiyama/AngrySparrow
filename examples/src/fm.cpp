#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "AngrySparrow.h"
#include "example.h"

using namespace AngrySparrow;
std::vector<float> targetVec, freqVec, modVec, adderVec, multiVec;
Sine mod(&modVec, &freqVec);
Sine carrier(&targetVec, &modVec);
Multiplier multiplier(&modVec, &adderVec);
Adder adder(&modVec, &multiVec);
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
  targetVec = allocVector(0);
  freqVec = allocVector(440);
  modVec = allocVector(0);
  multiVec = allocVector(330);
  adderVec = allocVector(840);

  // order of execution
  dsp.addToChain(&mod);
  dsp.addToChain(&multiplier);
  dsp.addToChain(&adder);
  dsp.addToChain(&carrier);

  setup(&generator);
  return 0;
}