/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef ExpRamp_h
#define ExpRamp_h

#include <cmath>
#include "Const.h"
#include "Ramp.h"

namespace AngrySparrow {
    
    /**
     * @brief a exponetial ramp generator. 
     */
    class ExpRamp: public Ramp{
    protected:
        float curve;
        void updateIncrementer(); ///< calc increment per sample

    public:
        /**
         * @brief constructor
         * 
         * @param tvp pointer to the output vector
         * @param dst destination value of the ramp
         * @param ct current value of the ramp
         * @param dur duration of the ramp
         * @param curve curve factor
         * @return [description]
         */
        ExpRamp(std::vector<float> *tvp, float dst = 880.0, float ct = 440.0, float dur = 1.0, float cv = 1.0):UnitGenerator(tvp), destination(dst), current(ct), duration(secondToSample(dur), curve(cv)){
            updateIncrementer();
        }; 

        virtual void performDSP();
    };

    inline void ExpRamp::updateIncrementer(){
        incrementer = (destination - current) / duration;
    }

    inline void ExpRamp::performDSP(){
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
