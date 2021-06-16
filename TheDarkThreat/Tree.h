#pragma once
#include "Entity.h"
class Tree :
    public Entity
{
private:
    void animationEnd(std::vector<Entity*>* entities);
public:
    Tree(std::map<std::string, sf::Texture*>* textures, const float& fps);
    ~Tree();

    void update(const float& deltaTime,
        std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

