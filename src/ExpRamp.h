/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef ExpRamp_h
#define ExpRamp_h

#include <cmath>
#include "Ramp.h"
#include "Const.h"

namespace AngrySparrow {
    
    /**
     * @brief a exponential ramp generator. This ramp generator cannot accept sample resolution destination change
     */
    class ExpRamp: public Ramp{
    protected:
        float factor; ///< curve factor
        
    public:
        /// constructor
        ExpRamp(std::vector<float> *tvp, float dst = 880.0, float ct = 440.0, float dur = 1.0, float fct = 1.0):Ramp(tvp, dst, ct, dur), factor(fct){}; 
        void setFactor(float factor);
        float getFactor();
        virtual void performDSP();
    };


    inline void ExpRamp::setFactor(float factor){
        ExpRamp::factor = factor;
    }

    inline float ExpRamp::getFactor(void){
        return ExpRamp::factor;
    }

    inline void ExpRamp::performDSP(){
        for(int i = 0; i< vectorSize; i++){
            if(!arrived){
                float position = static_cast<float>(counter) / duration;
                float processed = pow(position, factor);
                (*targetVectorPtr)[i] = distance * processed + current;
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
