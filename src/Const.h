/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Const_h
#define Const_h

#include <cmath>

namespace AngrySparrow {
    const float CYCLE  (M_PI * 2);
    const float HALF_RAND_MAX (RAND_MAX /2 );
    const int sampleRate = 44100;
    const int vectorSize = 256;
    float sampleToSecond(unsigned long sample); ///< convert sample to second
    unsigned long secondToSample(); ///< convert second to sample

	inline float sampleToSecond(unsigned long sample){
		return static_cast<float>(sample) / static_cast<float>(sampleRate);
	}

	inline unsigned long secondToSample(float second){
		return static_cast<unsigned long>(second * static_cast<float>(sampleRate));
	}

	inline std::vector<float> allocVector(float fill){
		std::vector<float> vec;
		vec.assign(vectorSize, fill);
		return vec;
	}

}

#endif
