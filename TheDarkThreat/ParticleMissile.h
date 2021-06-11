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
        sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos
    );
    ~ParticleMissile();
};

