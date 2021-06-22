#include "Crypt.h"

void Crypt::animationEnd(std::vector<Entity*>* entities)
{
}

Crypt::Crypt(std::map<std::string, sf::Texture*>* textures, Player* player):
	Entity(textures, 1), player(player), isNextLevel(false)
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

	// Finished level 
	if (areEnemies == std::end(*entities) && bounds.intersects(playerBounds)) {
		isNextLevel = true;
	}
	// if player enters crypt, all enemies attack
	else if (areEnemies != std::end(*entities) && bounds.intersects(playerBounds)) {
		for (auto& entity : *entities) {
			Wraith* wraith = dynamic_cast<Wraith*>(entity);
			if (wraith != nullptr) {
				wraith->isAttacked = true;
			}
		}
	}
}

const bool Crypt::getIsNextLevel()
{
	return this->isNextLevel;
}
