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

    sf::VertexArray vertices;
    sf::Texture texture;
};