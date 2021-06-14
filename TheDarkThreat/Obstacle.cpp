#include "Obstacle.h"

void Obstacle::animationEnd(std::vector<Entity*>* entities)
{
}

Obstacle::Obstacle(
	std::map<std::string, sf::Texture*>* textures, const float& fps
):Entity(textures, fps)
{
	this->setTexture(*this->textures->operator[]("TREE"));

	this->addAnimation(EntityState::Idle, {
		{24, 14, 113, 139}
		});

	this->setFirstFrame();
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
}
