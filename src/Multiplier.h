/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Multiplier_h
#define Multiplier_h

#include <cmath>
#include "Const.h"
#include "UnitGenerator.h"

namespace AngrySparrow {

    /**
     * @brief multiplying operand to the signal operand vector
     */
    class Multiplier : public UnitGenerator{

    public:
        std::vector<float> *multiplierVectorPtr; ///< a reference to a vector of multipliers
        Multiplier(std::vector<float> *targetVectorPtr, std::vector<float> *multiplierVectorPtr):UnitGenerator(targetVectorPtr){
            Multiplier::multiplierVectorPtr = multiplierVectorPtr;
        }; 
        virtual void performDSP();
    };

    inline void Multiplier::performDSP(){
        for(int i = 0; i < vectorSize; i++){
            (*targetVectorPtr)[i] *= (*multiplierVectorPtr)[i];
        }
    }
}

#endif
