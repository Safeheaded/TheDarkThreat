#include "Spell.h"

Spell::Spell(std::vector<Missile*>* missiles, const float& manaCost, 
    std::map<std::string, sf::Texture*>* textures):
    manaCost(manaCost), missiles(missiles), textures(textures)
{
}

Spell::~Spell()
{
}

const float Spell::getManaCost() const
{
    return this->manaCost;
}
