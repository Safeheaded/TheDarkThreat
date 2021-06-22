#pragma once
#include "Player.h"
class Skeleton :
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
    EntityState prevState;

    sf::RenderWindow* window;

    bool isAttacked;
public:
    Skeleton(
        Player* player,
        sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
        const float& fps);
    ~Skeleton();

    void update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize);
    void dealDamage(const float& damage);
};

