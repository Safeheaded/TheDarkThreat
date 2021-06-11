#include "FireballSpell.h"

FireballSpell::FireballSpell(std::vector<Missile*>* missiles, std::map<std::string, 
	sf::Texture*>* textures): 
	Spell(missiles, 0, textures)
{
}

FireballSpell::~FireballSpell()
{
}

void FireballSpell::fire(sf::RenderWindow* window, const float& fps, const sf::Vector2f& target, 
	const sf::Vector2f& pos, std::vector<Entity*>* enemies)
{
	this->missiles->emplace_back(new FireballMissile(window, textures, fps, target, pos));
}
