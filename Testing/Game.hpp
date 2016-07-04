#pragma once

#include <iostream>
#include <memory>

#include"SFML\Graphics.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Button.hpp"

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
		sf::Time mTime;
		sf::Clock mClock;

	private:
		sf::Event mEvent;

		float mWindowSizeX{1366.f};
		float mWindowSizeY{768.f};

		bool mRunningBvar = false;

		pUncia::Player mPlayer;
		pUncia::gui::Button mButton;
		pUncia::gui::Button mAnotherBtn;

	};

}

