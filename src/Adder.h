/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Adder_h
#define Adder_h

#include <cmath>
#include "Const.h"
#include "UnitGenerator.h"
 
namespace AngrySparrow {

    /**
     * @brief adding operand to the signal operand vector
     */
    class Adder : public UnitGenerator{

    public:
        std::vector<float> *adderVectorPtr; ///< a reference to a vector of adders
        Adder(std::vector<float> *targetVectorPtr, std::vector<float> *adderVectorPtr):UnitGenerator(targetVectorPtr){
            Adder::adderVectorPtr = adderVectorPtr;
        }; 
        virtual void performDSP();
    };

    inline void Adder::performDSP(){
        for(int i = 0; i < vectorSize; i++){
            (*targetVectorPtr)[i] += (*adderVectorPtr)[i];
        }
    }
}

#endif
