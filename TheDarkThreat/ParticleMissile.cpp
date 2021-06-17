#include "ParticleMissile.h"

void ParticleMissile::customBehaviour(const float& deltaTime)
{
	//this->setOrigin(bounds.width / 2, bounds.height / 2);
	//this->setScale(2, 2);
	this->timePassed += deltaTime;

	if (this->timePassed >= this->lifeTime) {
		this->canDie = true;
	}

	this->speed = 0;
}

void ParticleMissile::customAttackBehaviour(const float& deltaTime, Entity* entity)
{
	if (this->attackTimeCounter >= this->attacksPerSecond) {
		entity->dealDamage(this->damage);
		this->attackTimeCounter -= this->attacksPerSecond;
	}
	else {
		this->attackTimeCounter += deltaTime;
	}
}

ParticleMissile::ParticleMissile(
	sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
	const float& fps, const sf::Vector2f& target, 
	const sf::Vector2f& pos
):Missile(window, textures, fps, target, pos), 
attacksPerSecond(1), attackTimeCounter(1)
{
	this->damage = 100;
	this->addAnimation(EntityState::Idle, {
		{16, 19, 68, 68},
		{116, 19, 68, 68},
		{215, 19, 68, 68},
		{314, 19, 68, 68},
		{418, 19, 68, 68},
		{518, 19, 68, 68},
		{617, 19, 68, 68},
		{716, 19, 68, 68},
		});
	this->setTexture(*this->textures->operator[]("PARTICLE"));
	this->setFirstFrame();
	this->lifeTime = 5;
	this->timePassed = 0;
	auto bounds = this->getGlobalBounds();
	//this->setOrigin(bounds.width/2, bounds.height/2);
	//this->setScale(2, 2);
}

ParticleMissile::~ParticleMissile()
{
}
