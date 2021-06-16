#pragma once
#include "Entity.h"

// Missile type relative to player
enum class MissileType {
    Friendly,
    Hostile
};

class Missile :
    public Entity
{
protected:
    sf::Window* window;
    float speed;
    sf::Vector2f target;
    sf::Vector2f direction;
    sf::Vector2f initialPosition;
    float damage;
    MissileType type;

    void animationEnd(std::vector<Entity*>* entities);
    virtual void customBehaviour(const float& deltaTime) = 0;
    virtual void customAttackBehaviour(const float& deltaTime, Entity* entity) = 0;
public:
    Missile(
        sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
        const float& fps, const sf::Vector2f& target,
        const sf::Vector2f& pos
    );
    ~Missile();
    void update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize);
};

