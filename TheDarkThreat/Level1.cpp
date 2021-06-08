#include "Level1.h"

Level1::Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes): 
	Scene(window, scenes)
{
	this->textures["PLAYER"] = new sf::Texture();
	Utils::loadTexture("wizard.png", this->textures["PLAYER"]);

	// Setups player
	// TODO: Move to separate method
	this->player = new Player(this->window, this->textures["PLAYER"], 6.0f);
	this->player->addAnimation(EntityState::Idle, { 
		{82, 55, 57, 86},
		{313, 55, 57, 86},
		{544, 55, 57, 86},
		{775, 55, 57, 86},
		{1006, 55, 57, 86},
		{1237, 55, 57, 86}
		});
	this->player->addAnimation(EntityState::Move, {
		{73, 255, 75, 75},
		{308, 255, 70, 75},
		{547, 255, 59, 75},
		{764, 255, 71, 75},
		{997, 255, 75, 75},
		{1234, 255, 63, 75},
		{1474, 255, 55, 75},
		{1691, 255, 71, 75}
		});
	this->player->addAnimation(EntityState::Death, {
		{80, 801, 65, 99},
		{305, 801, 73, 99},
		{535, 801, 84, 99},
		{781, 801, 102, 99},
		{1012, 801, 88, 99},
		{1243, 801, 84, 99},
		{1474, 801, 88, 99}
		});
	this->player->setPosition(100, 100);
}

Level1::~Level1()
{
	for (const auto& texture : this->textures) {
		delete texture.second;
	}

	delete this->player;
}

void Level1::update(const float& deltaTime)
{
	this->player->update(deltaTime);
}

void Level1::render(const float& deltaTime)
{
	this->window->draw(*this->player);
}

void Level1::handleEvents(const sf::Event& event)
{
}
