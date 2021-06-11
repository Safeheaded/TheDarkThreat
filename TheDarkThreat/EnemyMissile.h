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
        sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos
    );
    ~EnemyMissile();
};

