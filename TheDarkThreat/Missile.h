#pragma once
#include "Entity.h"
class Missile :
    public Entity
{
protected:
    sf::Window* window;
    float speed;
    sf::Vector2f target;
    sf::Vector2f direction;
    sf::Vector2f initialPosition;
    std::vector<Entity*>* enemies;
    float damage;

    void animationEnd();
    virtual void customBehaviour(const float& deltaTime) = 0;
public:
    Missile(
        sf::RenderWindow* window, sf::Texture* texture, 
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos, std::vector<Entity*>* enemies
    );
    ~Missile();
    void update(const float& deltaTime);
};

