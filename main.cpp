#include <iostream>
#include <windows.h> 
#include <ctime>
#include "Tool.h"
#include "TitleScreen.h"
#include "Illustration.h"
#include "WhiteSpace.h"
#include "NeighborRoom.h"
#include "treemap.h"

using namespace std;

int main() {

    srand(time(0));
   /* 从头开始*/
    TitleScreen title;
    title.Execute_Title(1);

    //战斗入口
   /* Tool t;
    treemap tree;
    tree.Execute_treemap(t, 0, 1);*/

    system("pause");
    return 0;
}
