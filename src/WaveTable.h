/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef WaveTable_h
#define WaveTable_h

#include <cmath>
#include "Const.h"
#include "Oscillator.h"
#include "Interpolation.h"

namespace AngrySparrow {
    
    /**
     * @brief a wavetable oscillator. The size of the table can not be varied after the initialization.
     */
    class WaveTable : public Oscillator, public Interpolation{

    public:      
        WaveTable(std::vector<float> *tvp, std::vector<float> *fvp, std::vector<float> *tbp, float ip = 0.0 ):Oscillator(tvp, fvp, ip), Interpolation(tbp){};

        virtual void performDSP();
    };

    inline void WaveTable::performDSP(){
		for (int i = 0; i < vectorSize; i++) {
            (*targetVectorPtr)[i] = interpolate(phase);
            advancePhase((*frequencyVectorPtr)[i]);
        }
    }    
}

#endif
