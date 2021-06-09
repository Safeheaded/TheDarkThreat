#pragma once
#include "Missile.h"
class FireballMissile :
    public Missile
{
public:
    FireballMissile(
        sf::RenderWindow* window, sf::Texture* texture,
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos
    );
    ~FireballMissile();
private:
    void customBehaviour();
};

