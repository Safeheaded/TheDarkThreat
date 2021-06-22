#include "Missile.h"
#include <cmath>
#include "Utils.h"
#include "Player.h"
#include "Wraith.h"
#include "Skeleton.h"

void Missile::animationEnd(std::vector<Entity*>* entities)
{
}

Missile::Missile(
	sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
	const float& fps, const sf::Vector2f& target,
	const sf::Vector2f& pos
):
	Entity(textures, fps), window(window), speed(800),
	target(target), damage(50), type(MissileType::Friendly)
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

void Missile::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	auto missileBounds = this->getGlobalBounds();
	this->setOrigin(missileBounds.width/2, missileBounds.height/2);

	this->move(
		this->direction * speed * deltaTime
	);

	float missileRadius = 
		static_cast<float>(sqrt(pow(missileBounds.width / 2, 2) + 
			pow(missileBounds.height / 2, 2)))/2;

	if (missileBounds.contains(
		this->target + this->direction * missileRadius
	)) {
		//this->canDestroy = true;
		this->customBehaviour(deltaTime);
	}

	for (auto& entity : *entities) {
		if (missileBounds.intersects(entity->getGlobalBounds())) {
			if (this->type == MissileType::Friendly && typeid(*entity) == typeid(Wraith) ||
				this->type == MissileType::Hostile && typeid(*entity) == typeid(Player) ||
				this->type == MissileType::Friendly && typeid(*entity) == typeid(Skeleton)) {
				this->customAttackBehaviour(deltaTime, entity);
			}
		}
	}

	this->animate(deltaTime, entities);
}
