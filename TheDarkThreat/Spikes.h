#pragma once
#include "Player.h"
class Spikes :
    public Entity
{
private:
    float timer;
    float timeToAttack;
    EntityState prevState;

    void animationEnd(std::vector<Entity*>* entities);
public:
    Spikes(
        Player* player,
        sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
        const float& fps);
    ~Spikes();

    void update(const float& deltaTime,
        std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

