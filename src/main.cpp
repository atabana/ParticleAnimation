//============================================================================
// Name        : SDL.cpp
// Author      : Ahmed
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"
using namespace std;
using namespace ahmedtabana;

int main() {

	srand(time(NULL));

	Screen screen;
	Swarm swarm;

	if(!screen.init())
	{
		cout << "error initializing SDL" << endl;
	}

	while(true)
	{

		//screen.clear();
		int elapsedTime = SDL_GetTicks();

		swarm.update(elapsedTime);
		unsigned char green =  (1 + sin(elapsedTime * 0.001)) * 128;
		unsigned char red =  (1 + sin(elapsedTime * 0.002)) * 128;
		unsigned char blue =  (1 + sin(elapsedTime * 0.003)) * 128;

		const Particle * const pParticles = swarm.getParticles();
		for( int i =0; i<Swarm::NUMOFPARTICLES; i++)
		{
			Particle particle = pParticles[i];
			int x = (particle.mXLocation + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.mYLocation  * Screen::SCREEN_HEIGHT/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red,blue,green);
		}

		// add blur
		screen.boxBlur();
		//draw particles
		screen.update();
		// check events
		if(screen.processEvents() == false)
		{
			break;
		}
	}
	screen.close();
	return 0;
}
