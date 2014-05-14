#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "Sine.h"

std::vector<float> targetVec,freqVec;
AngrySparrow::Sine sine(&targetVec, &freqVec);

int generator( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData )
{
  unsigned int i, j;
  float *buffer = (float *) outputBuffer;
  if ( status )
    std::cout << "Stream underflow detected!" << std::endl;

  sine.performDSP(); // create sine wave
  int x = 0;
  for (int i = 0; i < nBufferFrames; ++i){
    buffer[x++] = targetVec[i];
    buffer[x++] = targetVec[i];
  }
  return 0;
}

int main()
{
  RtAudio dac;
  if ( dac.getDeviceCount() < 1 ) {
    std::cout << "\nNo audio devices found!\n";
    exit( 0 );
  }

  RtAudio::StreamParameters parameters;
  parameters.deviceId = dac.getDefaultOutputDevice();
  parameters.nChannels = 2;
  parameters.firstChannel = 0;
  unsigned int sampleRate = 44100;
  unsigned int bufferFrames = AngrySparrow::vectorSize; // 256 sample frames

  targetVec.assign(AngrySparrow::vectorSize, 0.0);
  freqVec.assign(AngrySparrow::vectorSize, 440);

  try {
    dac.openStream( &parameters, NULL, RTAUDIO_FLOAT32,
                    sampleRate, &bufferFrames, &generator, NULL );
    dac.startStream();
  }
  catch ( RtAudioError& e ) {
    e.printMessage();
    exit( 0 );
  }
  
  char input;
  std::cout << "\nPlaying ... press <enter> to quit.\n";
  std::cin.get( input );
  try {
    // Stop the stream
    dac.stopStream();
  }
  catch (RtAudioError& e) {
    e.printMessage();
  }
  if ( dac.isStreamOpen() ) dac.closeStream();
  return 0;
}