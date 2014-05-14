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
        float current; ///< destination value
        float incrementer; ///< internal variable for increment
        float destination; ///< destination value
        unsigned long duration; ///< number of samples to reach the goal
        unsigned long counter;
        float progress; ///< prgress towards the goal
        bool arrived;

    public:
        Ramp(std::vector<float> *targetVectorPtr, float destination = 0.0, float current = 0.0, float duration = 0.0):UnitGenerator(targetVectorPtr){
            setDuration(duration);
            setDestination(destination);
            setCurrent(current);
            counter = 0;
            arrived = false;
        }; 

        void setDuration(unsigned long duration);
        unsigned long getDuration(void);

        void setDestination(float destination);
        float getDestination();

        void setCurrent(float current);
        float getCurrent();

        virtual void performDSP();
    };

    inline void Ramp::setDuration(unsigned long duration){
        Ramp::duration = duration;
        arrived = false;
    }

    inline unsigned long Ramp::getDuration(){
        return duration;
    }

    inline void Ramp::setCurrent(float current){
        Ramp::current = current;
    }

    inline float Ramp::getCurrent(){
        return current;
    }

    inline void Ramp::setDestination(float destination){
        Ramp::destination = destination;
        incrementer = (destination - current) / duration;
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
