/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Noise_h
#define Noise_h

#include <cmath>
#include "Const.h"
#include "UnitGenerator.h"
 
namespace AngrySparrow {

    /**
     * @brief white noise generator
     */
    class Noise : public UnitGenerator{

    public:
        Noise(std::vector<float> *targetVectorPtr):UnitGenerator(targetVectorPtr){};
        virtual void performDSP();
    };

    inline void Noise::performDSP(){
        for(int i = 0;i < AngrySparrow::vectorSize; i++){
            (*targetVectorPtr)[i] = static_cast <float> (rand()) / (static_cast <float> (HALF_RAND_MAX)) - 1.0;
        }
    }
}

#endif
