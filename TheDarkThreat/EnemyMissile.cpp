#include "EnemyMissile.h"

void EnemyMissile::animationEnd()
{
}

void EnemyMissile::customBehaviour(const float& deltaTime)
{
	this->canDie = true;
}

EnemyMissile::EnemyMissile(
	sf::RenderWindow* window, sf::Texture* texture, const float& fps, 
	const sf::Vector2f& target, const sf::Vector2f& pos
): Missile(window, texture, fps, target, pos)
{
	this->damage = 30;
	this->addAnimation(EntityState::Idle, {
		{45, 53, 35, 40}
	});
	this->setFirstFrame();
	this->type = MissileType::Hostile;
}

EnemyMissile::~EnemyMissile()
{
}
