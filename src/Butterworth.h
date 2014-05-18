/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Butterworth_h
#define Butterworth_h

#include <cmath>
#include "Const.h"
#include "UnitGenerator.h"

namespace AngrySparrow {
    
    /**
     * @brief 1st oreder butterworth filter
     */
    class Butterworth: public UnitGenerator{
    protected:
        std::vector<float> *cutoffFrequencyVector; ///< a reference to a vector of frequencies

    public:
        /// constructor that invokes the constructor of the superclass
        Butterworth(std::vector<float> *tvp, std::vector<float> *cfvp) : UnitGenerator(tvp), cutoffFrequencyVectorPtr(fvp){};
    };
    
     
    

}

#endif
