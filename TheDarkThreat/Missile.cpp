#include "Missile.h"
#include <cmath>

void Missile::animationEnd()
{
}

Missile::Missile(
	sf::RenderWindow* window, sf::Texture* texture,
	const float& fps, const sf::Vector2f& target,
	const sf::Vector2f& pos
):
	Entity(texture, fps), window(window), speed(800), target(target), canDestroy(false)
{
	this->addAnimation(EntityState::Idle, {
		{23, 26, 53, 47},
		{122, 26, 55, 47},
		{221, 26, 56, 47},
		{320, 26, 58, 47},
		{419, 26, 53, 47},
		{518, 26, 54, 47},
		{617, 26, 55, 47},
		{725, 26, 57, 47},

		{17, 127, 53, 47},
		{116, 127, 55, 47},
		{224, 127, 56, 47},
		{323, 127, 58, 47},
		{424, 127, 53, 47},
		{524, 127, 54, 47},
		{623, 127, 55, 47},
		{723, 127, 57, 47},

		/*{23, 228, 53, 47},
		{122, 228, 55, 47},
		{221, 228, 56, 47},
		{320, 228, 58, 47},
		{419, 228, 53, 47},
		{518, 228, 54, 47},
		{617, 228, 55, 47},
		{716, 228, 57, 47},

		{23, 329, 53, 47},
		{122, 329, 55, 47},
		{221, 329, 56, 47},
		{320, 329, 58, 47},
		{419, 329, 53, 47},
		{518, 329, 54, 47},
		{617, 329, 55, 47},
		{716, 329, 57, 47},

		{23, 430, 53, 47},
		{122, 430, 55, 47},
		{221, 430, 56, 47},
		{320, 430, 58, 47},
		{419, 430, 53, 47},
		{518, 430, 54, 47},
		{617, 430, 55, 47},
		{716, 430, 57, 47},*/
		});
	this->setFirstFrame();

	this->setPosition(pos);

	auto missileBounds = this->getGlobalBounds();

	this->direction.x = this->target.x - missileBounds.left > 1 ? 1 : -1;
	this->direction.y = this->target.y - missileBounds.top > 1 ? 1 : -1;

	float yDistance = abs(target.y - missileBounds.top);
	float xDistance = abs(target.x - missileBounds.left);

	this->angle = atan(xDistance / yDistance);
}

Missile::~Missile()
{
}

void Missile::update(const float& deltaTime)
{
	auto missileBounds = this->getGlobalBounds();
	this->setOrigin(missileBounds.width/2, missileBounds.height/2);

	float yDistance = abs(target.y - missileBounds.top);
	float xDistance = abs(target.x - missileBounds.left);


	float distance = sqrt(pow(xDistance, 2) + pow(yDistance, 2));

	this->prevDirection.x = this->target.x - missileBounds.left > 1 ? 1 : -1;
	this->prevDirection.y = this->target.y - missileBounds.top > 1 ? 1 : -1;

	if (this->prevDirection != this->direction) {
		this->canDestroy = true;
	}

	this->move(
		this->direction.x * speed * deltaTime * sin(this->angle), 
		this->direction.y * speed * deltaTime * cos(this->angle)
	);

	this->animate(deltaTime);
}

const bool Missile::getCanDestroy() const
{
	return this->canDestroy;
}
