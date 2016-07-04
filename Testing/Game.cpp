#include <iostream>

#include "Game.hpp"

namespace pUncia {

		Game::Game() {
			mWindowPtr = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(int(mWindowSizeX), int(mWindowSizeY)), "Window"));
			mPlaystatePtr = std::unique_ptr<Playstate>(new Playstate());
			mMainMenustatePtr = std::unique_ptr<MainMenustate>(new MainMenustate());
			mRunningBvar = true;
			std::cout << "Game Started" << std::endl;
		}

		Game::~Game() {
			mRunningBvar = false;
			mWindowPtr->close();
			std::cout << "Game Closed" << std::endl;
		}

		void Game::running() {
			// Elapsed Time - Richtig ?
			mTime = mClock.getElapsedTime();;
			mElapsedTime = float(mTime.asMilliseconds());
			while (mWindowPtr->isOpen()) {
				while (mWindowPtr->pollEvent(mEvent)) {
					handleEvents();
				}
				update();
				render();
			}
			mClock.restart();
		}

		void Game::render() {
			mWindowPtr->clear(sf::Color(123, 123, 123));

			mPlaystatePtr->render(*this);
			mMainMenustatePtr->render(*this->mWindowPtr);

			mWindowPtr->display();
		}

		void Game::update() {
			mPlaystatePtr->update(*this);
			mMainMenustatePtr->update(*this->mWindowPtr);
		}

		void Game::handleEvents() {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || mEvent.type == sf::Event::Closed) {
				mRunningBvar = false;
				mWindowPtr->close();
			}
			mPlaystatePtr->handleEvents(*this);
			mMainMenustatePtr->handleEvents(*this->mWindowPtr);
		}

		bool Game::isRunning() {
			return mRunningBvar;
		}
}