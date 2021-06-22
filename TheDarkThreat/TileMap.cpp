#include "TileMap.h"

bool TileMap::load(
	const std::string& tileset, sf::Vector2u tileSize, 
	const std::vector<std::vector<int>>& tiles, std::map<std::string, 
	sf::Texture*>* textures, std::vector<Entity*>* entities,
	std::vector<Obstacle*>* obstacles, Player* player, sf::RenderWindow* window, 
	const sf::Vector2i& textureOffset)
{
	const unsigned int height = tiles.size();
	const unsigned int width = tiles[0].size();
	this->size = { (float)(tileSize.x * tiles[0].size()), (float)(tileSize.y * tiles.size()) };
	if (!texture.loadFromFile(tileset))
		return false;

	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(width * height * 4);

	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			int tileNumber = tiles[j][i];

			sf::IntRect textureArea(textureOffset, (sf::Vector2i)tileSize);

			this->loadEntities(tileNumber, entities, window, player, textures, tileSize, i, j);

			sf::Vertex* quad = &vertices[(i + j * width) * 4];

			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			quad[0].texCoords = sf::Vector2f(textureArea.left, textureArea.top);
			quad[1].texCoords = sf::Vector2f(textureArea.width, textureArea.top);
			quad[2].texCoords = sf::Vector2f(textureArea.width, textureArea.height);
			quad[3].texCoords = sf::Vector2f(textureArea.left, textureArea.height);
		}

	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	    states.transform *= getTransform();
	    states.texture = &texture;
	    target.draw(vertices, states);
}

const sf::Vector2f TileMap::getSize() const {
	return this->size;
}
