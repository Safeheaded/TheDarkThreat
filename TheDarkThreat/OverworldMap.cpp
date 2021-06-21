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
		entities->emplace_back(tree);
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
	else if (tileValue == 6) {
		Crypt* crypt = new Crypt(textures, player);
		crypt->setPosition(i * tileSize.x, j * tileSize.y);
		entities->insert(entities->begin(), crypt);
	}
	else if (tileValue == 7) {
		Cemetery* cemetery = new Cemetery(textures);
		cemetery->setPosition(i * tileSize.x, j * tileSize.y);
		entities->insert(entities->begin(), cemetery);
	}
}
