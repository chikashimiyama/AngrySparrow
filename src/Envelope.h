/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef Envelope_h
#define Envelope_h

#include "Interpolation.h"
#include "UnitGenerator.h"

namespace AngrySparrow {

	class Envelope: public Interpolation, public UnitGenerator{

	protected:
		std::vector<float> envelope;
		bool noteOn;
	public:
		static std::vector<float> createADSR(float attack, float decay, float sustainLevel, float release);

		Envelope();
		Envelope(float attack, float decay, float sustainLevel, float release);
		void performDSP();

	};


	inline static Envelope::createADSR(float attack, float decay, float sustainLevel, float release){

		unsigned long attackInSamps = secondToSamps(attack);
		unsigned long decayInSamps = secondToSamps(decay);
		unsigned long releaseInSamps = secondToSamps(release);
		unsigned long total = attackInSamps + decayInSamps + releaseInSamps;

		std::vector<float> envelope(total);
		unsigned long cnt = 0;
		for (int i = 0; i < attackInSamps; i++){
			envelope[cnt++] = static_cast<float>(i) / static_cast<float>(attackInSamps);
		}
		float gap = 1.0 - sustainLevel;
		for (int i = 0; i < decayInSamps; i++){
			envelope[cnt++] = 1.0 - gap * (static_cast<float>(i) / static_cast<float>(attackInSamps));
		}
		for (int i = 0; i < releaseInSamps; i++){
			envelope[cnt++] =
		}
	}

	inline Envelope::Envelope(){

	}

	inline Envelope::Envelope(float attack, float decay, float sustainLevel, float release){
		createADSR(attack, decay, sustainLevel, release);
	}

}
#endif