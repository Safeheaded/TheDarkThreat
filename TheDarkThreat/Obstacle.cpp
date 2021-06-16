#include "Obstacle.h"

Obstacle::Obstacle(const sf::Vector2f& size, const sf::Vector2f& pos)
{
	this->setSize(size);
	this->setPosition(pos);
}

Obstacle::~Obstacle()
{
}
