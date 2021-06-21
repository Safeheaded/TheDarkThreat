#pragma once
#include "Player.h"
#include "Wraith.h"

class Crypt :
    public Entity
{
private:
    Player* player;

    void animationEnd(std::vector<Entity*>* entities);
public:
    Crypt(std::map<std::string, sf::Texture*>* textures, Player* player);
    ~Crypt();

    void update(const float& deltaTime,
        std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

