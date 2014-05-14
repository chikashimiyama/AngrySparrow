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
     * @brief a ramp generator
     */
    class Ramp: public UnitGenerator{
    protected:
        float current; ///< destination value
        float destination; ///< destination value
        float duration; ///< number of samples to reach the goal
        float progress; ///< prgress towards the goal

    public:
        Ramp(std::vector<float> *targetVectorPtr, float destination = 0.0, float duration = 0.0):UnitGenerator(targetVectorPtr){
            Ramp::destination = destination;
            Ramp::duration = duration;
        }; 

        virtual void performDSP();
    };
    
    inline void Ramp::performDSP(){

    }    
}

#endif
