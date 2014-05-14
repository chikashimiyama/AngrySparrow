CC = g++
CFLAGS =  -O3
LIBS = -lstdc++ -lpthread -framework CoreAudio -framework CoreFoundation
FILES = *.cpp
STATIC_LIB = ../lib/librtaudio.a
INCLUDE_PATH = -I ../include -I ../../src
OBJECTS = RtAudio.o

all: sine.out 

sine.out: sine.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) sine.cpp $(OBJECTS) 


fm.out: fm.cpp $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(LIBS) $(INCLUDE_PATH) fm.cpp $(OBJECTS) 

clean:
	rm *.out