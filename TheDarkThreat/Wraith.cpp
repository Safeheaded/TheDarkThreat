#include "Wraith.h"

void Wraith::animationEnd()
{
}

Wraith::Wraith(
	Player* player,
	sf::RenderWindow* window, sf::Texture* texture, 
	const float& fps, std::vector<Missile*>* missiles
): Entity(texture, fps), player(player), 
sightDistance(500), attackDistance(200), speed(150), attackCooldown(4), timer(attackCooldown)
{
	this->addAnimation(EntityState::Idle, {
		{34, 21, 45, 62},
		{134, 21, 45, 62},
		{234, 21, 45, 62},
		{334, 21, 45, 62},
		{34, 121, 45, 62},
		{34, 121, 45, 62},
		{34, 121, 45, 62},
		{34, 121, 45, 62},
		});
	this->setFirstFrame();
}

Wraith::~Wraith()
{
}

void Wraith::update(const float& deltaTime)
{
	sf::Vector2f velocity;

	this->animate(deltaTime);

	auto wraithPosition = this->getPosition();

	auto playerBounds = this->player->getGlobalBounds();
	auto playerPosition = this->player->getPosition();

	auto direction = playerPosition - wraithPosition;
	
	float distance = Utils::getVectorLength(direction);

	if (distance <= this->sightDistance && distance > this->attackDistance) {
		auto normalisedDirection = Utils::normalizeVector(direction);
		velocity = normalisedDirection;
		if (this->timer <= this->attackCooldown) {
			this->timer += deltaTime;
		}
	}
	else if (distance <= this->attackDistance) {
		if (this->timer >= this->attackCooldown) {
			this->timer -= this->attackCooldown;
			
			std::cout << "ATTACK" << std::endl;
		}
		else {
			this->timer += deltaTime;
		}
	}

	this->move(velocity * this->speed * deltaTime);
}
