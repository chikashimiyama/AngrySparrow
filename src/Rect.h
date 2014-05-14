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
        Rect(std::vector<float> *targetVectorPtr, std::vector<float> *frequencyVectorPtr,  std::vector<float> *dutyCycleVectorPtr, float initialPhase = 0.0) : Oscillator(targetVectorPtr, frequencyVectorPtr, initialPhase){
            Rect::dutyCycleVectorPtr = dutyCycleVectorPtr;
        };
        
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
