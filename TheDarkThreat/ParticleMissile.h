#pragma once
#include "Missile.h"
class ParticleMissile :
    public Missile
{
private:
    void customBehaviour(const float& deltaTime);
    float lifeTime;
    float timePassed;
public:
    ParticleMissile(
        sf::RenderWindow* window, sf::Texture* texture,
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos, std::vector<Entity*>* enemies
    );
    ~ParticleMissile();
};

