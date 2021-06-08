#include "Level1.h"

Level1::Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes): 
	Scene(window, scenes)
{
	this->textures["PLAYER"] = new sf::Texture();
	Utils::loadTexture("wizard.png", this->textures["PLAYER"]);

	// Setups player
	// TODO: Move to separate method
	this->player = new Player(this->window, this->textures["PLAYER"], 6.0f);
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
