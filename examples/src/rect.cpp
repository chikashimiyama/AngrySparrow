#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "AngrySparrow.h"
#include "example.h"

using namespace AngrySparrow;
std::vector<float> targetVec,freqVec, dutyVec;
Ramp ramp(&dutyVec, 0.9, 0.01, 5.0);
Rect rect(&targetVec, &freqVec, &dutyVec);

int generator( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData )
{
  unsigned int i, j;
  float *buffer = (float *) outputBuffer;
  if ( status )
    std::cout << "Stream underflow detected!" << std::endl;

  ramp.performDSP();
  rect.performDSP(); // create sine wave
  int x = 0;
  for (int i = 0; i < nBufferFrames; ++i){
    buffer[x++] = targetVec[i] * 0.1;
    buffer[x++] = targetVec[i] * 0.1;
  }
  return 0;
}

int main(){
  targetVec.assign(vectorSize, 0.0);
  freqVec.assign(vectorSize, 110);
  dutyVec.assign(vectorSize, 0.01);

  setup(&generator);
  return 0;
}