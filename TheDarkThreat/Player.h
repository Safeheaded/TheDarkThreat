#pragma once
#include "Entity.h"
#include <iostream>
#include "Utils.h"
#include "Missile.h"

class Player :
    public Entity
{
private:
    float speed;
    sf::RenderWindow* window;
    bool isRunning;
    EntityState prevState;
    float health;
    float maxHealth;
    bool canChangeState;
    sf::Texture* spellTexture;
    std::vector<Missile*>* missiles;

    // Methods
    void handleMovement(
        sf::Vector2f& velocity, const float& deltaTime, sf::FloatRect& playerBounds
    );
    void handleWindowCollision(sf::FloatRect& playerBounds);
    void setupAnimations();
    void animationEnd();
    void attack();
public:
    Player(sf::RenderWindow* window, sf::Texture* texture, 
        const float& fps, std::vector<Missile*>* missiles);
    ~Player();

    // Methods
    void update(const float& deltaTime);
    void EvaluateState(std::vector<Missile*>* missiles);
};

