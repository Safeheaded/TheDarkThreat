#pragma once
#include "Entity.h"
class Obstacle :
    public Entity
{
private:
    void animationEnd(std::vector<Entity*>* entities);
public:
    Obstacle(std::map<std::string, sf::Texture*>* textures, const float& fps);
    ~Obstacle();

    void update(const float& deltaTime,
        std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

