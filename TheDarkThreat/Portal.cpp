#include "Portal.h"

void Portal::animationEnd(std::vector<Entity*>* entities)
{
	auto bounds = this->getGlobalBounds();
	EvilWizard* boss = new EvilWizard(this->player, this->window, this->textures, 5);
	auto wizardBounds = boss->getGlobalBounds();

	boss->setPosition(
		bounds.left + bounds.width / 2 - wizardBounds.width /2, 
		bounds.top + bounds.height / 2 - wizardBounds.height / 2
		);

	HealthBar* health = new HealthBar(this->textures, 1, boss);
	entities->emplace_back(boss);
	entities->emplace_back(health);
	this->canDie = true;
}

Portal::Portal(Player* player, sf::RenderWindow* window, 
	std::map<std::string, sf::Texture*>* textures, const float& fps):
	Entity(textures, fps), player(player), window(window)
{
	this->setTexture(*this->textures->operator[]("PORTAL"));
	this->addAnimation(EntityState::Idle, {
		{0, 0, 100, 100},
		{100, 0, 100, 100},
		{200, 0, 100, 100},
		{300, 0, 100, 100},
		{400, 0, 100, 100},
		{500, 0, 100, 100},
		{600, 0, 100, 100},

		{0, 100, 100, 100},
		{100, 100, 100, 100},
		{200, 100, 100, 100},
		{300, 100, 100, 100},
		{400, 100, 100, 100},
		{500, 100, 100, 100},
		{600, 100, 100, 100},

		{0, 200, 100, 100},
		{100, 200, 100, 100},
		{200, 200, 100, 100},
		{300, 200, 100, 100},
		{400, 200, 100, 100},
		{500, 200, 100, 100},
		{600, 200, 100, 100},

		{0, 300, 100, 100},
		{100, 300, 100, 100},
		{200, 300, 100, 100},
		{300, 300, 100, 100},
		{400, 300, 100, 100},
		{500, 300, 100, 100},
		{600, 300, 100, 100},
		});
	this->setFirstFrame();
	this->setScale(4, 4);
}

Portal::~Portal()
{
}

void Portal::update(const float& deltaTime, std::vector<Entity*>* entities, sf::Vector2f mapSize)
{
	this->animate(deltaTime, entities);
}
