#pragma once
#include "Player.h"
class HealthPotion :
    public Entity
{
private:
    Player* player;
    void animationEnd(std::vector<Entity*>* entities);

    void heal();
public:
    HealthPotion(std::map<std::string, sf::Texture*>* textures, const float& fps, Player* player);
    ~HealthPotion();

    void update(const float& deltaTime,
        std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

