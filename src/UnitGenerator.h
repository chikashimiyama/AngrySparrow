/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef UnitGenerator_h
#define UnitGenerator_h

#include <iostream>

namespace AngrySparrow {
    
    /**
     * @brief abstract class for DSP
     */
    class UnitGenerator{
    protected:
        std::vector<float> *targetVectorPtr; ///< pointer to the vector, which the result of DSP will be stored. Should be bigger than the vector size.
    public:
        UnitGenerator(std::vector<float> *targetVectorPtr); ///< constructor. The reference must be provided here.
        virtual void performDSP() = 0; ///< pure abstract function for DSP. should be implemented in all subclasses
    };

    inline UnitGenerator::UnitGenerator(std::vector<float> *targetVectorPtr){
        UnitGenerator::targetVectorPtr = targetVectorPtr;
    }
}


#endif
