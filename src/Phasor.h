/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Phasor_h
#define Phasor_h

#include "Oscillator.h"
#include <iostream>

namespace AngrySparrow {
    
    /**
     * @brief standard Phasor that outputs signal from 0 to 1.
     */
    class Phasor : public Oscillator{
    public:
        Phasor(std::vector<float> *targetVectorPtr, std::vector<float> *frequencyVectorPtr, float initialPhase = 0.0): 
            Oscillator(targetVectorPtr, frequencyVectorPtr, initialPhase){};
        
        virtual void performDSP();
    };

    inline void Phasor::performDSP(){
        for (int i = 0; i < vectorSize; i++) {
            (*targetVectorPtr)[i] =  phase / CYCLE;
            advancePhase((*frequencyVectorPtr)[i]);
        }
    } 
}


#endif
