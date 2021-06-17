#pragma once
#include "Tree.h"
#include "Obstacle.h"
#include "Player.h"
#include "Wraith.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
private:
    sf::Vector2f size;
public:
    const sf::Vector2f getSize() const;

    bool load(
        const std::string& path, sf::Vector2u tileSize,
        const std::vector<std::vector<int>>& tiles,
        std::map<std::string, sf::Texture*>* textures, std::vector<Entity*>* entities,
        std::vector<Obstacle*>* obstacles, Player* player, sf::RenderWindow* window
    );

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void loadEntities(
        unsigned int tileValue, std::vector<Entity*>* entities, sf::RenderWindow* window,
        Player* player, std::map<std::string, sf::Texture*>* textures, sf::Vector2u tileSize,
        unsigned int i, unsigned int j
    ) = 0;

    sf::VertexArray vertices;
    sf::Texture texture;
};