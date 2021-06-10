#include "Missile.h"
#include <cmath>
#include "Utils.h"

void Missile::animationEnd()
{
}

Missile::Missile(
	sf::RenderWindow* window, sf::Texture* texture,
	const float& fps, const sf::Vector2f& target,
	const sf::Vector2f& pos, std::vector<Entity*>* enemies
):
	Entity(texture, fps), window(window), speed(800), 
	target(target), enemies(enemies), damage(50)
{
	this->setPosition(pos);

	auto missileBounds = this->getGlobalBounds();

	this->initialPosition = this->getPosition();

	sf::Vector2f distance = direction = this->target - this->getPosition();
	this->direction = distance / Utils::getVectorLength(direction);
}

Missile::~Missile()
{
}

void Missile::update(const float& deltaTime)
{
	auto missileBounds = this->getGlobalBounds();
	this->setOrigin(missileBounds.width/2, missileBounds.height/2);

	this->move(
		this->direction * speed * deltaTime
	);

	float missileRadius = 
		static_cast<float>(sqrt(pow(missileBounds.width / 2, 2) + 
			pow(missileBounds.height / 2, 2)));

	if (missileBounds.contains(
		this->target + this->direction * missileRadius
	)) {
		//this->canDestroy = true;
		this->customBehaviour(deltaTime);
	}

	// There is only one item in vector
	for (auto& enemy : *this->enemies) {
		if (missileBounds.intersects(enemy->getGlobalBounds())) {
			this->customBehaviour(deltaTime);
			enemy->dealDamage(this->damage);
		}
	}

	this->animate(deltaTime);
}
