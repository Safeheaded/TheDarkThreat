#include "ManaPotion.h"

void ManaPotion::animationEnd(std::vector<Entity*>* entities)
{
}

void ManaPotion::refillMana()
{
	if (this->player->getMana() < this->player->getMaxMana()) {
		this->player->mana = this->player->maxMana;
		this->canDie = true;
	}
}

ManaPotion::ManaPotion(std::map<std::string, sf::Texture*>* textures, const float& fps, 
	Player* player): Entity(textures, 1), player(player)
{
	this->setTexture(*this->textures->operator[]("MANA_POTION"));
	this->setTextureRect(sf::IntRect(1, 0, 14, 16));
	this->setScale(2, 2);
}

ManaPotion::~ManaPotion()
{
}

void ManaPotion::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	auto playerBounds = this->player->getGlobalBounds();
	auto potionBounds = this->getGlobalBounds();
	if (potionBounds.intersects(playerBounds)) {
		this->refillMana();
	}
}
