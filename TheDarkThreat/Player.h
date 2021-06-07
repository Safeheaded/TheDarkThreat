#pragma once
#include "Entity.h"
#include <iostream>
class Player :
    public Entity
{
private:
    float speed;
    sf::RenderWindow* window;
    bool isRunning;
    EntityState prevState;
public:
    Player(sf::RenderWindow* window, sf::Texture* texture, const float& fps);
    ~Player();

    void update(const float& deltaTime);
};

