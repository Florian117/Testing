#pragma once

#include <string>
#include "SFML\Graphics.hpp"

namespace pUncia {
	namespace gui {

		class Game;

		class Button {
			public:
				Button(float posX, float posY, std::string btnString);
				~Button();

				void render(sf::RenderWindow &window);
				void handleEvents(sf::RenderWindow &window);

				bool btnPressed() { return mBtnPressed; };

			private:

				float mPosX = 0;
				float mPosY = 0;

				bool mBtnHover = false;
				bool mBtnPressed = false;

				bool contains(float mousePosX, float mousePosY);

				sf::Font mBtnFont;
				sf::Text mBtnText;
				std::string mBtnString = "Nameless";

				sf::RectangleShape mBtnShape;

			};

	}
}