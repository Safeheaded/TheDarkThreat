#include "Enemy.h"

Enemy::Enemy(std::map<std::string, sf::Texture*>* textures, const float& fps): Entity(textures, fps)
{
}

Enemy::~Enemy()
{
}
