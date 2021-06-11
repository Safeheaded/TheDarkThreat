#include "Spell.h"

Spell::Spell(std::vector<Missile*>* missiles, const float& manaCost, sf::Texture* texture):
    manaCost(manaCost), missiles(missiles), texture(texture)
{
}

Spell::~Spell()
{
}

const float Spell::getManaCost() const
{
    return this->manaCost;
}
