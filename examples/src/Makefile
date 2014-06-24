CC = g++
CFLAGS =  -O3
LIBS = -lstdc++ -lpthread -framework CoreAudio -framework CoreFoundation
FILES = *.cpp
STATIC_LIB = ../lib/librtaudio.a
INCLUDE_PATH = -I ../include -I ../../src
OBJECTS = RtAudio.o

all: sine.out fm.out rect.out ramp.out expRamp.out lowpass.out highpass.out wavetable.out play.out envelope.out

sine.out: sine.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) sine.cpp $(OBJECTS) 

fm.out: fm.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) fm.cpp $(OBJECTS) 

rect.out: rect.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) rect.cpp $(OBJECTS) 

ramp.out: ramp.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) ramp.cpp $(OBJECTS) 

expRamp.out: expRamp.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) expRamp.cpp $(OBJECTS) 

lowpass.out: lowpass.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) lowpass.cpp $(OBJECTS) 

highpass.out: highpass.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) highpass.cpp $(OBJECTS) 

wavetable.out: wavetable.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) wavetable.cpp $(OBJECTS) 

play.out: play.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) play.cpp $(OBJECTS) 

envelope.out: envelope.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) envelope.cpp $(OBJECTS) 
clean:
	rm *.out