#pragma once
#include "Missile.h"
class EnemyMissile :
    public Missile
{
private:

    void animationEnd();
    void customBehaviour(const float& deltaTime);
public:
    EnemyMissile(
        sf::RenderWindow* window, sf::Texture* texture,
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos
    );
    ~EnemyMissile();
};

