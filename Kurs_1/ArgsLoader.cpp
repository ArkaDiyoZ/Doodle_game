#include"ArgsLoader.h"
#include"Game.h"
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"functions.h"
#include<string>
#include"Texture_manage.h"

ArgsLoader::ArgsLoader(int x, int y, int width, int height, string texture)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_texture = texture;
}

int const ArgsLoader::getX()
{
	return m_x;
}

int const ArgsLoader::getY()
{
	return m_y;
}

int const ArgsLoader::getWidth()
{
	return m_width;
}

int const ArgsLoader::getHeight()
{
	return m_height;
}

string const ArgsLoader::getTexture()
{
	return m_texture;
}
