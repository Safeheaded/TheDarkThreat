#include "EnemyMissile.h"

void EnemyMissile::animationEnd()
{
}

void EnemyMissile::customBehaviour(const float& deltaTime)
{
	this->canDie = true;
}

void EnemyMissile::customAttackBehaviour(const float& deltaTime, Entity* entity)
{
	this->canDie = true;
	entity->dealDamage(this->damage);
}

EnemyMissile::EnemyMissile(
	sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures, const float& fps,
	const sf::Vector2f& target, const sf::Vector2f& pos
): Missile(window, textures, fps, target, pos)
{
	this->damage = 30;
	this->addAnimation(EntityState::Idle, {
		{45, 53, 35, 40}
	});
	this->setTexture(*this->textures->operator[]("ENEMY_ATTACK"));
	this->setFirstFrame();
	this->type = MissileType::Hostile;

}

EnemyMissile::~EnemyMissile()
{
}
