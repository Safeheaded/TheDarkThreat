#include "FireballSpell.h"

FireballSpell::FireballSpell(std::vector<Missile*>* missiles, 
	std::vector<Entity*>* enemies, sf::Texture* texture): Spell(missiles, enemies, 0, texture)
{
}

FireballSpell::~FireballSpell()
{
}

void FireballSpell::fire(sf::RenderWindow* window, const float& fps, const sf::Vector2f& target, const sf::Vector2f& pos)
{
	this->missiles->emplace_back(new FireballMissile(window, texture, fps, target, pos, this->enemies));
}
