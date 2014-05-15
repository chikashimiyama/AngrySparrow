/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Sine_h
#define Sine_h

#include "Oscillator.h"
#include <iostream>

namespace AngrySparrow {
    
    /**
     * @brief standard Sine wave oscillator. it uses Sine() function. Thus, computationally heavy
     */
    class Sine : public Oscillator{
    public:
        /// constructor
        Sine(std::vector<float> *tvp, std::vector<float> *fvp, float ip = 0.0):Oscillator(tvp, fvp, ip){};
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
