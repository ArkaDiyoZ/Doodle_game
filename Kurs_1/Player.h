#pragma once

#include"GameObj.h"
#include"Game.h"
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"functions.h"
#include<string>
#include"Texture_manage.h"

class Player: public GameObject
{
private:
//	SDL_Renderer *ren;
	TextureManager m_textureManager_1;
	SDL_Scancode keys[4];
	int moveSpeed;
	bool isActive;
public:
	Player(); //по умолчанию
	Player(int,int,int,int,string, SDL_Renderer*);
	void handle_events(SDL_Renderer*);
	virtual void update();
	 void draw(SDL_Renderer*);
	~Player();

};

