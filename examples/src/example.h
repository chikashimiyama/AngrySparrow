
#include "AngrySparrow.h"

void setup();

inline void setup(RtAudioCallback generator){
  
  RtAudio dac;
  if ( dac.getDeviceCount() < 1 ) {
    std::cout << "No audio devices found!\n";
    exit( 0 );
  }

  RtAudio::StreamParameters parameters;
  parameters.deviceId = dac.getDefaultOutputDevice();
  parameters.nChannels = 2;
  parameters.firstChannel = 0;
  unsigned int sampleRate = AngrySparrow::sampleRate;
  unsigned int bufferFrames = AngrySparrow::vectorSize; // 256 sample frames

  try {
    dac.openStream( &parameters, NULL, RTAUDIO_FLOAT32, sampleRate, &bufferFrames, generator, NULL );
    dac.startStream();
  }
  catch ( RtAudioError& e ) {
    e.printMessage();
    exit( 0 );
  }
  
  char input;
  std::cout << "Playing ... press <enter> to quit.\n";
  std::cin.get( input );
  try {
    dac.stopStream();
  }
  catch (RtAudioError& e) {
    e.printMessage();
  }
  if ( dac.isStreamOpen() ) dac.closeStream();

}
