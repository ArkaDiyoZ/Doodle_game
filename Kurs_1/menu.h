#pragma once
#include"Game.h"
#include"functions.h"
#include<SDL_ttf.h>
#include<SDL.h>

class menu:public Game
{
private:
	SDL_Texture *back_menu;
	SDL_Texture *ex;
	int e_x;
	int e_y;
	SDL_Texture *but_start;
	int x_start;
	int y_start;
	SDL_Texture *List;
	int x_list;
	int y_list;
	SDL_Texture *rule;
	int x_rul;
	int y_rul;
	int titlesize;
	SDL_Texture *rl_tx;
	SDL_Texture *chose;
	int rtx;
	int rty;
	SDL_Renderer * ren;
	SDL_Window * win;
	int last_1; 
	int last_2;
	int last_3;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int x;
	int y;
	bool m_bRunning;
	bool flag_vvod;
	bool flag_rule;
	bool flag_game;
	int flag_ch;
	int *results;
	int res_count;
	char p[100];
public:
	menu(SDL_Renderer*, int, SDL_Window *, int, int);
	void render();
	virtual bool run();
	virtual int handle();
	void start();
	void vvod();
	void rule_ins();
	void set_fl_vvod(bool a) { flag_vvod = a; };
	int get_fl_vvod () { return flag_vvod; };
	void set_fl_rule(bool a) { flag_rule = a; };
	int get_fl_rule() { return flag_rule; };
	void set_ch(int a) { flag_ch = a; };
	int get_ch() { return flag_ch; };
	void lead_print();
	void set_men(bool a) { m_bRunning = a; };
	~menu();
};

