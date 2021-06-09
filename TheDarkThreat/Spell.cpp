#include "Spell.h"

Spell::Spell(std::vector<Missile*>* missiles, const float& manaCost): 
    manaCost(manaCost), missiles(missiles)
{
}

Spell::~Spell()
{
}

const float Spell::getManaCost() const
{
    return this->manaCost;
}
