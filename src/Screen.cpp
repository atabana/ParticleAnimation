/*
 * Screen.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: Ahmed
 */

#include "Screen.h"

namespace ahmedtabana {

Screen::Screen() :
		mRenderer(NULL),
		mTexture(NULL),
		mWindow(NULL),
		mBuffer1(NULL),
		mBuffer2(NULL)

{

}

Screen::~Screen() {
}

bool Screen::init() {

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return false;
	}


	mWindow = SDL_CreateWindow("Particle Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(mWindow == NULL)
	{
		return false;
	}

	 mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	 mTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if(mRenderer == NULL)
	{
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}
	if(mTexture == NULL)
	{
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	mBuffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	mBuffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(mBuffer1, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(mBuffer2, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	return true;

}
void Screen::close() {
	SDL_Delay(5000);
	delete [] mBuffer1;
	delete [] mBuffer2;

	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyTexture(mTexture);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}
void Screen::setPixel(int x, int y, Uint8 red, Uint8 blue, Uint8 green)
{
	if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
	{
		return;
	}
	Uint32 color = 0;
	const int byte = 8;

	color += red;
	color <<= byte;
	color += blue;
	color <<= byte;
	color += green;
	color <<=byte;
	color += 0xFF;

	mBuffer1[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::update() {
	SDL_UpdateTexture(mTexture, NULL, mBuffer1, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(mRenderer);
	SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
	SDL_RenderPresent(mRenderer);
}
void Screen::clear() {
	memset(mBuffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(mBuffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

}
void Screen::boxBlur() {
	Uint32 * temp;
	temp = mBuffer1;
	mBuffer1 = mBuffer2;
	mBuffer2 = temp;
	const int byte = 8;
	for (int y = 0; y < SCREEN_HEIGHT ; y ++)
		for(int x = 0; x < SCREEN_WIDTH; x++)
		{
			/*
			 * 0 0 0
			 * 0 1 0
			 * 0 0 0
			 */
			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for(int row= -1 ; row <=1; row++)
				for(int col = -1; col <= 1; col++ )
				{
					int currentY = y + row;
					int currentX = x + col;

					if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT)
					{
						Uint32 color = mBuffer2[ currentY * SCREEN_WIDTH + currentX];
						// get pixel color

						// RGBA
						Uint8 red = color >> byte * 3;
						Uint8 green = color >> byte * 2;
						Uint8 blue = color >> byte;
						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}

				}
			Uint8 red = redTotal/9;
			Uint8 green = greenTotal/9;
			Uint8 blue = blueTotal/9;

			setPixel(x, y, red, green, blue);

		}


}
bool Screen::processEvents() {
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			return false;
		}
	}
	return true;
}
} /* namespace ahmedtabana */
