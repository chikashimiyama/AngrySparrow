CC = g++
CFLAGS =  -O3
LIBS = -lstdc++ -lpthread -framework CoreAudio -framework CoreFoundation
FILES = *.cpp
STATIC_LIB = ../lib/librtaudio.a
INCLUDE_PATH = -I ../include -I ../../src
OBJECTS = RtAudio.o

all: sine.out fm.out rect.out ramp.out onepole.out

sine.out: sine.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) sine.cpp $(OBJECTS) 

fm.out: fm.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) fm.cpp $(OBJECTS) 

rect.out: rect.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) rect.cpp $(OBJECTS) 

ramp.out: ramp.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) ramp.cpp $(OBJECTS) 

onepole.out: onepole.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) onepole.cpp $(OBJECTS) 

clean:
	rm *.out