/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef LowPass_h
#define LowPass_h

#include <cmath>
#include "Const.h"
#include "UnitGenerator.h"

 namespace AngrySparrow {
    
    /**
     * @brief 1st oreder butterworth filter
     */
     class LowPass: public UnitGenerator{
     protected:
        float z;
        std::vector<float> *cutoffVectorPtr; ///< a reference to a vector of frequencies

    public:
        /// constructor that invokes the constructor of the superclass
        LowPass(std::vector<float> *tvp, std::vector<float> *cutoffv) : UnitGenerator(tvp), cutoffVectorPtr(cutoffv){
            z = 0.0;
        };
        
        virtual void performDSP();

    };

    inline void LowPass::performDSP(){
        for(int i = 0; i < vectorSize; i++){
            
            double costh, coef;
            float input = (*targetVectorPtr)[i];
            float cutoff = (*cutoffVectorPtr)[i];
            costh = 2.0 - cos(2 * CYCLE * cutoff/sampleRate);
            coef = sqrt(costh*costh - 1.0) - costh;
            z = static_cast<float>(input * (1+coef) - z*coef);
            (*targetVectorPtr)[i] = z;
        }
    }
}
#endif
