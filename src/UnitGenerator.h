/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */
 
#ifndef UnitGenerator_h
#define UnitGenerator_h

#include <iostream>

namespace AngrySparrow {
    
    /**
     * @brief abstract class of all sound processor/generators
     * @details This class takes a pointer to a vector which will be filled with outgoing signal of subclasses. However, this class do not have a functionality to allocate memory to the vector. Thus, it is the responsibility of users to allocate appropriate memory before the passing a pointer to this class, or more precisely the instantiation of this class.
     */
    class UnitGenerator{
    protected:
        std::vector<float> *targetVectorPtr; ///< pointer to the vector, which the result of DSP will be stored. Should be bigger than the vector size.
        
    public:
        UnitGenerator(std::vector<float> *tvp): targetVectorPtr(tvp){}; ///< constructor. The reference must be provided here.
        virtual void performDSP() = 0; ///< pure abstract function for DSP. should be implemented in all subclasses
    };
}

#endif
