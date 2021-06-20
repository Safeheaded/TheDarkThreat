#include "OverworldMap.h"

void OverworldMap::loadEntities(unsigned int tileValue, std::vector<Entity*>* entities, sf::RenderWindow* window,
	Player* player, std::map<std::string, sf::Texture*>* textures, sf::Vector2u tileSize,
	unsigned int i, unsigned int j)
{
	if (tileValue == 1) {
		Tree* tree = new Tree(textures, 1);
		auto treeBounds = tree->getGlobalBounds();
		tree->setPosition(
			i * tileSize.x,
			j * tileSize.y
		);

		// setting collider
		/*Obstacle* obstacle = new Obstacle({ 10, 10 },
					{
						tree->getPosition().x + treeBounds.width / 2 - 5,
						tree->getPosition().y + treeBounds.height - 5
					}
					);
		obstacle->setOutlineColor(sf::Color::Red);
		obstacle->setOutlineThickness(2);*/
		entities->emplace_back(tree);
		//obstacles->emplace_back(obstacle);
	}
	else if (tileValue == 3) {
		Wraith* wraith = new Wraith(player, window, textures, 10);
		wraith->setPosition(i * tileSize.x, j * tileSize.y);
		HealthBar* health = new HealthBar(textures, 1, wraith);
		entities->insert(entities->begin(), wraith);
		entities->insert(entities->begin(), health);
	}
	else if (tileValue == 4) {
		HealthPotion* health = new HealthPotion(textures, 1, player);
		health->setPosition(i * tileSize.x, j * tileSize.y);
		entities->emplace_back(health);
	}
	else if (tileValue == 5) {
		ManaPotion* mana = new ManaPotion(textures, 1, player);
		mana->setPosition(i * tileSize.x, j * tileSize.y);
		entities->emplace_back(mana);
	}
}
