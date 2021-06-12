#pragma once
#include "Spell.h"
#include "ParticleMissile.h"
class ParticleSpell :
    public Spell
{
public:
    ParticleSpell(std::map<std::string, sf::Texture*>* textures, const std::string& name);
    ~ParticleSpell();

	void fire(
		sf::RenderWindow* window,
		const float& fps, const sf::Vector2f& target,
		const sf::Vector2f& pos, std::vector<Entity*>* entities
	);
};

