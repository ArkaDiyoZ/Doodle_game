#pragma once
#include"Game.h"
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"functions.h"
#include<string>
#include"Texture_manage.h"

class ArgsLoader
{
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	string m_texture;
public:
	ArgsLoader(int x, int y, int width, int height, string	texture);
	int const getX();  
	int const getY(); 
	int const getWidth();
	int const getHeight(); 
	string const getTexture(); 

};
