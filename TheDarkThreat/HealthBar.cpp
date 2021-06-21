#include "HealthBar.h"

void HealthBar::animationEnd(std::vector<Entity*>* entities)
{
}

HealthBar::HealthBar(std::map<std::string, sf::Texture*>* textures,
	const float& fps, Entity* entity): Entity(textures, 1), entity(entity), maxWidth(40)
{

	this->setTexture(*textures->operator[]("ENEMY_HEALTH"));
	this->setTextureRect(sf::IntRect(0, 0, this->maxWidth, 5));
}

HealthBar::~HealthBar()
{
}

void HealthBar::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	if (!this->entity->getCanDie()) {
		auto entityBounds = this->entity->getGlobalBounds();
		auto barBounds = this->getGlobalBounds();
		this->setPosition(
			entityBounds.left + entityBounds.width/2 - this->maxWidth /2, 
			entityBounds.top - 15
		);


		this->setTextureRect(sf::IntRect(
			0, 0, this->maxWidth * entity->getHealth() / entity->getMaxHealth(), 5)
		);
	}
	else {
		std::cout << "Destroying healthBar" << std::endl;
		this->canDie = true;
	}
}
