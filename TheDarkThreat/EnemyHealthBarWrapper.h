#pragma once
#include "Entity.h"
class EnemyHealthBarWrapper :
    public Entity, public sf::RectangleShape
{
private:
    void animationEnd(std::vector<Entity*>* entities);
    Entity* enemy;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates& states) const;
public:
    EnemyHealthBarWrapper(sf::RenderWindow* window, std::map<std::string, 
        sf::Texture*>* textures, const float& fps, Entity* enemy);
    ~EnemyHealthBarWrapper();

    void update(const float& deltaTime,
        std::vector<Entity*>* entities, sf::Vector2f mapSize);

    virtual void setPosition(float x, float y);
};

