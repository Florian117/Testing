#include "Player.hpp"

#include "Game.hpp"

namespace pUncia {

	Player::Player(float posX, float posY) : mPosX(posX), mPosY(posY), mPlayerShape(20.f) {
		mPlayerShape.setPosition(mPosX, mPosY);
		mPlayerShape.setFillColor(sf::Color(222, 222, 143));
		std::cout << "Player created" << std::endl;
	}

	Player::~Player() {
		std::cout << "Player deleted" << std::endl;
	}

	void Player::render(Game &game) {
		game.mWindowPtr->draw(mPlayerShape);
	}

	void Player::update(Game &game) {
		mPlayerShape.setPosition(mPosX, mPosY);
	}

	void Player::handleEvents(Game &game) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			move(0, -mSpeed * game.mElapsedTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			move(0, mSpeed * game.mElapsedTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			move(-mSpeed * game.mElapsedTime, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			move(mSpeed * game.mElapsedTime, 0);
		}
	}

	void Player::move(float speedX, float speedY) {
		mPosX += speedX;
		mPosY += speedY;
	}

}