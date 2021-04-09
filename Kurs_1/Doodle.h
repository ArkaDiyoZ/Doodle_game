#pragma once
#include"Game.h"
#include"functions.h"
#include<SDL_ttf.h>

struct pl_c 
{
	SDL_Texture *pl;
	int p_str_x;
	int p_str_y;
	int height = 16;
	int width = 57;
};
class Doodle:public Game
{
private:
	SDL_Texture *dood;
	SDL_Renderer *ren;
	SDL_Texture *back;
	SDL_Texture *plate_green;
	SDL_Rect mCollider;
	SDL_Window* m_pWindow;
	struct pl_c *plate_co;
	char score_ptr;
	int x;
	int y;
	int p_x;
	int p_y;
	int pl_x;
	int pl_y;
	int *pl_masx;
	int *pl_masy;
	int speed;
	int h;
	int pl_count;
	int del_dud;
	char p[100];
	float dx, dy;
	int hell;
	bool m_bRunning;
	int heaven;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int titlesize;
	bool ret;
	int y_temp;
	int heav_hell;
	int heav_hel_par;
	int tte;
	bool flag_death;
	bool flag_death_true;
	int flfl;
	string path;
	string path_r;
public:

	Doodle(SDL_Renderer*, int, SDL_Window *, int,int,int,int);
	void render();
	void move();
	virtual bool run();
	virtual int handle();
	void set_y(int);
	int get_y();
	void score();
	void death();
	void death_paint();
	void set_ret(bool a) { ret = a; };
	int get_ret(){return ret;};
	void set_fl_death(bool a) { flag_death_true = a; };
	int get_fl_death() { return flag_death_true; };

	void set_sc(int a) { tte = a; };
	int get_sc() { return tte; };

	void set_fl_fl(int a) { flfl = a; };
	int get_fl_fl() { return flfl; };
	~Doodle();
};

