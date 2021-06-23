#pragma once
#include "Entity.h"
#include "EvilWizard.h"
#include "HealthBar.h"

class Portal :
    public Entity
{
private:
    Player* player;
    sf::RenderWindow* window;

    void animationEnd(std::vector<Entity*>* entities);
public:
    Portal(
        Player* player, sf::RenderWindow* window,
        std::map<std::string, sf::Texture*>* textures,
        const float& fps);
    ~Portal();

    void update(const float& deltaTime,
        std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

