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
	public:

		Envelope();
		void performDSP();

	};

	inline Envelope::Envelope(std::vector<float> values, std::std::vector<float> times){
		int numValues = values.size();
		int numTimes = times.size();
		if(numTimes == numValues - 1){
			std::cout << "Envelope: invalid number of arguments. Values:" << numValues << " Times:" << numTimes << std::endl; 
			return;
		}
		unsigned long totalSamps = 0;
		std::vector<float>::iterator it = times.begin();
		std::vector<unsigned long> timesInSamps;
		while(it != times.end()){
			float tm = *it;
			unsigned long numSamps = secondToSample(tm);
			timeSamps.push_back(numSamps);
			totalSamps += numSamps;
		}
		envelope.reserve(totalSamps);
		unsigned long envCount = 0;
		for(int i = 0; i < numTimes; i++){
			float dif = values[i+1] - values[i];
			unsigned long numSamps = timesInSamps[i];
			float step = dif / static_cast<float>(numSamps); // unsafe
			for(int i = 0; i < numSamps; i++){
				envelope[envCount++] = values[i] + step;
			}
		}
	}
}
#endif