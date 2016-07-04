#pragma once

#include <iostream>
#include <memory>
#include"SFML\Graphics.hpp"

#include "Game.hpp"
#include "Playstate.hpp"
#include "MainMenustate.hpp"

namespace pUncia {

	class Game {

	public:
		Game();
		~Game();

		void running();
		bool isRunning();

		void render();
		void update();
		void handleEvents();

		std::unique_ptr<sf::RenderWindow> mWindowPtr;

		float mElapsedTime;
	

	private:
		sf::Event mEvent;
		sf::Time mTime;
		sf::Clock mClock;

		float mWindowSizeX{1366.f};
		float mWindowSizeY{768.f};

		bool mRunningBvar = false;

		std::unique_ptr<Playstate> mPlaystatePtr;
		std::unique_ptr<MainMenustate> mMainMenustatePtr;

	};

}

