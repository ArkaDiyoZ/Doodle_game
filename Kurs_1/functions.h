#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <iostream>
#include <string>
#include <SDL_image.h>
#include<string>
using namespace std;

bool init();
void renderTexture_mas(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
void renderTexture_nomas(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
SDL_Texture* loadimage_png(const std::string &file, SDL_Renderer *ren);
SDL_Texture* Loadimage_bmp(string file, SDL_Window *win, SDL_Renderer *ren);
void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
void print_surface(SDL_Texture *background, SDL_Renderer *ren, int screen_width, int screen_heigth, int title_size);
void nps_walk(int x, int y);
void destr_end(SDL_Texture *background, SDL_Renderer *ren, SDL_Window *win);
void QuickSort(int *mass, int n);
void res_pr(SDL_Renderer *ren, int res, int xpos, int ypos, int xpos_1, int ypos_1);