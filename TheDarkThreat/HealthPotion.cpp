#include "HealthPotion.h"

void HealthPotion::animationEnd(std::vector<Entity*>* entities)
{
}

void HealthPotion::heal(Player* player)
{
	if (player->getHealth() < player->getMaxHealth()) {
		player->health = player->maxHealth;
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
		this->heal(this->player);
		this->canDie = true;
	}
}
