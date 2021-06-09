#pragma once
#include "Entity.h"
class Missile :
    public Entity
{
private:
    sf::Window* window;
    float speed;
    sf::Vector2f target;
    bool canDestroy;
    sf::Vector2f direction;
    sf::Vector2f initialPosition;

    void animationEnd();
public:
    Missile(
        sf::RenderWindow* window, sf::Texture* texture, 
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos
    );
    ~Missile();
    void update(const float& deltaTime);
    
    const bool getCanDestroy() const;
};

