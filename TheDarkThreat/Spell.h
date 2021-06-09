#pragma once
#include "Missile.h"

class Spell
{
protected:
	float manaCost;
	std::vector<Missile*>* missiles;
	std::vector<Entity*>* enemies;
	sf::Texture* texture;
public:
	Spell(std::vector<Missile*>* missiles, std::vector<Entity*>* enemies, const float& manaCost, sf::Texture* texture);
	virtual ~Spell();

	virtual void fire(
		sf::RenderWindow* window,
		const float& fps, const sf::Vector2f& target,
		const sf::Vector2f& pos
	) = 0;
	const float getManaCost() const;
};

