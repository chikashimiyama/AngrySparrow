#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "AngrySparrow.h"
#include "example.h"

std::vector<float> targetVec, freqVec, modVec, adderVec, multiVec;
AngrySparrow::Sine mod(&modVec, &freqVec);
AngrySparrow::Sine carrier(&targetVec, &modVec);
AngrySparrow::Multiplier multiplier(&modVec, &adderVec);
AngrySparrow::Adder adder(&modVec, &multiVec);

int generator( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData )
{
  unsigned int i, j;
  float *buffer = (float *) outputBuffer;
  if ( status )
    std::cout << "Stream underflow detected!" << std::endl;


  mod.performDSP();
  std::vector<float>::iterator it = modVec.begin();
  multiplier.performDSP();
  adder.performDSP();
  carrier.performDSP();

  for ( i=0; i<nBufferFrames; i++ ) {
      *buffer++ = targetVec[i] * 0.1;
      *buffer++ = targetVec[i] * 0.1;
  }
  return 0;
}

int main(){
  targetVec.assign(AngrySparrow::vectorSize, 0);
  freqVec.assign(AngrySparrow::vectorSize, 221);
  modVec.assign(AngrySparrow::vectorSize, 0);
  multiVec.assign(AngrySparrow::vectorSize, 440);
  adderVec.assign(AngrySparrow::vectorSize, 880);
  setup(&generator);
  return 0;
}