/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Play_h
#define Play_h

#include "Interpolation.h"
#include "UnitGenerator.h"

namespace AngrySparrow {

	/**
	 * @brief playback a vector using a position vector
	 * 
	 */
	class Play: public Interpolation, public UnitGenerator{
	protected:
		std::vector<float> *positionVectorPtr;

	public:

		Play(std::vector<float> *tvp, std::vector<float> *pvp, std::vector<float> *tbp):UnitGenerator(tvp), Interpolation(tbp), positionVectorPtr(pvp){};
		void performDSP();
	};

	inline void Play::performDSP(){

		for (int i = 0; i < vectorSize; i++) {
			int index = static_cast<int>((*positionVectorPtr)[i]); // implement interpolation later
			(*targetVectorPtr)[i] = (*tablePointer)[index];
        }
	}
}

#endif