#pragma once
#include "Missile.h"
class ParticleMissile :
    public Missile
{
private:
    void customBehaviour(const float& deltaTime);
    void customAttackBehaviour(const float& deltaTime, Entity* entity);

    float lifeTime;
    float timePassed;

    float attackTimeCounter;
    float attacksPerSecond;
public:
    ParticleMissile(
        sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos
    );
    ~ParticleMissile();
};

