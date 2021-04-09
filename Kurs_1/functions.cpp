#include"functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <iostream>
#include <string>
#include <SDL_image.h>
#include<string>
#include<SDL_ttf.h>
using namespace std;

bool init()
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL init success" << endl;
		// init the window
	}
	else
	{
		cout << "SDL init fail" << endl;
		return false; // SDL init fail
	}
	cout << "init success" << endl;
	return true;
};
void renderTexture_mas(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)//рендер с масштаб
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}
void renderTexture_nomas(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)//рендер без масштаб
{
	int w, h;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	renderTexture_mas(tex, ren, x, y, w, h);
}
SDL_Texture* loadimage_png(const std::string &file, SDL_Renderer *ren)
{

	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (!texture)
	{
		std::cout << IMG_GetError(); // Можно заменить на SDL_GetError()
	}
	return texture;
}
SDL_Texture* Loadimage_bmp(string file, SDL_Window *win, SDL_Renderer *ren) {// берем текстуру
	SDL_Surface *loadedImage = nullptr;
	SDL_Texture *texture = nullptr;
	loadedImage = SDL_LoadBMP(file.c_str());
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	else
		std::cout << SDL_GetError() << std::endl;
	return texture;
}
void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend) {
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(rend, tex, NULL, &pos);
}
void print_surface(SDL_Texture *background, SDL_Renderer *ren, int screen_width, int screen_heigth, int title_size)
{
	//отрисовка фона циклом
	int bW, bH;
	bW = bH = 0;
	for (int j = 0; j < 4; j++)
	{
	 bW = 0;
		for (int i = 0; i < 3; i++)
		{
			ApplySurface(bW, bH, background, ren);
			bW = bW + 200;
		}
		bH = bH + 200;
	}
/*	int xTiles = screen_width / title_size;
	int yTiles = screen_heigth / title_size;

	for (int i = 0; i < xTiles * yTiles; ++i)
	{
		int x = i % xTiles;
		int y = i / xTiles;
		renderTexture_nomas(background, ren, x * title_size, y * title_size);
	}
 */
}
void nps_walk(int x, int y)
{


	int bW, bH;
	bW = bH = 0;
	for (int j = 0; j < 6; j++)
	{
		bW = 0;
		for (int i = 0; i < 5; i++)
		{
			y++;
			x++;
			bW = bW + 236;
		}
		bH = bH + 236;
	}


}
void destr_end(SDL_Texture *background, SDL_Renderer *ren, SDL_Window *win)
{

	SDL_DestroyTexture(background);//чистка текстуры(удаление)
	SDL_DestroyRenderer(ren);//чистка рендера(удаление)
	SDL_DestroyWindow(win);//удаление окна

}
void QuickSort(int *mass, int n)//она же сортировка Хоара
{
	int x, w, i, j;
	x = mass[n / 2];
	i = 0; j = n - 1;
	do
	{
		while (mass[i] < x) i++;
		while (x < mass[j]) j--;
		if (i <= j)
		{
			w = mass[i];
			mass[i] = mass[j];
			mass[j] = w;
			i++; j--;
		}
	} while (i < j);
	if (j > 0)
		QuickSort(mass, j + 1);
	if (i < n - 1)
		QuickSort(mass + i, n - i);
}
void res_pr(SDL_Renderer *ren,int res,int xpos,int ypos,int xpos_1,int ypos_1) 
{
	char p[100];
	TTF_Font* fon;
	if (fon = TTF_OpenFont("pix.ttf", 40))
	{
		//	cout << "font - load +" << endl;
	}
	else
	{
		cout << "font was cracked" << endl;
	}

	_itoa(res, p, 10);
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface *textSurface = TTF_RenderText_Solid(fon, "SCORE:", color);
	SDL_Texture *text = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_Rect textRect;
	textRect.x = xpos; textRect.y = ypos;

	SDL_Color color_1 = { 255, 255, 255, 255 };
	SDL_Surface *textSurface_1 = TTF_RenderText_Solid(fon, p, color);
	SDL_Texture *text_1 = SDL_CreateTextureFromSurface(ren, textSurface_1);
	SDL_Rect textRect_1;
	textRect_1.x = xpos_1; textRect_1.y = ypos_1;

	//	t=10;
	//	sprintf_s(temp, " %d ", t);

	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(ren, text, NULL, &textRect);

	SDL_QueryTexture(text_1, NULL, NULL, &textRect_1.w, &textRect_1.h);
	SDL_RenderCopy(ren, text_1, NULL, &textRect_1);


	SDL_FreeSurface(textSurface);
	textSurface = nullptr;

}