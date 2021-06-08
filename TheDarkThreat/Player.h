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

    // Methods
    void handleMovement(
        sf::Vector2f& velocity, const float& deltaTime, sf::FloatRect& playerBounds
    );
    void handleWindowCollision(sf::FloatRect& playerBounds);
public:
    Player(sf::RenderWindow* window, sf::Texture* texture, const float& fps);
    ~Player();

    // Methods
    void update(const float& deltaTime);
    void EvaluateState();
};

