#include "FireballSpell.h"

FireballSpell::FireballSpell(std::map<std::string, 
	sf::Texture*>* textures): 
	Spell(0, textures)
{
}

FireballSpell::~FireballSpell()
{
}

void FireballSpell::fire(sf::RenderWindow* window, const float& fps, const sf::Vector2f& target, 
	const sf::Vector2f& pos, std::vector<Entity*>* entities)
{
	entities->emplace_back(new FireballMissile(window, textures, fps, target, pos));
}
