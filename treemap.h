#ifndef TREEMAP_H
#define TREEMAP_H
#include "Tool.h"
#include "Fight.h"

class treemap
{
public:
	//treemap() ;

	void Begin_Print(Tool& t);
	void map_Print(Tool& t, int judge);

	void mailbox(Tool&);
	void ForestRabbit(Tool&);
	void Jigsaw(Tool&);
	void mailbox_choose(Tool&);
	void door_choose(Tool& t);

	void Position(int x0, int y0, int x1, int y1, Tool& t);
	int  ClueJudge(int x1, int y1);
	void Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t);
	void Execute_treemap(Tool& t, int judge1, int judge2);

	int map[19][19] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,
						1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,
						1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,
						1,1,1,1,0,0,4,0,0,0,0,0,0,0,0,1,1,1,1,
						1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
						1,1,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,1,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,1,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,1,1,
						1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
						1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
						1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,
						1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,
						1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};

	 static int ifSuccess;
	 Fight fight;
	//1°¢ ˜  //2°¢” œ‰ //3°¢∆¥Õº //4°¢…≠¡÷Õ√Õ√
};
#endif //!TREEMAP
