#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "AngrySparrow.h"
#include "example.h"

using namespace AngrySparrow;
std::vector<float> targetVec, envVec, rampVec, envTable;

Noise noise(&targetVec);
Play envelope(&targetVec, &rampVec, &envTable);
Ramp ramp(&rampVec, sampleRate * 3.8, 0, 3.8);
Multiplier multiplier(&targetVec, &envVec);
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
  std::vector<float> values, times;

  values.push_back(0);
  values.push_back(1.0);
  values.push_back(0.5);
  values.push_back(0);

  times.push_back(0.3);
  times.push_back(0.5);
  times.push_back(3.0);

  envTable = EnvGen::envelope(&values, &times);

  targetVec.assign(vectorSize, 0.0);
  envVec.assign(vectorSize, 0.0);
  rampVec.assign(vectorSize, 0.0);

  dsp.addToChain(&noise);
  dsp.addToChain(&envelope);
  dsp.addToChain(&multiplier);
  setup(&generator);
  return 0;
}