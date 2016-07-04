#pragma once

#include "Player.hpp"

class Game;

namespace pUncia {

	class Playstate {
		public:
			Playstate();
			~Playstate();

			void update(Game &game);
			void render(Game &game);
			void handleEvents(Game &game);

		private:

	};

}