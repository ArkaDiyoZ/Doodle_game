#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"Game.h"
#include<SDL_ttf.h>
#include"functions.h"
#include<string>
#include"Doodle.h"
#include"menu.h"
#include<fstream>

int main(int argc, char *argv[])
{	
	init();
	SDL_Renderer*m_pRenderer = NULL;
	SDL_Window* m_pWindow = NULL;
	int SCREEN_WIDTH=600;
	int SCREEN_HEIGHT=800;
	int titlesize=200;
	
	if (TTF_Init() < 0) 
	{
		cout << "TTF_Init" << TTF_GetError() << endl;
		SDL_Quit();
	}
	else 
	{
		cout << "TTF - succses" << endl;
	}
	m_pWindow = SDL_CreateWindow("----Code Bourn----", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_MOUSE_FOCUS);
	if (m_pWindow != 0) // window init success
	{
		cout << "window creation success" << endl;
		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (m_pRenderer != 0) // renderer init success
		{
			cout << "renderer creation success" << endl;
			if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
			{
				cout << "IMG_Init" << SDL_GetError() << endl;
				SDL_Quit();
			}

		}
		else
		{
			cout << "renderer init fail" << endl;
			return false; // renderer init fail
		}
	}
	else
	{
		cout << "window init fail\n";
		return false; // window init fail
	}

	menu *m = 0;
	m = new menu(m_pRenderer, titlesize, m_pWindow, SCREEN_WIDTH, SCREEN_HEIGHT);

	Doodle *gg = 0;
	//"----Code Bourn----", 100, 100, SDL_WINDOW_MOUSE_FOCUS, path_level_1

	int hell = 0;
	int heaven = 0;
	int temp=0;

	int n = 4;
	while(n!=2){   
	m->render();

	while (m->run()) 
	{
		m->handle();
		if (m->get_fl_vvod()) 
		{
			m->start();
			if (m->get_ch() == 1) 
			{
				heaven = 1;
				hell = 0;
				gg = new Doodle(m_pRenderer, titlesize, m_pWindow, SCREEN_WIDTH, SCREEN_HEIGHT, hell, heaven);
				//cout << "dodle chiil" << endl;
			}
			else if (m->get_ch() == 2) 
			{
				hell = 1;
				heaven = 0;	
				gg = new Doodle(m_pRenderer, titlesize, m_pWindow, SCREEN_WIDTH, SCREEN_HEIGHT,hell,heaven);
				//cout << "doodle hell" << endl;
			}
			else 
			{
				m->handle();
			}
		}
		
	} 
	
	while (gg->run())
	{
		gg->move();
		if (gg->get_ret())
		{
			temp = 1;
			gg->set_y(temp);
		}

		gg->render();
		if (gg->get_fl_death()) 
		{
			gg->death_paint();
			if (gg->get_fl_fl()== 2) 
			{
	
			}
		}

	}
	ofstream out;
	out.open("records.txt", ios_base::app);
	if (out.is_open())
	{
		cout << "open" << endl;
		out << gg->get_sc() << endl;
	}
	cout << "End of program" << endl;

	gg = 0;
	m = 0;
	m = new menu(m_pRenderer, titlesize, m_pWindow, SCREEN_WIDTH, SCREEN_HEIGHT);
	// m->set_men(true);
	}


	delete[] gg;
	delete[]m;
	//system("Pause");
	

	return 0;
}