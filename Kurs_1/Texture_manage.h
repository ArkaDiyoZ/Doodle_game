#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include<iostream>
#include"functions.h"
using namespace std;
class TextureManager 
{
private:
	SDL_Texture* pTexture;
public:
	TextureManager();//const 
	TextureManager(string, SDL_Renderer* );//constr with args
	bool load(string fileName,SDL_Renderer* pRenderer);//load
	void draw( int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);//draw
	void drawFrame(int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);//draw_frame
	~TextureManager();
};

