/**
 * @ingroup AngrySparrow
 * @authors Chikashi Miyama
 */

#ifndef DSP_h
#define DSP_h

#include "UnitGenerator.h"

namespace AngrySparrow{

	/**
	 * @brief manages all object that generate/process sound in an vector of UnitGenerator* 
	 */
	class DSP {
 	private:
 		std::vector<UnitGenerator*> dspChain;

 	public:
 		void addToChain(UnitGenerator* unitGenerator); ///< add a subclass of unit generator 
 		bool removeFromChain(UnitGenerator* unitGenerator); ///< return false if not found in the chain

 		void run(); ///< execute performDSP() of all registered unit generators.
	};

	inline void DSP::addToChain(UnitGenerator* unitGenerator){
		dspChain.push_back(unitGenerator);
	}

	inline bool DSP::removeFromChain(UnitGenerator* unitGenerator){
		std::vector<UnitGenerator*>::iterator it = dspChain.begin();
		while(it != dspChain.end()){
			if(unitGenerator == *it){
				dspChain.erase(it);
				return true;
			}
			it++;
		}
		return false;
	}

	inline void DSP::run(){
		std::vector<UnitGenerator*>::iterator it = dspChain.begin();
		while(it != dspChain.end()){
			(*it)->performDSP();
			it++;
		}
	}

}

#endif
