#include "Entity.h"

Entity::Entity(std::map<std::string, sf::Texture*>* textures, const float& fps, bool isBlocking, EntityState state):
	isBlocking(isBlocking), state(state), timeCounter(0), 
    timePerFrame(0), counter(0), textures(textures), canDie(false), health(100), maxHealth(100)
{
    this->timePerFrame = 1 / fps;
}

const bool Entity::getIsBlocking() const
{
	return this->isBlocking;
}

const EntityState Entity::getState() const
{
	return this->state;
}

void Entity::addAnimation(EntityState state, const std::vector<sf::IntRect>& frames)
{
	this->animations.emplace(state, frames);
}

void Entity::animate(const float& deltaTime, std::vector<Entity*>* entities)
{
	if (this->animations.count(this->state)) {
        timeCounter += deltaTime;
        if (timeCounter >= timePerFrame) {
            timeCounter -= timePerFrame;
            if (counter == this->animations[this->state].size() - 1) {
                counter = 0;
                this->animationEnd(entities);
            }
            else {
                counter++;
            }
            this->setTextureRect(this->animations[this->state][counter]);
        }
	}
}

void Entity::setFirstFrame()
{
    if (this->animations.count(this->state)) {
        this->setTextureRect(this->animations[this->state][0]);
    }
}

void Entity::dealDamage(const float& damage)
{
}

const bool Entity::getCanDie() const
{
    return this->canDie;
}

const float Entity::getHealth() const 
{
    return this->health;
}

const float Entity::getMaxHealth() const
{
    return this->maxHealth;
}