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
        virtual void performDSP_CR();
        virtual void performDSP_AR();
    public:
        virtual std::vector<float> getNextVector();
    };
    
    inline void Sine::performDSP_CR(){
        for (int i = 0; i < vectorSize; i++) {
            outputVector[i] = sin(phase);
            getNext();
        }
    }
    
    inline void Sine::performDSP_AR(){
        
        if(!frequencyVectorPtr){
            std::cout << "Sine: frequencyVectorPtr not set" << std::endl;
            return;
        }
        for (int i = 0; i < vectorSize; i++) {
            outputVector[i] = sin(phase);
            frequency = (*frequencyVectorPtr)[i];
            updatePhaseIncrement();
            getNext();
        }
    }
    
    inline std::vector<float> Sine::getNextVector(){
        if(audioRateMode){
            performDSP_AR();
        }else{
            performDSP_CR();
        }
        return outputVector;
    };
    
}


#endif
