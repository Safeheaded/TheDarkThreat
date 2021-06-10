#include "Level1.h"

Level1::Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes): 
	Scene(window, scenes)
{
	setupTextures();

	// Setups player
	this->player = new Player(this->window, this->textures["PLAYER"], 10.0f, 
		&this->missiles, &this->enemies);
	this->player->setPosition(100, 100);

	this->enemies.emplace_back(
		new Wraith(this->player, this->window, this->textures["WRAITH"], 7.0f, &this->missiles)
	);
}

void Level1::setupTextures()
{
	this->textures["PLAYER"] = new sf::Texture();
	Utils::loadTexture("wizard.png", this->textures["PLAYER"]);

	this->textures["WRAITH"] = new sf::Texture();
	Utils::loadTexture("wraith.png", this->textures["WRAITH"]);
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

	for (const auto& enemy : this->enemies) {
		delete enemy;
	}

}

void Level1::update(const float& deltaTime)
{
	this->player->update(deltaTime);


	for (size_t i = 0; i < this->missiles.size(); i++) {
		this->missiles[i]->update(deltaTime);
		if (this->missiles[i]->getCanDie()) {
			delete this->missiles[i];
			this->missiles.erase(this->missiles.begin() + i);
		}
	}

	for (size_t i = 0; i < this->enemies.size(); i++) {
		this->enemies[i]->update(deltaTime);
		if (this->enemies[i]->getCanDie()) {
			delete this->enemies[i];
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}

void Level1::render(const float& deltaTime)
{
	this->window->draw(*this->player);

	for (const auto& mis : this->missiles) {
		this->window->draw(*mis);
	}

	for (const auto& enemy : this->enemies) {
		this->window->draw(*enemy);
	}
}

void Level1::handleEvents(const sf::Event& event)
{
}
