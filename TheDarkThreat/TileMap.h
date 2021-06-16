#pragma once
#include "Obstacle.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
private:
    sf::Vector2f size;
public:
    const sf::Vector2f getSize() const;

    bool load(
        const std::string& tileset, sf::Vector2u tileSize,
        const int* tiles, unsigned int width, unsigned int height,
        std::map<std::string, sf::Texture*>* textures, std::vector<Entity*>* entities
    );

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};