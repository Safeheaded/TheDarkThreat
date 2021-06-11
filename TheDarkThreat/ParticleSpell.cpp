#include "ParticleSpell.h"

ParticleSpell::ParticleSpell(
	std::vector<Missile*>* missiles, std::map<std::string, sf::Texture*>* textures
): Spell(missiles, 10, textures)
{
}

ParticleSpell::~ParticleSpell()
{
}

void ParticleSpell::fire(
	sf::RenderWindow* window, const float& fps, const sf::Vector2f& target, 
	const sf::Vector2f& pos, std::vector<Entity*>* enemies)
{
	this->missiles->emplace_back(new ParticleMissile(
		window, this->textures, fps, target, pos
	));
}
