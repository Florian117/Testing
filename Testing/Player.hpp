#pragma once

#include "SFML\Graphics.hpp"

namespace pUncia {

class Game;

	class Player {

	public:
		Player(float posX, float posY);
		~Player();

		void render(Game &game);
		void update(Game &game);
		void handleEvents(Game &game);

	private:
		sf::CircleShape mPlayerShape;

		void move(float speedX, float speedY);

		float mSpeed = 220.0f;
		float mPosX = 0.0f;
		float mPosY = 0.0f;

	};
}