#include <iostream>
using namespace std;
#include "Game.h"

// ������ ���� : TextRPG #4

int main()
{
	srand(time(NULL));
	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}


	return 0;
}