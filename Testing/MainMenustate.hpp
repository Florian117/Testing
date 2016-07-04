#pragma once

#include "Button.hpp"

class Game;

namespace pUncia {

	class MainMenustate {
		public:
			MainMenustate();
			~MainMenustate();

			void update(sf::RenderWindow &window);
			void render(sf::RenderWindow &window);
			void handleEvents(sf::RenderWindow &window);

		private:
			pUncia::Button mStartBtn;
			pUncia::Button mExitBtn;

	};
}