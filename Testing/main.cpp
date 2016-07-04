#include <iostream>

#include "Game.hpp"

int main()
{
	pUncia::Game game;

	while (game.isRunning()) {
		game.running();
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}