#include "Spikes.h"

void Spikes::animationEnd(std::vector<Entity*>* entities)
{
	if (this->state == EntityState::PrimaryAttack) {
		this->state = EntityState::Idle;
	}
}

Spikes::Spikes(Player* player, sf::RenderWindow* window, 
	std::map<std::string, sf::Texture*>* textures, const float& fps): 
	Entity(textures, fps), timer(0), timeToAttack(3), prevState(EntityState::Idle)
{
	this->setTexture(*this->textures->operator[]("SPIKES"));
	this->addAnimation(EntityState::Idle, {
		{0, 0, 32, 32},
		});
	this->addAnimation(EntityState::PrimaryAttack, {
		{0, 0, 32, 32},
		{32, 0, 32, 32},
		{64, 0, 32, 32},
		{96, 0, 32, 32},
		{128, 0, 32, 32},
		{160, 0, 32, 32},
		{192, 0, 32, 32},
		{224, 0, 32, 32},
		{256, 0, 32, 32},
		{288, 0, 32, 32},
		{320, 0, 32, 32},
		{352, 0, 32, 32},
		{416, 0, 32, 32},
		});
	this->setFirstFrame();
	this->setScale(2, 2);
}

Spikes::~Spikes()
{
}

void Spikes::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	this->animate(deltaTime, entities);

	if (this->timer >= this->timeToAttack) {
		this->timer = 0;

		this->state = EntityState::PrimaryAttack;
	}
	else if (this->state == EntityState::Idle) {
		this->timer += deltaTime;
	}

	if (this->state != this->prevState) {
		this->counter = 0;
		this->prevState = this->state;
	}
}
