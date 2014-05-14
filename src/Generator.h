/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Generator_h
#define Generator_h

#include <cmath>
#include "Const.h"

namespace AngrySparrow {
    
    /**
     * @brief an abstract class for all signal generators, that offers scaling functionalities.
     */
    class Generator{
    protected:
 
        std::vector<float> outputVector; ///< output vector
        float mul;
        float add;

        virtual void performDSP_CR() = 0; ///< abstract function for internal DSP routine for control rate
        virtual void performDSP_AR() = 0; ///< abstract function for internal DSP routine for audio rate

    public:
        Generator(float mul = 1.0, float add = 0.0); ///< constructor

        void setMul(float mul);
        float getMul();

        void setAdd(float add);
        float getAdd();
        virtual std::vector<float> getNextVector() = 0; ///< virtual abstract function for generating audio vectors. should be implmeneted in the subclasses.
    };

    inline Generator::Generator(float mul, float add){
        setMul(mul);
        setAdd(add);
    }

    inline void Generator::setMul(float mul){
        Generator::mul = mul;
    }

    inline float Generator::getMul(){
        return mul;
    }

    inline void Generator::setAdd(float add){
        Generator::add = add;
    }

    inline float Generator::getAdd(){
        return add;
    }
}

#endif
