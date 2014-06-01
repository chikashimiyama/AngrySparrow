#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "AngrySparrow.h"
#include "example.h"

using namespace AngrySparrow;
std::vector<float> targetVec(vectorSize), positionVec(vectorSize), freqVec(vectorSize), tableVec(sampleRate * 5);
Sine sine(&targetVec, &freqVec);
Play control(&freqVec, &positionVec, &tableVec);
Ramp ramp(&positionVec, sampleRate * 5, 0, 4.9);
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
  for(int i = 0; i < sampleRate * 5; i++){
    tableVec[i] = sin(i / (4410.0 - ( i / 100.0))) * 880 + 1000; // large vibrato
  }
  dsp.addToChain(&ramp);
  dsp.addToChain(&control);
  dsp.addToChain(&sine);
  setup(&generator);
  return 0;
}