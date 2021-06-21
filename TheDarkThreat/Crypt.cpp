#include "Crypt.h"

void Crypt::animationEnd(std::vector<Entity*>* entities)
{
}

Crypt::Crypt(std::map<std::string, sf::Texture*>* textures, Player* player):
	Entity(textures, 1), player(player)
{
	this->setTexture(*this->textures->operator[]("CEMETERY"));
	this->setTextureRect({134, 3, 55, 51});
	this->setScale(3, 3);
}

Crypt::~Crypt()
{
}

void Crypt::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	auto playerBounds = this->player->getGlobalBounds();
	auto bounds = this->getGlobalBounds();

	// Checking if there are any enemies
	auto areEnemies = std::find_if(entities->begin(), entities->end(), [](Entity* entity) {
		return typeid(*entity) == typeid(Wraith);
		});


	if (areEnemies == std::end(*entities) && bounds.intersects(playerBounds)) {
		std::cout << "You Won 1st Level" << std::endl;
	}
}
