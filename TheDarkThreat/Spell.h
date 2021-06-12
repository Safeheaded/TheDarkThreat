#pragma once
#include "Missile.h"

class Spell
{
protected:
	float manaCost;
	std::map<std::string, sf::Texture*>* textures;
private:
	std::string name;
public:
	Spell(const float& manaCost, 
		std::map<std::string, sf::Texture*>* textures, const std::string& name);
	virtual ~Spell();

	virtual void fire(
		sf::RenderWindow* window,
		const float& fps, const sf::Vector2f& target,
		const sf::Vector2f& pos,
		std::vector<Entity*>* entities
	) = 0;
	const float getManaCost() const;

	const std::string getName() const;
};

