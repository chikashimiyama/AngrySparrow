//
//  Waveforms.h
//
//  Created by Chikashi Miyama on 12/05/14.
//
//

#ifndef Phasor_h
#define Phasor_h

#include "Oscillator.h"
#include <iostream>

namespace AngrySparrow {
    
    class Phasor : public Oscillator{
        virtual void performDSP_CR();
        virtual void performDSP_AR();
    public:
        virtual vector<float> getNextVector();
    };
    
    inline void Phasor::performDSP_CR(){
        for (int i = 0; i < vectorSize; i++) {
            outputVector[i] = phase / CYCLE;
            getNext();
        }
    }
    
    inline void Phasor::performDSP_AR(){
        
        if(!frequencyVectorPtr){
            cout << "Phasor: frequencyVectorPtr not set" << endl;
            return;
        }
        for (int i = 0; i < vectorSize; i++) {
            outputVector[i] = phase / CYCLE;
            frequency = (*frequencyVectorPtr)[i];
            updatePhaseIncrement();
            getNext();
        }
    }
    
    inline vector<float> Phasor::getNextVector(){
        if(audioRateMode){
            performDSP_AR();
        }else{
            performDSP_CR();
        }
        return outputVector;
    };
    
//
//    class Saw : public Oscillator{
//    public:
//        virtual vector<float> getNextVector();
//    };
//    
//    inline vector<float> Saw::getNextVector(){
//        
//        for (int i = 0; i < vectorSize; i++) {
//            
//            outputVector[i] = phase / CYCLE - 0.5;
//            getNext(); // increment phase
//        }
//        return outputVector;
//    };
//    
//    class Triangle : public Oscillator{
//    public:
//        virtual vector<float> getNextVector();
//    };
//    
//    inline vector<float> Triangle::getNextVector(){
//        
//        for (int i = 0; i < vectorSize; i++) {
//            float location = phase / CYCLE;
//            outputVector[i] = location > 0.5 ? 1.0 - location : location;
//            getNext(); // increment phase
//        }
//        return outputVector;
//    };
//    
//    class Sin : public Oscillator{
//    public:
//        virtual vector<float> getNextVector();
//    };
//    
//    inline vector<float> Sin::getNextVector(){
//        
//        for (int i = 0; i < vectorSize; i++) {
//            outputVector[i] = sin(phase);
//            getNext(); // increment phase
//        }
//        return outputVector;
//    };
//    
//    class Cos : public Oscillator{
//    public:
//        virtual vector<float> getNextVector();
//    };
//    
//    inline vector<float> Cos::getNextVector(){
//        
//        for (int i = 0; i < vectorSize; i++) {
//            outputVector[i] = cos(phase);
//            getNext(); // increment phase
//        }
//        return outputVector;
//    };
    
}


#endif
