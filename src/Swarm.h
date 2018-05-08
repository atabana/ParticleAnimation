/*
 * Swarm.h
 *
 *  Created on: Apr 22, 2018
 *      Author: Ahmed
 */

#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"

namespace ahmedtabana {

class Swarm {
public:
	const static int NUMOFPARTICLES = 1000;
private:
	Particle * mParticles;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();
	const Particle * const getParticles(){ return mParticles;}
	void update(int timeElapsed);
};

} /* namespace ahmedtabana */

#endif /* SWARM_H_ */
