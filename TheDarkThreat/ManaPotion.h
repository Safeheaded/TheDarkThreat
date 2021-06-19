#pragma once
#include "Player.h"
class ManaPotion :
    public Entity
{
private:
    Player* player;

    void animationEnd(std::vector<Entity*>* entities);
    void refillMana();
public:
    ManaPotion(std::map<std::string, sf::Texture*>* textures, const float& fps, Player* player);
    ~ManaPotion();

    void update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

