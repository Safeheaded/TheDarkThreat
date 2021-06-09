#pragma once
#include "Entity.h"
#include "Missile.h"
#include "Player.h"

class Wraith :
    public Entity
{
private:
    Player* player;
    float speed;

    void animationEnd();
    float sightDistance;
    float attackDistance;
    float attackCooldown;
    float timer;
public:
    Wraith(
        Player* player,
        sf::RenderWindow* window, sf::Texture* texture,
        const float& fps, std::vector<Missile*>* missiles
    );
    ~Wraith();

    void update(const float& deltaTime);
};

