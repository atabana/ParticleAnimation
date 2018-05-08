/*
 * Swarm.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: Ahmed
 */

#include "Swarm.h"

namespace ahmedtabana {

Swarm::Swarm() : lastTime(0){
	mParticles = new Particle[NUMOFPARTICLES];
}

Swarm::~Swarm() {
	delete [] mParticles;
}

void Swarm::update(int timeElapsed)
{
	int interval = timeElapsed - lastTime;
	for( int i =0; i<Swarm::NUMOFPARTICLES; i++)
	{
		mParticles[i].update(interval);
	}
	lastTime = timeElapsed;
}

} /* namespace ahmedtabana */
