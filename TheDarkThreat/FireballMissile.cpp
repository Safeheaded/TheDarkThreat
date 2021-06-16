#include "FireballMissile.h"

FireballMissile::FireballMissile(
	sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures, const float& fps,
	const sf::Vector2f& target, const sf::Vector2f& pos
): Missile(window, textures, fps, target, pos)
{
	this->damage = 100;
	this->addAnimation(EntityState::Idle, {
		{23, 26, 53, 47},
		{122, 26, 55, 47},
		{221, 26, 56, 47},
		{320, 26, 58, 47},
		{419, 26, 53, 47},
		{518, 26, 54, 47},
		{617, 26, 55, 47},
		{725, 26, 57, 47},

		{17, 127, 53, 47},
		{116, 127, 55, 47},
		{224, 127, 56, 47},
		{323, 127, 58, 47},
		{424, 127, 53, 47},
		{524, 127, 54, 47},
		{623, 127, 55, 47},
		{723, 127, 57, 47},

		{23, 228, 53, 47},
		{122, 228, 55, 47},
		{221, 228, 56, 47},
		{320, 228, 58, 47},
		{419, 228, 53, 47},
		{518, 228, 54, 47},
		{617, 228, 55, 47},
		{716, 228, 57, 47},

		{23, 329, 53, 47},
		{122, 329, 55, 47},
		{221, 329, 56, 47},
		{320, 329, 58, 47},
		{419, 329, 53, 47},
		{518, 329, 54, 47},
		{617, 329, 55, 47},
		{716, 329, 57, 47},

		{23, 430, 53, 47},
		{122, 430, 55, 47},
		{221, 430, 56, 47},
		{320, 430, 58, 47},
		{419, 430, 53, 47},
		{518, 430, 54, 47},
		{617, 430, 55, 47},
		{716, 430, 57, 47},
		});
	this->setTexture(*this->textures->operator[]("FIREBALL"));
	this->setFirstFrame();
}

FireballMissile::~FireballMissile()
{
}

void FireballMissile::customBehaviour(const float& deltaTime)
{
	this->canDie = true;
}

void FireballMissile::customAttackBehaviour(const float& deltaTime, Entity* entity)
{
	this->customBehaviour(deltaTime);
	entity->dealDamage(this->damage);
}
