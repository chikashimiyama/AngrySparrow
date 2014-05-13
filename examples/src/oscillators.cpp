#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include "Sine.h"

AngrySparrow::Sine sine;

int generator( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData )
{
  unsigned int i, j;
  float *buffer = (float *) outputBuffer;
  if ( status )
    std::cout << "Stream underflow detected!" << std::endl;

  std::vector<float> fv = sine.getNextVector();

  for ( i=0; i<nBufferFrames; i++ ) {
      *buffer++ = fv[i];
      *buffer++ = fv[i];
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

  sine.setAudioRateMode(false);
  RtAudio::StreamParameters parameters;
  parameters.deviceId = dac.getDefaultOutputDevice();
  parameters.nChannels = 2;
  parameters.firstChannel = 0;
  unsigned int sampleRate = 44100;
  unsigned int bufferFrames = 256; // 256 sample frames
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