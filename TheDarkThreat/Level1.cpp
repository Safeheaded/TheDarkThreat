#include "Level1.h"

Level1::Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes): 
	Scene(window, scenes)
{
	setupTextures();

	// Setups player
	this->player = new Player(this->window, &this->textures, 10.0f, 
		&this->missiles);
	this->player->setPosition(100, 100);

	this->entities.emplace_back(player);

	this->entities.emplace_back(
		new Wraith(this->player, this->window, &this->textures, 7.0f, &this->missiles)
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

	// Player is deleted in entities vector
	//delete this->player;

	for (const auto& missile : this->missiles) {
		delete missile;
	}

	for (const auto& enemy : this->entities) {
		delete enemy;
	}

}

void Level1::update(const float& deltaTime)
{
	//this->player->update(deltaTime);


	for (size_t i = 0; i < this->missiles.size(); i++) {
		this->missiles[i]->update(deltaTime, &this->entities);
		if (this->missiles[i]->getCanDie()) {
			delete this->missiles[i];
			this->missiles.erase(this->missiles.begin() + i);
		}
	}

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

	for (const auto& mis : this->missiles) {
		this->window->draw(*mis);
	}

	for (const auto& enemy : this->entities) {
		this->window->draw(*enemy);
	}
}

void Level1::handleEvents(const sf::Event& event)
{
}
