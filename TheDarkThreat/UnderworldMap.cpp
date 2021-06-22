#include "UnderworldMap.h"

void UnderworldMap::loadEntities(unsigned int tileValue, std::vector<Entity*>* entities, 
	sf::RenderWindow* window, Player* player, std::map<std::string, sf::Texture*>* textures, 
	sf::Vector2u tileSize, unsigned int i, unsigned int j)
{
	if (tileValue == 1) {
		Wraith* wraith = new Wraith(player, window, textures, 10);
		wraith->setPosition(i * tileSize.x, j * tileSize.y);
		HealthBar* health = new HealthBar(textures, 1, wraith);
		entities->insert(entities->begin(), wraith);
		entities->insert(entities->begin(), health);
	}
	else if (tileValue == 2) {
		Skeleton* skeleton = new Skeleton(player, window, textures, 10);
		skeleton->setPosition(i * tileSize.x, j * tileSize.y); 
		HealthBar* health = new HealthBar(textures, 1, skeleton);
		entities->insert(entities->begin(), skeleton);
		entities->insert(entities->begin(), health);
	}
	else if (tileValue == 3) {
		// resp health potion
	}
	else if (tileValue == 4) {
		// resp mana potion
	}
}
