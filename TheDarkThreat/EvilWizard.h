#pragma once
#include "Player.h"
#include "EnemyMissile.h"

class EvilWizard : public Entity
{
private:
	Player* player;
	float sightDistance;
	float attackDistance;
	sf::RenderWindow* window;
	float speed;
	EntityState prevState;

	float attackCounter;
	float attackTime;

	bool isAttacking;

	int missilesPerAttack;
	int firedMissiles;
	float missilesCounter;
	float missilesSpan;

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
	void dealDamage(const float& damage);
};

