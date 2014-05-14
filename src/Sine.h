//
//  Sine.h
//
//  Created by Chikashi Miyama on 12/05/14.
//
//

#ifndef Sine_h
#define Sine_h

#include "Oscillator.h"
#include <iostream>

namespace AngrySparrow {
    
    /**
     * @brief standard Sinee wave oscillator. it uses Sine() function. Thus, computationally heavy
     */
    class Sine : public Oscillator{
    public:
        Sine(std::vector<float> *targetVectorPtr, std::vector<float> *frequencyVectorPtr, float initialPhase = 0.0): 
            Oscillator(targetVectorPtr, frequencyVectorPtr, initialPhase){};
        
        virtual void performDSP();
    };

    inline void Sine::performDSP(){
        for (int i = 0; i < vectorSize; i++) {
            (*targetVectorPtr)[i] = sin(phase);
            advancePhase((*frequencyVectorPtr)[i]);
        }
    } 
}


#endif
