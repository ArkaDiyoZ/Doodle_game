#include "Doodle.h"
#include<iostream>
#include"functions.h"
#include"Game.h"
#include<random>
#include<ctime>
#include<SDL_ttf.h>
#include<fstream>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
random_device rd;
mt19937_64 gen(rd());
uniform_int_distribution<unsigned long long> dis;
using namespace std;


Doodle::Doodle(SDL_Renderer* ren, int titlesize, SDL_Window * m_pWindow, int SCREEN_WIDTH, int SCREEN_HEIGHT,int hard,int easy)
{
	
	this->m_pWindow = m_pWindow;
	this->SCREEN_HEIGHT = SCREEN_HEIGHT;
	this->SCREEN_WIDTH = SCREEN_WIDTH;
	this->titlesize = titlesize;
	hell = hard;
	heaven = easy;
	if (heaven) 
	{
	back = loadimage_png("star.png", ren);
	dood = loadimage_png("dudle_yel.png", ren);
	path = "dudle_yel.png";
	path_r = "dudle_yel_z.png";
	cout << heaven << "- level" << endl;
	}
	else if (hell) 
	{
		back = loadimage_png("gr.png", ren);
		dood = loadimage_png("dudle_g.png", ren);
		path = "dudle_g.png";
		path_r = "dudle_g_z.png";
		cout << hell << "- level" << endl;
	}
	m_bRunning = true;
	ret = false;
	y_temp = 0;
	flag_death = 0;
	flag_death_true = 0;
	if (heaven)pl_count = 10;
	if(hell)pl_count = 6;
	h = 100;
	dx = 0;
	dy = 0;
	score_ptr=0;
	this->ren = ren;
	del_dud = 11;
	x = 200;
	y = 700;
	speed = 0;
	tte = 0;
	srand(time(NULL));
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<unsigned long long> dis;
	int *randomDigits_x = new int[pl_count];
	int *randomDigits_y = new int[pl_count];
	int *randomDigits_temp = new int[pl_count];
	// 100, 200,345,425,150,235,123,80,360,503,371,520,189,156,436 
	//100, 200, 345,425,640,235,123,80,360,503,371,568,623,156,436
	//int *pl_masx = new int[15]{};
	//int *pl_masy = new int[15]{};

	plate_co = new pl_c[pl_count];
	int point;
	for (int i = 0; i < pl_count; i++)
	{
		randomDigits_y[i] = 100 + dis(gen) % 700; //10000000  ... 99999999
		randomDigits_x[i] = 99 + dis(gen) % 420;
		randomDigits_temp[i] = 99 + dis(gen) % 420;
		plate_co[i].p_str_x = randomDigits_x[i];
		cout << "plate_co[" << i << "].p_str_x - " << plate_co[i].p_str_x << endl;
		plate_co[i].p_str_y = randomDigits_y[i];
		cout << "plate_co[" << i << "].p_str_y - " << plate_co[i].p_str_y << endl;
		point = 0;
		for (int j = i; j < pl_count; j++)
		{
			if (plate_co[i].p_str_x+57 == plate_co[j].p_str_x+ 57 && i != j)
			{
				point = 1;
				plate_co[i].p_str_x = randomDigits_temp[i];
				cout << "plate_co[" << i << "].p_str_x  was chandged - " << plate_co[i].p_str_x << endl;
			}
		}
		if (point == 0)
		{
			if (hell)
			{
				plate_co[i].pl = loadimage_png("PL3.png", ren);
			}
			if (heaven) 
			{
				plate_co[i].pl = loadimage_png("PL4.png", ren);
			}
	
		
		}
	
	}
	cout << "DOODLE const with arguments " << endl;

}

void Doodle::render()
{
	SDL_RenderClear(ren); // clear the renderer to the draw color	
	
	//print_surface(back, ren, SCREEN_WIDTH, SCREEN_HEIGHT, titlesize);
	
	ApplySurface(0,0, back, ren);
	
	for (int i = 0; i < pl_count; i++)
	{
		ApplySurface(plate_co[i].p_str_x, plate_co[i].p_str_y, plate_co[i].pl, ren);
	}
	score(); 
	ApplySurface(x, y, dood, ren);

	if (flag_death_true == true) 
	{
		
		SDL_RenderClear(ren);
		ApplySurface(0, 0, back, ren);
		death_paint();
	}
	//SDL_RenderCopy(ren, dood, NULL, NULL);
	SDL_RenderPresent(ren); // draw to the screen
}

void Doodle::move()
{
	 m_bRunning = true;
	// x+= speed;
	 //mCollider.x = x;
	 dx = 10.2;
	SDL_Event e;
	// Флаг выхода
	bool quit = false;
	int grav=30;
	
	while (SDL_PollEvent(&e))
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			quit = true;
			m_bRunning = false;
		}
		//User presses a key
		else if (e.type == SDL_KEYDOWN)
		{
			//Select surfaces based on key press
			switch (e.key.keysym.sym)
			{
			case SDLK_SPACE:
				y_temp = y;
				cout << "ytem" << y_temp << endl;
				set_ret(true);
				break;

			case SDLK_d:
				dood = loadimage_png(path, ren);
				x +=dx;
				break;

			case SDLK_a:
				dood = loadimage_png(path_r, ren);
				x -= dx;
				break;
			case SDLK_ESCAPE: 
			{
				system("Pause");
			}
				break;
			}
		}
	}
}

bool Doodle::run()
{
	return m_bRunning;

}

int Doodle::handle()
{
	return 0;
}

void Doodle::set_y(int num)
{

	SDL_Rect a;
	SDL_Rect b;
	a.x = x;
	a.y = y;
	SDL_QueryTexture(dood, NULL, NULL, &a.w, &a.h);
	int *randomDigits_temp = new int[pl_count];
	if (num)
	{
		dy += 0.2;
		y += dy;
		if (y > 700)
		{
			dy = -11;	
		}
	}
	
	if (y < h) 
	{
		 tte++;
		_itoa(tte, p, 10);
		for (int i = 0; i < pl_count; i++)
		{
			randomDigits_temp[i] = 99 + dis(gen) % 420;
			y = h;
			plate_co[i].p_str_y = plate_co[i].p_str_y-dy;
			if (plate_co[i].p_str_y > 800)
			{
				if(heaven)plate_co[i].p_str_y = 20;
				if(hell)plate_co[i].p_str_y = 20;
				plate_co[i].p_str_x = randomDigits_temp[i];

			}

		}
	}
	for (int i = 0; i < pl_count; i++)
	{

	/*SDL_QueryTexture(plate_co[i].pl, NULL, NULL, &b.w, &b.h);
	//b.x = plate_co[i].p_str_x;
	//b.y = plate_co[i].p_str_y;
	//b.w = plate_co[i].width;
	//b.h = plate_co[i].height;
	*/
		if ((x + 50 > plate_co[i].p_str_x) && (x + 20 < plate_co[i].p_str_x + 68) && (y + 70 > plate_co[i].p_str_y) && (y + 70 < plate_co[i].p_str_y + 14) && (dy > 0))
		{
			flag_death = true;
			//cout << "true" << endl;
			dy = -11;
		}
	//	if(SDL_HasIntersection(&a,&b))
	}
	//set_ret(false);
	/*int gr = 25;
	if (num < gr) 
	{
		cout << "num > 25 - " << num << endl;
		y = y - num;
		cout << "y - " <<y << endl;
	}
	if (num > gr)
	{
		cout << "num > 25 - " << num << endl;
		y = y - num;
		cout << "y - " << y << endl;
		set_ret(false);	
		if (y == y_temp);
	}
	*/
	if (y > 680 && flag_death == true) 
	{

		set_fl_death(true);

		//death(); 
	};
	/*    
	if (num > 25) 
	{
		y = y + 5;
		num = 0;
		y = 0;
		cout << "num > 25 - " << num << endl;
	}
*/
	
}

int Doodle::get_y()
{
	return y;

}

void Doodle::score()
{
	TTF_Font* fon;
	if (fon = TTF_OpenFont("pix.ttf", 40))
	{
	//	cout << "font - load +" << endl;
	}
	else
	{
		cout << "font was cracked" << endl;
	}

	char temp[15];
	int t = 0;
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface *textSurface = TTF_RenderText_Solid(fon, "SCORE:", color);
	SDL_Texture *text = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_Rect textRect;
	textRect.x = textRect.y = 0;

	//_itoa(tte, p, 10);
	SDL_Color color_1 = { 255, 255, 255, 255 };
	SDL_Surface *textSurface_1 = TTF_RenderText_Solid(fon, p, color);
	SDL_Texture *text_1 = SDL_CreateTextureFromSurface(ren, textSurface_1);
	SDL_Rect textRect_1;
	textRect_1.x =180; textRect_1.y = 0;
	
	//	t=10;
	//	sprintf_s(temp, " %d ", t);

	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(ren, text, NULL, &textRect);

	SDL_QueryTexture(text_1, NULL, NULL, &textRect_1.w, &textRect_1.h);
	SDL_RenderCopy(ren, text_1, NULL, &textRect_1);
	
	
	SDL_FreeSurface(textSurface);
	textSurface = nullptr;
}

void Doodle::death()
{
	flag_death_true = true;

}

void Doodle::death_paint()
{
	char temp[80];
	int t_score;
	t_score = tte;

	set_fl_fl(2);

	TTF_Font* fon;
	if (fon = TTF_OpenFont("pix.ttf", 40))
	{
		//	cout << "font - load +" << endl;
	}
	else
	{
		cout << "font was cracked" << endl;
	}

	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface *textSurface = TTF_RenderText_Solid(fon, "YOU DIED", color);
	SDL_Texture *text = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_Rect textRect;
	textRect.x = textRect.y = 0;

	SDL_Color color_1 = { 255, 255, 255, 255 };
	SDL_Surface *textSurface_1 = TTF_RenderText_Solid(fon, p, color_1);
	SDL_Texture *text_1 = SDL_CreateTextureFromSurface(ren, textSurface_1);
	SDL_Rect textRect_1;
	textRect_1.x = 360; textRect_1.y = 0;

	SDL_Color color_2 = { 255, 100, 100, 100 };
	SDL_Surface *textSurface_2 = TTF_RenderText_Solid(fon,"YOUR SCORE :", color);
	SDL_Texture *text_2 = SDL_CreateTextureFromSurface(ren, textSurface_2);
	SDL_Rect textRect_2;
	textRect_2.x = 0; textRect_2.y = 120;

	SDL_Color color_3 = { 255, 255, 255, 255 };
	SDL_Surface *textSurface_3 = TTF_RenderText_Solid(fon, "PRESS SPASCE BUTONN", color_3);
	SDL_Texture *text_3 = SDL_CreateTextureFromSurface(ren, textSurface_3);
	SDL_Rect textRect_3;
	textRect_3.x = 0; textRect_3.y =520;
	
	//	t=10;
	//	sprintf_s(temp, " %d ", t);

	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(ren, text, NULL, &textRect);

	SDL_QueryTexture(text_1, NULL, NULL, &textRect_1.w, &textRect_1.h);
	SDL_RenderCopy(ren, text_1, NULL, &textRect_1);


	SDL_QueryTexture(text_2, NULL, NULL, &textRect_2.w, &textRect_2.h);
	SDL_RenderCopy(ren, text_2, NULL, &textRect_2);


	SDL_QueryTexture(text_3, NULL, NULL, &textRect_3.w, &textRect_3.h);
	SDL_RenderCopy(ren, text_3, NULL, &textRect_3);
	set_sc(tte);
	
	//set_fl_death(true);
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_QUIT)
		{
			//quit = true;
			m_bRunning = false;
		}
		else if (ev.type == SDL_KEYDOWN)
		{
			//Select surfaces based on key press
			switch (ev.key.keysym.sym)
			{
			case SDLK_SPACE :
				cout << "death_paint " << endl;
				set_fl_fl(2);
				m_bRunning = false;
				break;
			}
		}
	}

	SDL_FreeSurface(textSurface);
	textSurface = nullptr;
	//m_bRunning = false;
	//return 1;
}

Doodle::~Doodle()
{
	std::cout << "cleaning game" << endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(ren);
	cout << "Doodle  destroyed" << endl;
	SDL_Quit();
	
}
