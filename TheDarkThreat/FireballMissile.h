#pragma once
#include "Missile.h"
class FireballMissile :
    public Missile
{
public:
    FireballMissile(
        sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos
    );
    ~FireballMissile();
private:
    void customBehaviour(const float& deltaTime);
};

