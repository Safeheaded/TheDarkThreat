#include "TileMap.h"

bool TileMap::load(
	const std::string& tileset, sf::Vector2u tileSize, 
	const std::vector<std::vector<int>>& tiles, std::map<std::string, 
	sf::Texture*>* textures, std::vector<Entity*>* entities,
	std::vector<Obstacle*>* obstacles, Player* player, sf::RenderWindow* window)
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

			int tu = tileNumber % (texture.getSize().x / tileSize.x);
			int tv = tileNumber / (texture.getSize().x / tileSize.x);

			if (tileNumber == 1) {
				Tree* tree = new Tree(textures, 1);
				auto treeBounds = tree->getGlobalBounds();
				tree->setPosition(
					i * tileSize.x + treeBounds.width/2, 
					j * tileSize.y + treeBounds.height / 2
				);

				// setting collider
				Obstacle* obstacle = new Obstacle({10, 10}, 
					{ 
						tree->getPosition().x + treeBounds.width/2 - 5,  
						tree->getPosition().y + treeBounds.height - 5 
					}
				);
				obstacle->setOutlineColor(sf::Color::Red);
				obstacle->setOutlineThickness(2);
				entities->emplace_back(tree);
				obstacles->emplace_back(obstacle);
			}
			else if (tileNumber == 3) {
				Wraith* wraith = new Wraith(player, window, textures, 10);
				wraith->setPosition(i * tileSize.x, j * tileSize.y);
				entities->emplace_back(wraith);
			}

			sf::Vertex* quad = &vertices[(i + j * width) * 4];

			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
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
