#include "Tree.h"

void Tree::animationEnd(std::vector<Entity*>* entities)
{
}

Tree::Tree(
	std::map<std::string, sf::Texture*>* textures, const float& fps
):Entity(textures, fps)
{
	this->setTexture(*this->textures->operator[]("TREE"));

	this->addAnimation(EntityState::Idle, {
		{24, 14, 113, 139}
		});

	this->setFirstFrame();
}

Tree::~Tree()
{
}

void Tree::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
}
