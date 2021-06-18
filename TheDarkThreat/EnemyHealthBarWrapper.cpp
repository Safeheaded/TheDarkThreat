#include "EnemyHealthBarWrapper.h"

void EnemyHealthBarWrapper::animationEnd(std::vector<Entity*>* entities)
{
}

void EnemyHealthBarWrapper::draw(sf::RenderTarget& target, sf::RenderStates& states) const
{
	states.transform *= RectangleShape::getTransform();
	target.draw(*this->enemy, states);
}

EnemyHealthBarWrapper::EnemyHealthBarWrapper(sf::RenderWindow* window, std::map<std::string,
	sf::Texture*>* textures, const float& fps, Entity* enemy): Entity(textures, 1), enemy(enemy)
{
}

EnemyHealthBarWrapper::~EnemyHealthBarWrapper()
{
	delete this->enemy;
}

void EnemyHealthBarWrapper::update(const float& deltaTime, 
	std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	this->setSize({ this->enemy->getGlobalBounds().width, this->enemy->getGlobalBounds().height });
	this->enemy->update(deltaTime, entities, mapSize);
	if (this->enemy->getCanDie()) {
		this->canDie = true;
	}
}

void EnemyHealthBarWrapper::setPosition(float x, float y)
{
	RectangleShape::setPosition(x, y);
}
