#include "MainMenustate.hpp"
#include "Game.hpp"

namespace pUncia {

	MainMenustate::MainMenustate() : mStartBtn(40.0f, 40.0f, "Start"), mExitBtn(40.0f, 100.0f, "Beenden") {
		std::cout << "MainMenustate Konstrunktor Aufruf" << std::endl;
	}

	MainMenustate::~MainMenustate()	{
		std::cout << "MainMenustate Dekonstrunktor Aufruf" << std::endl;
	}

	void MainMenustate::update(sf::RenderWindow &window) {
	}

	void MainMenustate::render(sf::RenderWindow &window)	{
		mStartBtn.render(window);
		mExitBtn.render(window);
	}

	void MainMenustate::handleEvents(sf::RenderWindow &window) {
		mStartBtn.handleEvents(window);
		mExitBtn.handleEvents(window);
	}

}