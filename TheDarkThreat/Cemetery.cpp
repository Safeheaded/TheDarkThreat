#include "Cemetery.h"

void Cemetery::animationEnd(std::vector<Entity*>* entities)
{
}

Cemetery::Cemetery(std::map<std::string, sf::Texture*>* textures):
	Entity(textures, 1)
{
	this->setTexture(*textures->operator[]("CEMETERY"));
	this->setTextureRect({
			2, 2, 77, 45
		});
	this->setScale(2, 2);
}

Cemetery::~Cemetery()
{
}

void Cemetery::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
}
