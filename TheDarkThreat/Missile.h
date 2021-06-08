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
    sf::Vector2i direction;
    sf::Vector2i prevDirection;
    float angle;

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

