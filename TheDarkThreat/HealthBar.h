#pragma once
#include "Wraith.h"
class HealthBar :
    public Entity
{
private:
    Entity* entity;
    float maxWidth;

    void animationEnd(std::vector<Entity*>* entities);
public:
    HealthBar(std::map<std::string, sf::Texture*>* textures, const float& fps, Entity* entity);
    ~HealthBar();

    void update(const float& deltaTime,
        std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

