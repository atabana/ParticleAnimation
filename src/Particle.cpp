/*
 * Particle.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: Ahmed
 */

#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace ahmedtabana {

Particle::Particle() : mXLocation(0),mYLocation(0)
{
 init();
}

Particle::~Particle()
{
}

void Particle::init()
{
	mXLocation = 0;
	mYLocation = 0;
	mDirection = (2 * M_PI * rand())/RAND_MAX;
	mSpeed = (0.04 * rand())/RAND_MAX;
	mSpeed *= mSpeed;
}


void Particle::update(int interval)
{
	mDirection += interval * 0.0004;
	double xSpeed = mSpeed * cos(mDirection);
	double ySpeed = mSpeed * sin(mDirection);
	mXLocation += xSpeed * interval;
	mYLocation += ySpeed * interval;

	if(mXLocation < -1 || mXLocation >= 1 || mYLocation < -1 || mYLocation >= 1)
	{
		init();
	}

}

} /* namespace ahmedtabana */
