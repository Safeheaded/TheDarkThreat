#include "Spell.h"

Spell::Spell(const float& manaCost, 
    std::map<std::string, sf::Texture*>* textures, const std::string& name):
    manaCost(manaCost), textures(textures), name(name)
{
}

Spell::~Spell()
{
}

const float Spell::getManaCost() const
{
    return this->manaCost;
}

const std::string Spell::getName() const
{
    return this->name;
}
