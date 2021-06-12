#pragma once
#include "Spell.h"
#include "FireballMissile.h"
class FireballSpell :
    public Spell
{
public:
	FireballSpell(std::map<std::string, sf::Texture*>* textures, const std::string& name);
	~FireballSpell();
	void fire(
		sf::RenderWindow* window,
		const float& fps, const sf::Vector2f& target,
		const sf::Vector2f& pos, std::vector<Entity*>* entities
	);
};

