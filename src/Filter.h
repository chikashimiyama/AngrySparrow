/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Filter_h
#define Filter_h

#include <cmath>
#include "Const.h"

namespace AngrySparrow {
    
    /**
     * @brief the subclasses of Modifier, processes provided target vector.
     * it does not copy any samples and distructively change the content of vector.
     * This class cannot be instantiated without specifying the target Vector pointer
     */
    class Filter{
    protected:
        std::vector<float> *targetVectorPtr;

    public:
        Filter(std::vector<float> *targetVectorPtr);
        void setTargetVectorPtr(std::vector<float> *targetVectorPtr);

        virtual void performDSP() = 0;
    };

    inline Filter::Filter(std::vector<float> *targetVectorPtr){
        Filter::targetVectorPtr = targetVectorPtr;
    }

    /**
     * @brief adding operand to the signal operand vector
     */
    class Adder : public Filter{
    protected:
        std::vector<float> *adderVectorPtr;

    public:

        Adder(std::vector<float> *targetVectorPtr, std::vector<float> *adderVectorPtr);
        void setAdderVectorPtr(std::vector<float> *adderVectorPtr);
        void performDSP();
    };

    inline Adder::Adder(std::vector<float> *targetVectorPtr, std::vector<float> *adderVectorPtr): Filter(targetVectorPtr){
        setAdderVectorPtr(adderVectorPtr);
    }

    inline void Adder::setAdderVectorPtr(std::vector<float> *adderVectorPtr){
        Adder::adderVectorPtr = adderVectorPtr;
    }

    inline void Adder::performDSP(){
        for(int i = 0; i < vectorSize; i++){
            (*targetVectorPtr)[i] += (*adderVectorPtr)[i];
        }
    }


    // /**
    //  * @brief multiplying target signal vector with multiplier vector
    //  */
    // class Multiplier : public Filter{
    // protected:
    //     std::vector<float> *multiplierVectorPtr;
    //     void setMultiplierVectorPtr(std::vector<float> *multiplierVectorPtr);

    // public:
    //     void performDSP();
    // };

    // inline void Multiplier::setMultiplierVectorPtr(std::vector<float> *multiplierVectorPtr){
    //     Multiplier::multiplierVectorPtr = multiplierVectorPtr;
    // }

    // inline void Multiplier::performDSP(){
    //     for(int i = 0; i < vectorSize; i++){
    //         (*targetVectorPtr)[i] += (*multiplierVectorPtr)[i];
    //     }
    // }
}

#endif
