#pragma once
#include "Missile.h"

class Spell
{
protected:
	float manaCost;
	std::vector<Missile*>* missiles;
	std::map<std::string, sf::Texture*>* textures;
public:
	Spell(std::vector<Missile*>* missiles, const float& manaCost, 
		std::map<std::string, sf::Texture*>* textures);
	virtual ~Spell();

	virtual void fire(
		sf::RenderWindow* window,
		const float& fps, const sf::Vector2f& target,
		const sf::Vector2f& pos,
		std::vector<Entity*>* enemies
	) = 0;
	const float getManaCost() const;
};

