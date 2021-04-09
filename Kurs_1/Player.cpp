#include "Player.h"
#include"GameObj.h"
#include"Game.h"
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"functions.h"
#include<string>
#include"Texture_manage.h"

//Scanner(int scanner, int power): PoweredDevice(power)
Player::Player() 
{
	m_x = 0;
	m_y = 0;
	m_width = 0;
	m_height = 0;
	m_texture = "gg.png";
	m_currentFrame_1 = 0;
	keys[0] = SDL_SCANCODE_W;
	keys[1] = SDL_SCANCODE_S;
	keys[2] = SDL_SCANCODE_A;
	keys[3] = SDL_SCANCODE_D;
	moveSpeed = 30;
	isActive = false;
	//m_textureManager_1.load(m_texture, ren);

}
Player::Player(int x, int y, int width, int height, string texture,SDL_Renderer* ren)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	this->m_texture = texture;
	m_currentFrame_1 = 0;
	keys[0] = SDL_SCANCODE_W;
	keys[1] = SDL_SCANCODE_S;
	keys[2] = SDL_SCANCODE_A;
	keys[3] = SDL_SCANCODE_D;
	moveSpeed = 30;
	isActive = false;

	m_textureManager_1.load(m_texture, ren);
}
void Player::handle_events(SDL_Renderer*ren)
{
	SDL_Event e;
	SDL_Rect r;
	int v = 4, v2 = 5;//скорость движения
	
		SDL_PollEvent(&e);
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_w) {
					m_y -= v;
					m_textureManager_1.load("gg_high.png", ren);
	
				}
				if (e.key.keysym.sym == SDLK_s) {
					m_y += v;
					m_textureManager_1.load("gg.png", ren);
				}
				if (e.key.keysym.sym == SDLK_d) {
					m_x += v;
					m_textureManager_1.load("gg_right.png", ren);
				}
				if (e.key.keysym.sym == SDLK_a) {
					m_x -= v;
					m_textureManager_1.load("gg_left.png", ren);

				}
			}

}
void Player::update()
{
	m_currentFrame_1 = int(((SDL_GetTicks() / 100) % 2));
}

void Player::draw(SDL_Renderer*ren)
{
	SDL_RenderClear(ren); // clear the renderer to the draw color
	m_textureManager_1.draw(30, 70, 160, 240, ren);
	m_textureManager_1.drawFrame(30, 299, 160, 240, 1, m_currentFrame_1, ren);
	//SDL_RenderCopy(m_pRenderer, m_pTexture, NULL,NULL);
	//SDL_RenderClear(m_pRenderer);
	// pass in the horizontal flip
	SDL_RenderPresent(ren); // draw to the screen
}


Player::~Player()
{
}
