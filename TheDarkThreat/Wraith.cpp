#include "Wraith.h"
#include "EnemyMissile.h"

void Wraith::animationEnd(std::vector<Entity*>* entities)
{
}

Wraith::Wraith(
	Player* player,
	sf::RenderWindow* window, std::map<std::string, sf::Texture*>* textures,
	const float& fps
) : Entity(textures, fps), player(player),
sightDistance(300), attackDistance(150),
speed(150), attackCooldown(4), timer(attackCooldown),
window(window), isAttacked(false), timeToAttack(1), toAttackTimer(0)
{
	this->maxHealth = 200;
	this->health = this->maxHealth;

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
	this->setTexture(*this->textures->operator[]("WRAITH"));
	this->setFirstFrame();
}

Wraith::~Wraith(){
}

void Wraith::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	sf::Vector2f velocity;

	this->animate(deltaTime, entities);

	auto wraithPosition = this->getPosition();

	auto playerBounds = this->player->getGlobalBounds();
	auto playerPosition = this->player->getPosition();

	auto direction = playerPosition - wraithPosition;
	
	float distance = Utils::getVectorLength(direction);

	if ((distance <= this->sightDistance && distance > this->attackDistance) || 
		(isAttacked && distance > this->attackDistance)) {
		this->isAttacked = true;
		auto normalisedDirection = Utils::normalizeVector(direction);
		velocity = normalisedDirection;
		// waits before attacking
		if (this->toAttackTimer < this->timeToAttack) {
			this->toAttackTimer += deltaTime;
		}
		
	}
	if (distance <= this->sightDistance) {
		if (this->timer >= this->attackCooldown && this->toAttackTimer >= this->timeToAttack) {
			this->timer -= this->attackCooldown;
			entities->emplace_back(
				new EnemyMissile(
					this->window,
					this->textures,
					20.0f,
					playerPosition,
					wraithPosition
				)
			);
		}
		else {
			this->timer += deltaTime;
		}
	}

	this->move(velocity * this->speed * deltaTime);
}

void Wraith::dealDamage(const float& damage)
{
	this->isAttacked = true;
	this->health -= damage;
	if (this->health <= 0) {
		this->canDie = true;
	}
}