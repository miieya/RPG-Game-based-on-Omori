#pragma once
#include "Tool.h"
#include "treemap.h"

class NeighborRoom
{
public:
	
	void Begin_Print(Tool& t);
	void door_choose(Tool& t);
	void stair_choose(Tool& t, treemap& tree);
	void map_Print(Tool& t);
	void Photo(Tool& t);
	void Pillow(Tool& t);
	void Hole(Tool& t);
	void TV(Tool& t);
	void Snack(Tool& t);
	void Aubrey(Tool& t);
	void Kel(Tool& t);
	void Hero(Tool& t);

	void Position(int x0, int y0, int x1, int y1, Tool& t);
	int  ClueJudge(int x1, int y1);
	void Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t);
	void Execute_NeighborRoom(Tool& t, int judge);

	int map[13][18] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					   1,0,2,2,0,3,3,0,0,0,0,0,0,0,0,6,6,1,
				       1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,1,
			     	   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1,
					   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					   1,0,1,1,0,0,0,11,0,10,0,0,0,0,0,0,0,1,
				       1,0,1,1,0,0,0,0,9,0,0,0,0,0,0,0,0,1,
			   	       1,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1,
		    		   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					   1,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,1,
					   1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					   1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,1,1,1 };
	
	static int cnt;
	static int cnt2;
	//2°¢’’∆¨  3°¢’ÌÕ∑  4°¢∂¥  5°¢µÁ ”  6°¢¬•Ã›  7°¢…ﬂ  8°¢√≈  9°¢A  10°¢K  11°¢H
}; 
