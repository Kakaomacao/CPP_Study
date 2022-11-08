#include <iostream>
using namespace std;
#include "Game.h"

// ø¿¥√¿« ¡÷¡¶ : TextRPG #4

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