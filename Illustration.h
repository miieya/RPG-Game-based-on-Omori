//Í¼¼øÀà
#pragma once
#include "Tool.h"

class Illustration
{
public:

	void Header_Print01(Tool& t);
	void Header_Print02(Tool& t,int judge);
	void Select(Tool& t);

	void Position(int x0, int y0, int x1, int y1, Tool& t);
	int  ClueJudge(int x1, int y1);
	void Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t, int judge);
	void Execute(Tool& t, int judge1, int judge2);

	void ForestBunny(Tool& t);
	void SproutMole(Tool& t);
	void Mixtape(Tool& t);
	void DoomBox(Tool& t);

	int map[6][17] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					   1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,
					   1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,
		               1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
					
};

