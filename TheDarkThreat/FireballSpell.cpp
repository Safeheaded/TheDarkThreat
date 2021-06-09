#include "FireballSpell.h"

FireballSpell::FireballSpell(std::vector<Missile*>* missiles): Spell(missiles, 0)
{
}

FireballSpell::~FireballSpell()
{
}

void FireballSpell::fire(sf::RenderWindow* window, sf::Texture* texture, const float& fps, const sf::Vector2f& target, const sf::Vector2f& pos)
{
	this->missiles->emplace_back(new Missile(window, texture, fps, target, pos));
}
