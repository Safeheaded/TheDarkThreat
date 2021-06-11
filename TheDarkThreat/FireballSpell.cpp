#include "FireballSpell.h"

FireballSpell::FireballSpell(std::vector<Missile*>* missiles, sf::Texture* texture): Spell(missiles, 0, texture)
{
}

FireballSpell::~FireballSpell()
{
}

void FireballSpell::fire(sf::RenderWindow* window, const float& fps, const sf::Vector2f& target, 
	const sf::Vector2f& pos, std::vector<Entity*>* enemies)
{
	this->missiles->emplace_back(new FireballMissile(window, texture, fps, target, pos));
}
