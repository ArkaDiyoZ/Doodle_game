#include "menu.h"
#include"functions.h"
#include<SDL_events.h>
#include<fstream>
using namespace std;

menu::menu(SDL_Renderer* ren, int titlesize, SDL_Window * m_pWindow, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	this->ren = ren;
	this->win = m_pWindow;
	this->SCREEN_HEIGHT = SCREEN_HEIGHT;
	this->SCREEN_WIDTH = SCREEN_WIDTH;
	this->titlesize = titlesize;
	res_count = 0;

	ifstream input("records.txt");
	int ch;
	while (input >> ch)res_count++;
	cout << "nums in file : " << res_count << endl;
	//input.close();

	results = new int[res_count];
	for (int i = 0; i < res_count; i++)results[i] = 0;
	ifstream file("records.txt");
	for (int i = 0; i < res_count; i++) 
	{
		file >> results[i];
		cout << results[i] << endl;
	}
	
	last_1 = results[res_count-1];
	last_2 = results[res_count-2];
	last_3 = results[res_count-3];
	m_bRunning = true;
	flag_vvod = false;
	flag_ch = 0;
	x = 0;
	y = 0;
	x_rul =40;
	y_rul =100;
	x_start = 40;
	y_start = 250;
	x_list = 40;
	y_list = 400;
	e_x = 40;
	e_y = 550;
	flag_rule = 0;
	flag_vvod = 0;
	flag_game = 0;
	rtx = 0;
	rty = 250;
	back_menu = loadimage_png("back_menu.png", ren);
	rule = loadimage_png("rule.png", ren);
	but_start = loadimage_png("start_1.png", ren);
	List = loadimage_png("lead.png", ren);
	ex = loadimage_png("ex.png", ren);
	rl_tx = loadimage_png("rtx.png", ren);
	chose = loadimage_png("Scen_ch.png", ren);
	cout<<"menu constructor "<<endl;
}


void menu::render()
{
	SDL_RenderClear(ren);
	print_surface(back_menu, ren, SCREEN_WIDTH, SCREEN_HEIGHT, titlesize);
	ApplySurface(x_rul,y_rul,rule,ren);
	ApplySurface(x_start, y_start, but_start, ren);
	ApplySurface(x_list, y_list, List, ren);
	ApplySurface(e_x, e_y, ex, ren);
	SDL_RenderPresent(ren);
}

bool menu::run()
{
	return m_bRunning;
}

int menu::handle()
{

	bool quit = false;

	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
			m_bRunning = false;
		}
		 else if (e.type == SDL_KEYDOWN)
		 {
			//Select surfaces based on key press
			switch (e.key.keysym.sym)
			{
			case SDLK_1:
				cout << "pravila " <<endl;
				SDL_RenderClear(ren);
				rule_ins();
				break;
			case SDLK_2:
				cout << "start" << endl;
				SDL_RenderClear(ren);
				set_fl_vvod(true);
				//start();
				//m_bRunning = false;
				break;
			case SDLK_3:
				cout << "scores" << endl;
				SDL_RenderClear(ren);
				lead_print();
				break;
			case SDLK_4:
				cout << "vihod" << endl;
				exit(0);
				break;
			case SDLK_r:
				cout << "back" << endl;
				render();
				break;
			}
		 }

	}

}

void menu::start() 
{
	SDL_RenderClear(ren);
	print_surface(back_menu, ren, SCREEN_WIDTH, SCREEN_HEIGHT, titlesize);
	ApplySurface(0, 0, chose, ren);
	SDL_RenderPresent(ren);

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
			case SDLK_1:
				cout << "easy " << endl;
				set_ch(1);
				m_bRunning = false;
				break;
			case SDLK_2:
				cout << "hardcore" << endl;
				set_ch(2);
				m_bRunning = false;
				//set_ch(1);
				break;
			case SDLK_r:
				handle();
				break;
			}
		}
	}

	

}; 

void menu::vvod()
{
	SDL_RenderClear(ren);
	print_surface(back_menu, ren, SCREEN_WIDTH, SCREEN_HEIGHT, titlesize);
	//vvod();
	

	TTF_Font* fon;
	if (fon = TTF_OpenFont("pix.ttf", 40))
	{
		//	cout << "font - load +" << endl;
	}
	else
	{
		cout << "font was cracked" << endl;
	}

	int t = 0;
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface *textSurface = TTF_RenderText_Solid(fon, "Enter player's name:", color);
	SDL_Texture *text = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_Rect textRect;
	textRect.x = 15; textRect.y = 40;
	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(ren, text, NULL, &textRect);

	


}

void menu::rule_ins()
{

	SDL_RenderClear(ren);
	print_surface(back_menu, ren, SCREEN_WIDTH, SCREEN_HEIGHT, titlesize);
	ApplySurface(rtx, rty, rl_tx, ren);
	
	SDL_RenderPresent(ren);	
}


void menu::lead_print()
{
	SDL_RenderClear(ren);
	print_surface(back_menu, ren, SCREEN_WIDTH, SCREEN_HEIGHT, titlesize);

	TTF_Font* fon;
	if (fon = TTF_OpenFont("pix.ttf", 40))
	{
		//	cout << "font - load +" << endl;
	}
	else
	{
		cout << "font was cracked" << endl;
	}

	int xpos=20, ypos=80;
	int xpos_1 = 240, ypos_1 = 80;
	int xpos_11 = 20, ypos_11 = 530;
	int xpos_12 = 240, ypos_12 = 530;
	
	if (res_count > 0)
	{
		SDL_Color color = { 255, 255, 255, 255 };
		SDL_Surface *textSurface = TTF_RenderText_Solid(fon, " LAST RECORDS :", color);
		SDL_Texture *text = SDL_CreateTextureFromSurface(ren, textSurface);
		SDL_Rect textRect;
		textRect.x = 100; textRect.y = 480;
		//	t=10;
		//	sprintf_s(temp, " %d ", t);
		SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
		SDL_RenderCopy(ren, text, NULL, &textRect);
		res_pr(ren, last_1, xpos_11, ypos_11, xpos_12, ypos_12);
		ypos_11 += 80;
		ypos_12 += 80;

		res_pr(ren, last_2, xpos_11, ypos_11, xpos_12, ypos_12);
		ypos_11 += 80;
		ypos_12 += 80;

		res_pr(ren, last_3, xpos_11, ypos_11, xpos_12, ypos_12);
		ypos_11 += 80;
		ypos_12 += 80;
	}
	

	QuickSort(results, res_count);

	
	if (res_count > 0)
	{
		SDL_Color color = { 255, 255, 255, 255 };
		SDL_Surface *textSurface = TTF_RenderText_Solid(fon, "TOP 5 RECORDS :", color);
		SDL_Texture *text = SDL_CreateTextureFromSurface(ren, textSurface);
		SDL_Rect textRect;
		textRect.x = 100; textRect.y = 0;
		//	t=10;
		//	sprintf_s(temp, " %d ", t);
		SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
		SDL_RenderCopy(ren, text, NULL, &textRect);
	}
	for (int i = 0; i < 6; i++) 
	{
		if (results[res_count-i] > 0) 
		{
			int a;
			a = results[res_count - i];
			res_pr(ren, a, xpos, ypos, xpos_1, ypos_1);
			ypos += 80;
			ypos_1 += 80;
		}
	}
	


	SDL_RenderPresent(ren);
}

menu::~menu()
{
	cout << "menu destroy" << endl;
}


