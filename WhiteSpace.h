//°×É«¿Õ¼ä
#pragma once
#include "Tool.h"

class WhiteSpace
{
public:

	void Begin_Print(Tool& t);
	void map_Print(Tool& t);

	void Computer(Tool& t, int judge);
	void Computer_Choose(Tool& t);
	void Computer_Print(Tool& t);
	void Computer_Print_Diary(Tool& t);
	void ArtBook(Tool& t);
	void TissueBox(Tool& t);
	void Cat(Tool& t);
	void Bulb(Tool& t);
	void Bulb_Choose(Tool& t);
	void Door(Tool& t);
	void Door_Choose(Tool& t);

	void Position(int x0, int y0, int x1, int y1, Tool& t);
	int  ClueJudge(int x1, int y1);
	void Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t);
	void Execute_WhiteSpace(Tool& t, int judge);

	int map[14][19] = { 1,1,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						1,0,0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,2,2,0,0,0,0,0,0,3,3,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,4,4,4,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

	//2¡¢µçÄÔ  3¡¢»­±¾  4¡¢Ö½½íºÐ   5¡¢ß÷ÎØ  6¡¢µÆÅÝ   7¡¢ÃÅ
};
