/*
 * Screen.h
 *
 *  Created on: Apr 22, 2018
 *      Author: Ahmed
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
namespace ahmedtabana {

class Screen {

public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Renderer * mRenderer;
	SDL_Texture * mTexture;
	SDL_Window * mWindow;
	Uint32 * mBuffer1;
	Uint32 * mBuffer2;


public:
	Screen();
	virtual ~Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 blue, Uint8 green);
	void close();
	void clear();
	void boxBlur();
	bool processEvents();
};

} /* namespace ahmedtabana */

#endif /* SCREEN_H_ */
