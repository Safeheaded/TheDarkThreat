#include "Skeleton.h"

void Skeleton::animationEnd(std::vector<Entity*>* entities)
{
	if (this->state == EntityState::PrimaryAttack) {
		this->player->dealDamage(3);
		this->timer = 0;
	}
}

Skeleton::Skeleton(Player* player, sf::RenderWindow* window, 
	std::map<std::string, sf::Texture*>* textures, const float& fps):
	Entity(textures, fps), player(player),
	sightDistance(300), attackDistance(10),
	speed(250), attackCooldown(4), timer(0),
	window(window), isAttacked(false), prevState(EntityState::Idle)
{
	this->maxHealth = 80;
	this->health = this->maxHealth;

	this->addAnimation(EntityState::Idle, {
		{9, 208, 33, 32},
		});
	this->addAnimation(EntityState::PrimaryAttack, {
		{8, 16, 34, 32},
		{69, 16, 37, 32},
		{129, 16, 41, 32},
		{196, 16, 38, 32},
		{269, 8, 51, 40},
		{335, 9, 31, 39},
		{401, 15, 26, 33},
		});
	this->addAnimation(EntityState::Move, {
		{5, 144, 36, 32},
		{70, 143, 35, 33},
		{134, 143, 35, 33},
		{198, 143, 35, 33},
		{261, 144, 36, 32},
		{325, 145, 36, 31},
		{389, 144, 36, 32},
		{452, 143, 38, 33},
		{516, 143, 38, 33},
		{580, 143, 38, 33},
		{645, 143, 37, 32},
		{709, 144, 37, 31},
		});
	this->setTexture(*this->textures->operator[]("SKELETON"));
	this->setFirstFrame();

	this->setScale(2, 2);
}

Skeleton::~Skeleton()
{
}

void Skeleton::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	

	sf::Vector2f velocity;

	this->animate(deltaTime, entities);

	

	auto bounds = this->getGlobalBounds();
	this->setOrigin(bounds.width / 2, bounds.height / 2);

	auto skeletonPosition = this->getPosition();

	auto playerBounds = this->player->getGlobalBounds();
	auto playerPosition = this->player->getPosition();

	auto direction = playerPosition - skeletonPosition;

	float distance = Utils::getVectorLength(direction);



	if ((distance <= this->sightDistance && distance > this->attackDistance) ||
		(isAttacked && distance > this->attackDistance)) {
		this->isAttacked = true;
		auto normalisedDirection = Utils::normalizeVector(direction);
		velocity = normalisedDirection;

		if (velocity.x < 0) {
			this->setScale(-2, 2);
		}
		else {
			this->setScale(2, 2);
		}
		this->state = EntityState::Move;
	}

	if (distance <= this->attackDistance) {

		this->state = EntityState::PrimaryAttack;
		if (this->timer >= this->attackCooldown) {
			this->timer -= this->attackCooldown;
			// Attack
		}
		else if(this->state != EntityState::PrimaryAttack) {
			this->timer += deltaTime;
		}
	}

	if (this->state != this->prevState) {
		this->counter = 0;
		this->prevState = this->state;
	}

	this->move(velocity * this->speed * deltaTime);

}

void Skeleton::dealDamage(const float& damage)
{
	this->health -= damage;
	this->isAttacked = true;
	if (this->health <= 0) {
		this->canDie = true;
	}
}
