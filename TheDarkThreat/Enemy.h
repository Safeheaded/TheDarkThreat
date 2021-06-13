#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
protected:
    void animationEnd(std::vector<Entity*>* entities) = 0;
public:
    Enemy(std::map<std::string, sf::Texture*>* textures, const float& fps);
    virtual ~Enemy();

    virtual void update(const float& deltaTime, std::vector<Entity*>* entities) = 0;
};

