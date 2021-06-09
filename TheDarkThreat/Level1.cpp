#include "Level1.h"

Level1::Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes): 
	Scene(window, scenes)
{
	this->textures["PLAYER"] = new sf::Texture();
	Utils::loadTexture("wizard.png", this->textures["PLAYER"]);

	this->textures["WRAITH"] = new sf::Texture();
	Utils::loadTexture("wraith.png", this->textures["WRAITH"]);

	// Setups player
	this->player = new Player(this->window, this->textures["PLAYER"], 10.0f, &this->missiles);
	this->player->setPosition(100, 100);

	this->wraith = new Wraith(this->player, this->window, this->textures["WRAITH"], 7.0f, &this->missiles);
	this->wraith->setPosition(400, 400);
}

Level1::~Level1()
{
	for (const auto& texture : this->textures) {
		delete texture.second;
	}

	delete this->player;

	for (const auto& missile : this->missiles) {
		delete missile;
	}

}

void Level1::update(const float& deltaTime)
{
	this->player->update(deltaTime);

	this->wraith->update(deltaTime);

	for (size_t i = 0; i < this->missiles.size(); i++) {
		this->missiles[i]->update(deltaTime);
		if (this->missiles[i]->getCanDestroy()) {
			delete this->missiles[i];
			this->missiles.erase(this->missiles.begin() + i);
		}
	}
}

void Level1::render(const float& deltaTime)
{
	this->window->draw(*this->player);
	this->window->draw(*this->wraith);

	for (const auto& mis : this->missiles) {
		this->window->draw(*mis);
	}
}

void Level1::handleEvents(const sf::Event& event)
{
}
