#pragma once
#include "Entity.h"
class Cemetery :
    public Entity
{
private:
    void animationEnd(std::vector<Entity*>* entities);
public:
    Cemetery(std::map<std::string, sf::Texture*>* textures);
    ~Cemetery();

    void update(const float& deltaTime,
        std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

