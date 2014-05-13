TARGET = test
CC = g++
CFLAGS =  -O3
LIBS = -lstdc++ -lpthread -framework CoreAudio -framework CoreFoundation
FILES = *.cpp
STATIC_LIB = ../lib/librtaudio.a
INCLUDE_PATH = -I ../include -I ../../src
OBJECTS = RtAudio.o

all: $(FILES) $(OBJECTS)
	$(CC) -o $(TARGET) $(CFLAGS) $(LIBS) $(INCLUDE_PATH) $(FILES) $(OBJECTS) 
