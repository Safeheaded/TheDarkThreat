#pragma once
#include "Scene.h"

class Obstacle : public sf::RectangleShape
{
public:
	Obstacle(const sf::Vector2f& size, const sf::Vector2f& pos);
	~Obstacle();
};

