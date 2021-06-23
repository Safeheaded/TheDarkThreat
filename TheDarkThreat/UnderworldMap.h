#pragma once
#include "TileMap.h"
#include "HealthBar.h"
#include "Skeleton.h"
#include "Spikes.h"

class UnderworldMap :
    public TileMap
{
private:
    void loadEntities(unsigned int tileValue, std::vector<Entity*>* entities, sf::RenderWindow* window,
        Player* player, std::map<std::string, sf::Texture*>* textures, sf::Vector2u tileSize,
        unsigned int i, unsigned int j);
};

