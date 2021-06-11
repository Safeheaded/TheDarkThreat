#include "Level1.h"

Level1::Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes): 
	Scene(window, scenes)
{
	setupTextures();

	// Setups player
	this->player = new Player(this->window, &this->textures, 10.0f);
	this->player->setPosition(100, 100);

	this->entities.emplace_back(player);

	this->entities.emplace_back(
		new Wraith(this->player, this->window, &this->textures, 7.0f)
	);
}

void Level1::setupTextures()
{
	this->textures["PLAYER"] = new sf::Texture();
	Utils::loadTexture("wizard.png", this->textures["PLAYER"]);

	this->textures["WRAITH"] = new sf::Texture();
	Utils::loadTexture("wraith.png", this->textures["WRAITH"]);

	this->textures["ENEMY_ATTACK"] = new sf::Texture();
	Utils::loadTexture("wraithAttack.png", this->textures["ENEMY_ATTACK"]);

	this->textures["FIREBALL"] = new sf::Texture();
	Utils::loadTexture("primaryAttack.png", this->textures["FIREBALL"]);

	this->textures["PARTICLE"] = new sf::Texture();
	Utils::loadTexture("particleSpell.png", this->textures["PARTICLE"]);
}

Level1::~Level1()
{
	for (const auto& texture : this->textures) {
		delete texture.second;
	}

	for (const auto& entity : this->entities) {
		delete entity;
	}

}

void Level1::update(const float& deltaTime)
{
	//this->player->update(deltaTime);

	for (size_t i = 0; i < this->entities.size(); i++) {
		this->entities[i]->update(deltaTime, &this->entities);
		if (this->entities[i]->getCanDie()) {
			delete this->entities[i];
			this->entities.erase(this->entities.begin() + i);
		}
	}
}

void Level1::render(const float& deltaTime)
{
	//this->window->draw(*this->player);

	for (const auto& entity : this->entities) {
		this->window->draw(*entity);
	}
}

void Level1::handleEvents(const sf::Event& event)
{
}
