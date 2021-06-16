#include "TileMap.h"

bool TileMap::load(
	const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, 
	unsigned int width, unsigned int height, std::map<std::string, 
	sf::Texture*>* textures, std::vector<Entity*>* entities,
	std::vector<Obstacle*>* obstacles)
{
	this->size = { (float)(tileSize.x * width), (float)(tileSize.y * height) };
	// load the tileset texture
	if (!m_tileset.loadFromFile(tileset))
		return false;

	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// get the current tile number
			int tileNumber = tiles[i + j * width];

			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			if (tileNumber == 1) {
				Tree* tree = new Tree(textures, 1);
				tree->setPosition(i * tileSize.x, j * tileSize.y);
				Obstacle* obstacle = new Obstacle({100, 100}, tree->getPosition());
				entities->emplace_back(tree);
				obstacles->emplace_back(obstacle);
			}

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	    // apply the transform
	    states.transform *= getTransform();

	    // apply the tileset texture
	    states.texture = &m_tileset;

	    // draw the vertex array
	    target.draw(m_vertices, states);
}

const sf::Vector2f TileMap::getSize() const {
	return this->size;
}
