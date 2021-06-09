#include "ParticleSpell.h"

ParticleSpell::ParticleSpell(
	std::vector<Missile*>* missiles, 
	std::vector<Entity*>* enemies, sf::Texture* texture
): Spell(missiles, enemies, 10, texture)
{
}

ParticleSpell::~ParticleSpell()
{
}

void ParticleSpell::fire(sf::RenderWindow* window, const float& fps, const sf::Vector2f& target, const sf::Vector2f& pos)
{
	this->missiles->emplace_back(new ParticleMissile(window, this->texture, fps, target, pos, this->enemies));
}
