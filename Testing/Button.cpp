#include <iostream>

#include "Button.hpp"
#include "Game.hpp"

namespace pUncia {
	namespace gui {

		Button::Button(float posX, float posY, std::string btnString) : mPosX(posX), mPosY(posY), mBtnString(btnString) {
			if (!mBtnFont.loadFromFile("calibri.ttf")) {
				std::cerr << "ERROR: Canno't load the Font" << std::endl;
			};

			mBtnText.setFont(mBtnFont);
			mBtnText.setString(mBtnString);
			mBtnText.setCharacterSize(50);
			mBtnText.setColor(sf::Color::White);

			mBtnText.setPosition(mPosX, mPosY);

			std::cout << "Button Konstruktor Aufruf" << std::endl;
		}

		Button::~Button() {
		}


		void Button::render(sf::RenderWindow &window) {
			window.draw(mBtnText);
		}

		void Button::handleEvents(sf::RenderWindow &window) {
			float mousePosX = sf::Mouse::getPosition(window).x;
			float mousePosY = sf::Mouse::getPosition(window).y;
			//std::cout << mousePosX << " __ " << mousePosY << std::endl;

			if (contains(mousePosX, mousePosY)) { mBtnHover = true; } else { mBtnHover = false; }
			if (mBtnHover) { mBtnText.setColor(sf::Color::Red); } else { mBtnText.setColor(sf::Color::White); };
			if (contains(mousePosX, mousePosY) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (mBtnPressed) { mBtnPressed = false; } else { mBtnPressed = true; }
			}
		}

		bool Button::contains(float mousePosX, float mousePosY) {
			if ((mousePosX >= mBtnText.getPosition().x && mousePosX <= mBtnText.getPosition().x + mBtnText.getGlobalBounds().width) && (mousePosY >= mBtnText.getPosition().y && mousePosY <= mBtnText.getPosition().y + mBtnText.getGlobalBounds().height)) {
				return true;} else { return false; }
		}

	}
}