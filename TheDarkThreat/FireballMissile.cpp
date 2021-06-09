#include "FireballMissile.h"

FireballMissile::FireballMissile(
	sf::RenderWindow* window, sf::Texture* texture, const float& fps, 
	const sf::Vector2f& target, const sf::Vector2f& pos
): Missile(window, texture, fps, target, pos)
{
}

FireballMissile::~FireballMissile()
{
}

void FireballMissile::customBehaviour()
{
	this->canDestroy = true;
}
