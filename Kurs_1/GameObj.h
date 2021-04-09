#pragma once
#include"Game.h"
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"functions.h"
#include<string>
#include"Texture_manage.h"
class GameObject
{
protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentFrame_1;
	string m_texture;
public:
	//virtual void draw() = 0;
	virtual void update() = 0;
	//virtual void clean() = 0;
	//virtual ~GameObject() {};
};