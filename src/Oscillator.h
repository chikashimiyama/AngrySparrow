/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Oscillator_h
#define Oscillator_h

#include <cmath>
#include "Const.h"
#include "Generator.h"

namespace AngrySparrow {
    
    /**
     * @brief an abstract class of autonomous oscillator
     */
    class Oscillator : public Generator{
    protected:
        bool audioRateMode; ///< when true, enables sample based computation (necessary for e.g. frequency modulation )
        float frequency; ///< frequency in non audioRate mode

        float phase; ///< internal varibale which storing current phase
        float phaseIncrement; ///< increment by phase
        
        void updatePhaseIncrement(); ///< internal function for calculating phaseIncrement from Freq
        void getNext(); ///< advance the phase and get the value of phase
    
        std::vector<float> *frequencyVectorPtr; ///< a pointer to a vector of frequencies

    public:
        Oscillator(float freq = 440.0, float initialPhase = 0.0, bool audioRateMode = true, float mul = 1.0, float add = 0.0); ///< constructor
        
        void setAudioRateMode(bool audioRateMode); ///< set mode of the oscillator
        bool getAudioRateMode(); ///< get current mode of the osciilator

        void setFrequency(float frequency); ///< set the control rate frequency
        void setFrequencyVectorPtr(std::vector<float> *frequencyVectorPtr); /// set the vector of audio rate frequency

        float getFrequency(); ///< get the control rate frequency
        float getPhaseIncrement(); ///< get current phase increment
        
        void setPhase(float phase); ///< force set the phase
        void resetPhase(); ///< set the phase to 0
        float getPhase(); ///< get current phase
        
        virtual std::vector<float> getNextVector() = 0; ///< virtual abstract function for generating audio vectors. should be implmeneted in the subclasses.
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
    
    inline Oscillator::Oscillator(float frequency, float initialPhase, bool audioRateMode, float mul, float add ){
        updatePhaseIncrement();
        outputVector.assign(vectorSize, 0.0);
        setPhase(initialPhase);
        setFrequency(frequency);
        setAudioRateMode(audioRateMode);
        setMul(mul);
        setAdd(add);
    }
    
    inline void Oscillator::setAudioRateMode(bool audioRateMode){
        Oscillator::audioRateMode = audioRateMode;
    }
    
    inline bool Oscillator::getAudioRateMode(){
        return audioRateMode;
    }
    
    inline void Oscillator::setFrequency(float frequency){
        Oscillator::frequency = frequency;
        updatePhaseIncrement();
    }
    
    inline void Oscillator::setFrequencyVectorPtr(std::vector<float> *frequencyVectorPtr){
        Oscillator::frequencyVectorPtr = frequencyVectorPtr;
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
