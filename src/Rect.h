/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Rect_h
#define Rect_h

#include "Oscillator.h"
#include <iostream>

namespace AngrySparrow {
    
    /**
     * @brief phase distortion
     */
    class Rect : public Oscillator{
    protected:
        std::vector<float> *dutyCycleVectorPtr;
    public:
        Rect(std::vector<float> *tvp, std::vector<float> *fvp, std::vector<float> *dcvp, float ip = 0.0) : Oscillator(tvp, fvp, ip), dutyCycleVectorPtr(dcvp){};
        virtual void performDSP();
    };

    inline void Rect::performDSP(){
        float state;
        for (int i = 0; i < vectorSize; i++) {
            state = phase / CYCLE;
            (*targetVectorPtr)[i] = state < (*dutyCycleVectorPtr)[i] ? -1.0 : 1.0;
            advancePhase((*frequencyVectorPtr)[i]);
        }
    } 
}


#endif
