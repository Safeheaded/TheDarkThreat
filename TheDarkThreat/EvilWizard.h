#pragma once
#include "Player.h"

class EvilWizard : public Entity
{
private:
	Player* player;
	float sightDistance;
	float attackDistance;
	sf::RenderWindow* window;
	float speed;

	void animationEnd(std::vector<Entity*>* entities);
public:
	EvilWizard(
		Player* player,
		sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
		const float& fps
	);
	~EvilWizard();

	void update(const float& deltaTime,
		std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

