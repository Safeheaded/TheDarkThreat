#pragma once
#include "Entity.h"
#include <iostream>
#include "Utils.h"
#include "Missile.h"
#include "FireballSpell.h"
#include "ParticleMissile.h"
#include "ParticleSpell.h"

// This is to avoid circular dependencies (I spent like half an hour trying to figure out the errors :) )
class HealthPotion;

class Player :
    public Entity
{
private:
    float speed;
    sf::RenderWindow* window;
    bool isRunning;
    EntityState prevState;
    float mana;
    float maxMana;
    bool canChangeState;
    std::vector<Spell*> spells;
    std::vector<Entity*>* entities;
    int selectedSpell;
    sf::Vector2f target;
    friend class HealthPotion;

    // Methods
    void handleMovement(
        sf::Vector2f& velocity, const float& deltaTime, sf::FloatRect& playerBounds
    );
    void handleVoidCollision(sf::FloatRect& playerBounds, const sf::Vector2f& mapSize);
    void setupAnimations();
    void animationEnd(std::vector<Entity*>* entities);
    void attack(std::vector<Entity*>* entities);
public:
    Player(sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
        const float& fps);
    ~Player();

    // Methods
    void update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize);
    void EvaluateState(std::vector<Entity*>* entities);
    void dealDamage(const float& damage);

    const float getMana() const;
    const float getMaxMana() const;
    const std::string getSpellName() const;
};

