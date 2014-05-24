#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "AngrySparrow.h"
#include "example.h"

using namespace AngrySparrow;

const int tableSize = 512; // 512 + 1
std::vector<float> targetVec(vectorSize), freqVec(vectorSize), tableVec(tableSize+1);
WaveTable wavetable(&targetVec, &freqVec, &tableVec);
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
  
  for(int i = 0; i < tableSize; i++){
    tableVec[i] = sin(static_cast<float>(i)/static_cast<float>(tableSize) * CYCLE );
    tableVec[i] += sin(static_cast<float>(i)/static_cast<float>(tableSize) * CYCLE * 3) * 0.5;
    tableVec[i] += sin(static_cast<float>(i)/static_cast<float>(tableSize) * CYCLE * 5) * 0.25;
    tableVec[i] *= 0.5;
  }

  Interpolation::prepareLinear(&tableVec);
  targetVec.assign(vectorSize, 0.0);
  freqVec.assign(vectorSize, 440);
  dsp.addToChain(&wavetable);
  setup(&generator);
  return 0;
}