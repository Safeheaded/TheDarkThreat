#include "Entity.h"

Entity::Entity(sf::Texture* texture, const float& fps, bool isBlocking, EntityState state):
	isBlocking(isBlocking), state(state), timeCounter(0), 
    timePerFrame(0), counter(0), texture(texture), canDie(false)
{
    this->timePerFrame = 1 / fps;
    this->setTexture(*this->texture);
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

void Entity::animate(const float& deltaTime)
{
	if (this->animations.count(this->state)) {
        timeCounter += deltaTime;
        if (timeCounter >= timePerFrame) {
            timeCounter -= timePerFrame;
            if (counter == this->animations[this->state].size() - 1) {
                counter = 0;
                this->animationEnd();
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
