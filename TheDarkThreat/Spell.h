#pragma once
#include "Missile.h"

class Spell
{
protected:
	float manaCost;
	std::vector<Missile*>* missiles;
public:
	Spell(std::vector<Missile*>* missiles, const float& manaCost);
	virtual ~Spell();

	virtual void fire(
		sf::RenderWindow* window, sf::Texture* texture,
		const float& fps, const sf::Vector2f& target,
		const sf::Vector2f& pos
	) = 0;
	const float getManaCost() const;
};

