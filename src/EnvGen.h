/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef EnvGen_h
#define EnvGen_h

namespace AngrySparrow{

	class EnvGen{
	public:
		static std::vector<float> envelope(std::vector<float> *values, std::vector<float> *times);

	};


	inline std::vector<float> EnvGen::envelope(std::vector<float> *values, std::vector<float> *times){
		std::vector<float> env;
		int numValues = values->size();
		int numTimes = times->size();
		if(numTimes == numValues - 1){
			std::cout << "Play: invalid number of arguments. Values:" << numValues << " Times:" << numTimes << std::endl; 
			return env;
		}
		unsigned long totalSamps = 0;
		std::vector<float>::iterator it = times->begin();
		std::vector<unsigned long> timesInSamps;
		while(it != times->end()){
			float tm = *it;
			unsigned long numSamps = secondToSample(tm);
			timesInSamps.push_back(numSamps);
			totalSamps += numSamps;
		}
		env.reserve(totalSamps);
		unsigned long envCount = 0;
		for(int i = 0; i < numTimes; i++){
			float dif = (*values)[i+1] - (*values)[i];
			unsigned long numSamps = timesInSamps[i];
			float step = dif / static_cast<float>(numSamps); // unsafe
			for(int i = 0; i < numSamps; i++){
				env[envCount++] = (*values)[i] + step;
			}
		}
		return env;
	}
}

#endif