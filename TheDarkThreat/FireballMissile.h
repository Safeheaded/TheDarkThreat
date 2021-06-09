#pragma once
#include "Missile.h"
class FireballMissile :
    public Missile
{
public:
    FireballMissile(
        sf::RenderWindow* window, sf::Texture* texture,
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos, std::vector<Entity*>* enemies
    );
    ~FireballMissile();
private:
    void customBehaviour(const float& deltaTime);
};

