#include "EvilWizard.h"

void EvilWizard::animationEnd(std::vector<Entity*>* entities)
{
}

EvilWizard::EvilWizard(Player* player, sf::RenderWindow* window,
	std::map<std::string, sf::Texture*>* textures, const float& fps) :
	Entity(textures, fps), player(player), window(window), speed(100), sightDistance(500),
	attackDistance(200)
{
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

	this->addAnimation(EntityState::PrimaryAttack, {
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

	this->setScale(2.5, 2.5);
}

EvilWizard::~EvilWizard()
{
}

void EvilWizard::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	sf::Vector2f velocity;

	this->animate(deltaTime, entities);

	auto bounds = this->getGlobalBounds();
	this->setOrigin(bounds.width / 2, bounds.height / 2);

	auto wraithPosition = this->getPosition();

	auto playerBounds = this->player->getGlobalBounds();
	auto playerPosition = this->player->getPosition();

	auto direction = playerPosition - wraithPosition;

	float distance = Utils::getVectorLength(direction);

	if (distance > this->attackDistance) {
		auto normalisedDirection = Utils::normalizeVector(direction);
		velocity = normalisedDirection;
	}

	this->move(velocity * this->speed * deltaTime);
}
