#include "ParticleSpell.h"

ParticleSpell::ParticleSpell(
	std::map<std::string, sf::Texture*>* textures
): Spell(10, textures)
{
}

ParticleSpell::~ParticleSpell()
{
}

void ParticleSpell::fire(
	sf::RenderWindow* window, const float& fps, const sf::Vector2f& target, 
	const sf::Vector2f& pos, std::vector<Entity*>* entities)
{
	entities->emplace_back(new ParticleMissile(
		window, this->textures, fps, target, pos
	));
}
