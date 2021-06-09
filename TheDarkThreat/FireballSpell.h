#pragma once
#include "Spell.h"
#include "FireballMissile.h"
class FireballSpell :
    public Spell
{
public:
	FireballSpell(std::vector<Missile*>* missiles);
	~FireballSpell();
	void fire(
		sf::RenderWindow* window, sf::Texture* texture,
		const float& fps, const sf::Vector2f& target,
		const sf::Vector2f& pos
	);
};

