#include "ParticleMissile.h"

void ParticleMissile::customBehaviour(const float& deltaTime)
{
	//this->rotate(180 * deltaTime);

	this->timePassed += deltaTime;

	if (this->timePassed >= this->lifeTime) {
		this->canDestroy = true;
	}

	this->speed = 0;
}

ParticleMissile::ParticleMissile(
	sf::RenderWindow* window, sf::Texture* texture, 
	const float& fps, const sf::Vector2f& target, const sf::Vector2f& pos
):Missile(window, texture, fps, target, pos)
{
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
	this->setFirstFrame();
	this->lifeTime = 3;
	this->timePassed = 0;
	this->setScale(2, 2);
}

ParticleMissile::~ParticleMissile()
{
}
