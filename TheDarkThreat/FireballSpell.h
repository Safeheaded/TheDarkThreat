#pragma once
#include "Spell.h"
#include "FireballMissile.h"
class FireballSpell :
    public Spell
{
public:
	FireballSpell(std::vector<Missile*>* missiles, 
		std::vector<Entity*>* enemies, sf::Texture* texture);
	~FireballSpell();
	void fire(
		sf::RenderWindow* window,
		const float& fps, const sf::Vector2f& target,
		const sf::Vector2f& pos
	);
};

