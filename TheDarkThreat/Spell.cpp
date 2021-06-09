#include "Spell.h"

Spell::Spell(std::vector<Missile*>* missiles, std::vector<Entity*>* enemies, const float& manaCost, sf::Texture* texture):
    manaCost(manaCost), missiles(missiles), texture(texture), enemies(enemies)
{
}

Spell::~Spell()
{
}

const float Spell::getManaCost() const
{
    return this->manaCost;
}
