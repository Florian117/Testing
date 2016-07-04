#include <iostream>

#include "Game.hpp"

namespace pUncia {

		Game::Game() : mPlayer(1366 / 2, 768 / 2), mButton(40.0f, 40.0f, "Start"), mAnotherBtn(40.0f, 100.0f, "Beenden") {
			mWindowPtr = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(int(mWindowSizeX), int(mWindowSizeY)), "Window"));
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

			mPlayer.render(*this);

			mButton.render(*this->mWindowPtr);
			mAnotherBtn.render(*this->mWindowPtr);

			mWindowPtr->display();
		}

		void Game::update() {
			//std::cout << mElapsedTime << std::endl;
			mPlayer.update(*this);
		}

		void Game::handleEvents() {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || mEvent.type == sf::Event::Closed) {
				mRunningBvar = false;
				mWindowPtr->close();
			}
			mPlayer.handleEvents(*this);
			mButton.handleEvents(*this->mWindowPtr);
			mAnotherBtn.handleEvents(*this->mWindowPtr);
			if (mAnotherBtn.btnPressed()) {
				mRunningBvar = false;
				mWindowPtr->close();
			}

		}

		bool Game::isRunning() {
			return mRunningBvar;
		}
}