#include "Level1.h"

Level1::Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes): 
	Scene(window, scenes)
{
	setupTextures();

	// Setups player
	this->player = new Player(this->window, &this->textures, 10.0f);
	this->player->setPosition(100, 100);

	this->entities.emplace_back(player);

	this->playerGUI = new PlayerGUI(this->window, this->player);

	/*this->entities.emplace_back(
		new Wraith(this->player, this->window, &this->textures, 10.0f)
	);*/

	this->view.setSize(600, 600);

	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	this->map.load("tileset.png", sf::Vector2u(128, 128), level, 16, 8);
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

	for (size_t i = 0; i < this->entities.size(); i++) {
		this->entities[i]->update(deltaTime, &this->entities, this->map.getSize());
		if (this->entities[i]->getCanDie()) {
			// Temporary workaround so I won't get flowed by erros
			if (typeid(*this->entities[i]) == typeid(Player)) {
				//delete this->playerGUI;
			}
			else {
				delete this->entities[i];
				this->entities.erase(this->entities.begin() + i);
			}
		}
	}

	this->playerGUI->update(deltaTime);

	// Handling view

	handleView();
}

void Level1::handleView()
{
	auto playerBounds = this->player->getGlobalBounds();
	this->view.setCenter(this->player->getPosition());

	auto viewSize = this->view.getSize();
	auto viewPos = this->view.getCenter() - viewSize / 2.f;
	auto playerPos = this->player->getPosition();

	if (viewPos.x <= 0) {
		this->view.setCenter(viewSize.x / 2.f, view.getCenter().y);
	}
	else if (viewPos.x + viewSize.x >= this->map.getSize().x) {
		this->view.setCenter(this->map.getSize().x - viewSize.x / 2.f, view.getCenter().y);
	}

	if (viewPos.y <= 0) {
		this->view.setCenter(view.getCenter().x, viewSize.y / 2.f);
	}
	else if (viewPos.y + viewSize.y >= this->map.getSize().y) {
		this->view.setCenter(view.getCenter().x, this->map.getSize().y - viewSize.y / 2.f);
	}
	this->window->setView(this->view);
}

void Level1::render(const float& deltaTime)
{
	this->window->draw(this->map);
	for (const auto& entity : this->entities) {
		this->window->draw(*entity);
	}

	this->playerGUI->setPosition(this->view.getCenter() - this->view.getSize()/2.f);

	this->window->draw(*this->playerGUI);
}

void Level1::handleEvents(const sf::Event& event)
{
}
