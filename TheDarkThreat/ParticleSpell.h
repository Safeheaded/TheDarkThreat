#pragma once
#include "Spell.h"
#include "ParticleMissile.h"
class ParticleSpell :
    public Spell
{
public:
    ParticleSpell(std::vector<Missile*>* missiles, 
		std::vector<Entity*>* enemies, sf::Texture* texture);
    ~ParticleSpell();

	void fire(
		sf::RenderWindow* window,
		const float& fps, const sf::Vector2f& target,
		const sf::Vector2f& pos
	);
};

