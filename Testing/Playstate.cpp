#include "Playstate.hpp"
#include "Game.hpp"

namespace pUncia {

	Playstate::Playstate() : mPlayerPtr(std::unique_ptr<Player>(new Player(1366/2, 768/2))) {
		std::cout << "Playstate Konstrunktor Aufruf" << std::endl;
	} 

	Playstate::~Playstate() {
		std::cout << "Playstate Dekonstrunktor Aufruf" << std::endl;
	}

	void Playstate::update(Game &game)	{
		mPlayerPtr->update(game);
	}

	void Playstate::render(Game &game)	{
		mPlayerPtr->render(game);
	}

	void Playstate::handleEvents(Game &game) {
		mPlayerPtr->handleEvents(game);
	}

}