/*
 * Particle.h
 *
 *  Created on: Apr 22, 2018
 *      Author: Ahmed
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace ahmedtabana {

class Particle {
public:
	double mXLocation;
	double mYLocation;

private:
	double mSpeed;
	double mDirection;
	void init();
public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace ahmedtabana */

#endif /* PARTICLE_H_ */
