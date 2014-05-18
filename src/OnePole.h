/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef OnePole_h
#define OnePole_h

#include <cmath>
#include "Const.h"
#include "UnitGenerator.h"

 namespace AngrySparrow {
    
    /**
     * @brief 1st oreder butterworth filter
     */
     class OnePole: public UnitGenerator{
     protected:
        float z;
        std::vector<float> *coefVectorPtr; ///< a reference to a vector of frequencies

    public:
        /// constructor that invokes the constructor of the superclass
        OnePole(std::vector<float> *tvp, std::vector<float> *coefv) : UnitGenerator(tvp), coefVectorPtr(coefv){
            z = 0.0;
        };
        
        virtual void performDSP();

    };

    inline void OnePole::performDSP(){
        for(int i = 0; i < vectorSize; i++){
            
            float input = (*targetVectorPtr)[i];
            float coef = (*coefVectorPtr)[i];
            z = input * coef + z * (1.0 - coef);
            (*targetVectorPtr)[i] = z;
        }
    }
}
#endif
