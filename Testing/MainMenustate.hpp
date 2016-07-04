#pragma once

#include "Button.hpp"

class Game;

namespace pUncia {

	class MainMenustate {
		public:
			MainMenustate();
			~MainMenustate();

			void update(Game &game);
			void render(Game &game);
			void handleEvents(Game &game);

		private:

	};
}