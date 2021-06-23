#include "EvilWizard.h"

void EvilWizard::animationEnd(std::vector<Entity*>* entities)
{

}

EvilWizard::EvilWizard(Player* player, sf::RenderWindow* window,
	std::map<std::string, sf::Texture*>* textures, const float& fps) :
	Entity(textures, fps), player(player), window(window), speed(100), sightDistance(500),
	attackDistance(100), prevState(EntityState::Idle), attackTime(4), attackCounter(0), 
	isAttacking(false), missilesPerAttack(4), missilesCounter(0), missilesSpan(0.4), firedMissiles(0)
{
	this->maxHealth = 800;
	this->health = this->maxHealth;

	this->setTexture(*this->textures->operator[]("WIZARD"));

	this->addAnimation(EntityState::Idle, {
		{108, 72, 57, 104},
		{358, 72, 57, 104},
		{608, 72, 57, 104},
		{858, 72, 57, 104},
		{1108, 72, 57, 104},
		{1358, 72, 57, 104},
		{1608, 72, 57, 104},
		{1858, 72, 57, 104},
		});

	this->setFirstFrame();

	this->setScale(2, 2);
}

EvilWizard::~EvilWizard()
{
}

void EvilWizard::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	sf::Vector2f velocity;

	this->animate(deltaTime, entities);

	auto bounds = this->getGlobalBounds();
	//this->setOrigin(bounds.width / 2, bounds.height / 2);

	auto wraithPosition = this->getPosition();

	auto playerBounds = this->player->getGlobalBounds();
	auto playerPosition = this->player->getPosition();

	auto direction = playerPosition - wraithPosition;

	float distance = Utils::getVectorLength(direction);

	if (distance > this->attackDistance) {
		auto normalisedDirection = Utils::normalizeVector(direction);
		velocity = normalisedDirection;
	}

	if (this->attackCounter >= this->attackTime && !this->isAttacking) {
		this->attackCounter = 0;
		this->isAttacking = true;
	}
	else if(!this->isAttacking)  {
		this->attackCounter += deltaTime;
	}

	if (this->isAttacking) {
		if (this->missilesCounter >= this->missilesSpan) {
			this->firedMissiles += 1;
			this->missilesCounter -= this->missilesSpan;
			
			entities->emplace_back(
				new EnemyMissile(
					this->window,
					this->textures,
					20.0f,
					playerPosition,
					wraithPosition
				)
			);

			if (this->firedMissiles == this->missilesPerAttack) {
				this->firedMissiles = 0;
				this->isAttacking = false;
			}
		}
		else {
			this->missilesCounter += deltaTime;
		}
	}

	if (this->getPosition().x - bounds.width < 0) {
		this->setPosition(bounds.width, this->getPosition().y);
	}
	if (this->getPosition().y - bounds.height < 0) {
		this->setPosition(this->getPosition().x, bounds.height);
	}
	if (this->getPosition().x + bounds.width > mapSize.x) {
		this->setPosition(mapSize.x - bounds.width, this->getPosition().y);
	}
	if (this->getPosition().y + bounds.height > mapSize.y) {
		this->setPosition(this->getPosition().x, mapSize.y - bounds.height);
	}

	this->move(velocity * this->speed * deltaTime);
}

void EvilWizard::dealDamage(const float& damage)
{
	this->health -= damage;
	if (this->health <= 0) {
		this->canDie = true;
	}
}
