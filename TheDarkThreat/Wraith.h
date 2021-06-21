#pragma once
#include "Entity.h"
#include "Missile.h"
#include "Player.h"

class Crypt;

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

    float timeToAttack;
    float toAttackTimer;
    sf::RenderWindow* window;

    bool isAttacked;
    friend class Crypt;
public:
    Wraith(
        Player* player,
        sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
        const float& fps
    );
    ~Wraith();

    void update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize);
    void dealDamage(const float& damage);
};

