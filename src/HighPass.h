/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef HighPass_h
#define HighPass_h

#include <cmath>
#include "Const.h"
#include "UnitGenerator.h"

 namespace AngrySparrow {
    
    /**
     * @brief 1st oreder butterworth filter
     */
     class HighPass: public UnitGenerator{
     protected:
        float z;
        std::vector<float> *cutoffVectorPtr; ///< a reference to a vector of frequencies

    public:
        /// constructor that invokes the constructor of the superclass
        HighPass(std::vector<float> *tvp, std::vector<float> *cutoffv) : UnitGenerator(tvp), cutoffVectorPtr(cutoffv){
            z = 0.0;
        };
        
        virtual void performDSP();

    };

    inline void HighPass::performDSP(){
        for(int i = 0; i < vectorSize; i++){
            
            float costh, coef;
            float input = (*targetVectorPtr)[i];
            float cutoff = (*cutoffVectorPtr)[i];
            costh = 2.0 - cos(CYCLE * cutoff/sampleRate);
            coef = costh - sqrt(costh*costh - 1.0);
            z = (input * (1-coef) - z*coef);
            (*targetVectorPtr)[i] = z;
        }
    }
}
#endif
