#include "HealthPotion.h"

void HealthPotion::animationEnd(std::vector<Entity*>* entities)
{
}

void HealthPotion::heal()
{
	if (this->player->getHealth() < this->player->getMaxHealth()) {
		this->player->health = this->player->maxHealth;
		this->canDie = true;
	}
}

HealthPotion::HealthPotion(std::map<std::string, sf::Texture*>* textures,
	const float& fps, Player* player) :
	Entity(textures, 1), player(player)
{
	this->setTexture(*textures->operator[]("HEALTH_POTION"));
	this->setTextureRect(sf::IntRect(1, 0, 14, 16));
	this->setScale(2, 2);
}

HealthPotion::~HealthPotion()
{
}

void HealthPotion::update(const float& deltaTime, std::vector<Entity*>* entities,
	sf::Vector2f mapSize)
{
	auto playerBounds = this->player->getGlobalBounds();
	auto potionBounds = this->getGlobalBounds();
	if (potionBounds.intersects(playerBounds)) {
		this->heal();
	}
}
