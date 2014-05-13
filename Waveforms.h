//
//  Waveforms.h
//
//  Created by Chikashi Miyama on 12/05/14.
//
//

#ifndef Phasor_h
#define Phasor_h

#include "Oscillator.h"

namespace AngrySparrow {
    
    class Phasor : public Oscillator{
    public:
        virtual vector<float> getNextVector();
    };
    
    inline vector<float> Phasor::getNextVector(){
        
        for (int i = 0; i < vectorSize; i++) {
            
            outputVector[i] = phase / CYCLE;
            getNext(); // increment phase
        }
        return outputVector;
    };

    class Saw : public Oscillator{
    public:
        virtual vector<float> getNextVector();
    };
    
    inline vector<float> Saw::getNextVector(){
        
        for (int i = 0; i < vectorSize; i++) {
            
            outputVector[i] = phase / CYCLE - 0.5;
            getNext(); // increment phase
        }
        return outputVector;
    };
    
    class Triangle : public Oscillator{
    public:
        virtual vector<float> getNextVector();
    };
    
    inline vector<float> Triangle::getNextVector(){
        
        for (int i = 0; i < vectorSize; i++) {
            float location = phase / CYCLE;
            outputVector[i] = location > 0.5 ? 1.0 - location : location;
            getNext(); // increment phase
        }
        return outputVector;
    };
    
    class Sin : public Oscillator{
    public:
        virtual vector<float> getNextVector();
    };
    
    inline vector<float> Sin::getNextVector(){
        
        for (int i = 0; i < vectorSize; i++) {
            outputVector[i] = sin(phase);
            getNext(); // increment phase
        }
        return outputVector;
    };
    
    class Cos : public Oscillator{
    public:
        virtual vector<float> getNextVector();
    };
    
    inline vector<float> Cos::getNextVector(){
        
        for (int i = 0; i < vectorSize; i++) {
            outputVector[i] = cos(phase);
            getNext(); // increment phase
        }
        return outputVector;
    };
    
}


#endif
