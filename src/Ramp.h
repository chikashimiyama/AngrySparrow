/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Ramp_h
#define Ramp_h

#include <cmath>
#include "Const.h"

namespace AngrySparrow {
    
    /**
     * @brief a ramp generator. This ramp generator cannot accept sample resolution destination change
     */
    class Ramp: public UnitGenerator{
    protected:
        float incrementer; ///< internal variable for increment
        float distance; ///< distance between destination and current value

        float current; ///< destination value
        float destination; ///< destination value
        unsigned long duration; ///< number of samples to reach the goal
        unsigned long counter; ///< current progress
        float progress; ///< prgress towards the goal
        bool arrived; ///< destination arrived or not

    public:
        /// constructor
        Ramp(std::vector<float> *tvp, float dst = 880.0, float ct = 440.0, float dur = 1.0):UnitGenerator(tvp), destination(dst), current(ct), duration(secondToSample(dur)){
            counter = 0;
            arrived = false;
            distance = destination - current;
            incrementer = distance / duration;
        }; 

        void setDuration(float duration); ///< set duration
        float getDuration(void); ///< get duration

        void setDestination(float destination); ///< set destination
        float getDestination(); ///< get destination

        void setCurrent(float current); ///< set current
        float getCurrent(); ///< get current

        virtual void performDSP();
    };

    inline void Ramp::setDuration(float duration){
        Ramp::duration = secondToSample(duration);
        arrived = false;
    }

    inline float Ramp::getDuration(){
        return sampleToSecond(duration);
    }

    inline void Ramp::setCurrent(float current){
        Ramp::current = current;
    }

    inline float Ramp::getCurrent(){
        return current;
    }

    inline void Ramp::setDestination(float destination){
        Ramp::destination = destination;
        distance = destination - current;
        incrementer = distance / duration;
    }

    inline float Ramp::getDestination(){
        return destination;
    }

    inline void Ramp::performDSP(){
        for(int i = 0; i< vectorSize; i++){
            if(!arrived){
                (*targetVectorPtr)[i] = current;
                current += incrementer;
                counter++;
            }
            if(duration < counter){
                arrived = true;
                counter = 0;
            }
        }
    }    
}

#endif
