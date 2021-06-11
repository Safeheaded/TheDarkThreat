#pragma once
#include "Spell.h"
#include "ParticleMissile.h"
class ParticleSpell :
    public Spell
{
public:
    ParticleSpell(std::vector<Missile*>* missiles, sf::Texture* texture);
    ~ParticleSpell();

	void fire(
		sf::RenderWindow* window,
		const float& fps, const sf::Vector2f& target,
		const sf::Vector2f& pos, std::vector<Entity*>* enemies
	);
};

