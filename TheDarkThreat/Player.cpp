#include "Player.h"
#include <cmath>

Player::Player(sf::RenderWindow* window, sf::Texture* texture, const float& fps):
	Entity(texture, fps), speed(500), 
	window(window), isRunning(false), prevState(EntityState::Idle)
{
}

Player::~Player()
{
}

void Player::update(const float& deltaTime)
{
	this->isRunning = false;
	auto playerBounds = this->getGlobalBounds();

	// Movement
	sf::Vector2f velocity;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		velocity.y = -this->speed * deltaTime;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		velocity.y = this->speed * deltaTime;
	}

	// TODO (low priority): change scale / origin only after direction change
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocity.x = -this->speed * deltaTime;
		this->setScale(-1, 1);
		this->setOrigin({ playerBounds.width, 0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x = this->speed * deltaTime;
		this->setScale(1, 1);
		this->setOrigin({ 0, 0 });
	}

	// Checks if player is moving
	if (
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->isRunning = true;
	}

	// changes state based on movement (or it's absence)
	if (this->isRunning) {
		this->state = EntityState::Move;
	}
	else {
		this->state = EntityState::Idle;
	}

	// resets animation counter if animation has changed
	if (this->state != this->prevState) {
		this->counter = 0;
		this->prevState = this->state;
	}

	// fires animation
	this->animate(deltaTime);

	// moves sprite
	this->move(velocity);

	// Window collision
	if (getPosition().x < 0) {
		setPosition(0, getPosition().y);
	}
	if (getPosition().y < 0) {
		setPosition(getPosition().x, 0);
	}
	if (getPosition().x + playerBounds.width > window->getSize().x) {
		setPosition(window->getSize().x - playerBounds.width, getPosition().y);
	}
	if (getPosition().y + playerBounds.height > window->getSize().y) {
		setPosition(getPosition().x, window->getSize().y - playerBounds.height);
	}

}
