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

    void animationEnd(std::vector<Entity*>* entities);
    float sightDistance;
    float attackDistance;
    float attackCooldown;
    float timer;
    float health;
    std::vector<Missile*>* missiles;
    sf::RenderWindow* window;
    sf::Texture* attackTexture;
    std::vector<Entity*> enemy;
public:
    Wraith(
        Player* player,
        sf::RenderWindow* window, sf::Texture* texture,
        const float& fps, std::vector<Missile*>* missiles
    );
    ~Wraith();

    void update(const float& deltaTime, std::vector<Entity*>* entities);
    void dealDamage(const float& damage);
};

