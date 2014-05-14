//
//  Phasor.h
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
        virtual void performDSP();
    public:
        virtual vector<float> getNextVector();
    };
    
    inline void Phasor::performDSP(){
        
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
        performDSP();
        return outputVector;
    };
    
}


#endif
