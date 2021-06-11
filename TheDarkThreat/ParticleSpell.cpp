#include "ParticleSpell.h"

ParticleSpell::ParticleSpell(
	std::vector<Missile*>* missiles, sf::Texture* texture
): Spell(missiles, 10, texture)
{
}

ParticleSpell::~ParticleSpell()
{
}

void ParticleSpell::fire(
	sf::RenderWindow* window, const float& fps, const sf::Vector2f& target, 
	const sf::Vector2f& pos, std::vector<Entity*>* enemies)
{
	this->missiles->emplace_back(new ParticleMissile(window, this->texture, fps, target, pos));
}
