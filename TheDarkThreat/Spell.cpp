#include "Spell.h"

Spell::Spell(const float& manaCost, 
    std::map<std::string, sf::Texture*>* textures):
    manaCost(manaCost), textures(textures)
{
}

Spell::~Spell()
{
}

const float Spell::getManaCost() const
{
    return this->manaCost;
}
