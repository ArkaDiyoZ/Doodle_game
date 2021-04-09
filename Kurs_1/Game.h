#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"functions.h"
#include<string>
#include<SDL_ttf.h>

class Game
{
public:
	virtual bool run() = 0;
	virtual int handle()=0;
};