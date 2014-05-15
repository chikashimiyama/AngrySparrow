/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Oscillator_h
#define Oscillator_h

#include <cmath>
#include "Const.h"
#include "UnitGenerator.h"

namespace AngrySparrow {
    
    /**
     * @brief an abstract class of autonomous oscillator
     */
    class Oscillator: public UnitGenerator{
    protected:
        std::vector<float> *frequencyVectorPtr; ///< a reference to a vector of frequencies
        float phase; ///< internal varibale which storing current phase
        void advancePhase(float frequency); ///< advance the phase and get the value of phase

    public:
        /// constructor that invokes the constructor of the superclass
        Oscillator(std::vector<float> *tvp, std::vector<float> *fvp, float ip = 0.0) : UnitGenerator(tvp), frequencyVectorPtr(fvp), phase(ip){};
        void setPhase(float phase); ///< force set the phase
        void resetPhase(); ///< set the phase to 0
        float getPhase(); ///< get current phase
    };
    
    inline void Oscillator::advancePhase(float frequency){
        float phaseIncrement = CYCLE / (sampleRate / frequency);
        phase += phaseIncrement;
        if(phase > CYCLE)
            phase -= CYCLE;
        else if(phase < 0.0)
            phase += CYCLE;
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
