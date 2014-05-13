/*
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Oscillator_h
#define Oscillator_h

#include <cmath>
#include "Const.h"

namespace AngrySparrow {
    
    
    /*
     * @brief an abstract class of autonomous oscillator
     */
    class Oscillator{
    protected:
        float frequency;
        float phase;
        float phaseIncrement;
        
        void updatePhaseIncrement();
        void getNext();
    
        vector<float> frequencyVector;
        vector<float> outputVector;
        
    public:
        Oscillator(float freq = 440.0, float initialPhase = 0.0);
        void setFrequency(float frequency);
        void setFrequency(vector<float> frequencyVector);
        float getFrequency();
        float getPhaseIncrement();
        
        void setPhase(float phase);
        void resetPhase();
        float getPhase();
        
        virtual vector<float> getNextVector() = 0;
    };
    
    inline void Oscillator::updatePhaseIncrement(){
        phaseIncrement = CYCLE / (sampleRate / frequency);
    }
    
    inline void Oscillator::getNext(){
        phase += phaseIncrement;
        if(phase > CYCLE)
            phase -= CYCLE;
        else if(phase < 0.0)
            phase += CYCLE;
    }
    
    inline Oscillator::Oscillator(float frequency, float initialPhase){
        Oscillator::phase = initialPhase;
        Oscillator::frequency = frequency;
        updatePhaseIncrement();
        outputVector.assign(vectorSize, 0.0);
    }
    
    inline void Oscillator::setFrequency(float frequency){
        Oscillator::frequency = frequency;
        updatePhaseIncrement();
    }
    
    inline float Oscillator::getFrequency(){
        return frequency;
    }
    
    inline float Oscillator::getPhaseIncrement(){
        return phaseIncrement;
    }
    
    inline void Oscillator::setPhase(float phase){
        Oscillator::phase = phase;
    }
    
    inline void Oscillator::resetPhase(){
        Oscillator::phase = 0.0;
    }

    inline float Oscillator::getPhase(){
        return phase;
    }
    
}

#endif
