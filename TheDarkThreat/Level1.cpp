#include "Level1.h"

Level1::Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes) :
	Scene(window, scenes), isPaused(false)
{
	setupTextures();

	// Setups player
	this->player = new Player(this->window, &this->textures, 10.0f);
	this->player->setPosition(100, 100);

	this->entities.emplace_back(player);

	this->playerGUI = new PlayerGUI(this->window, this->player);

	this->view.setSize(800, 800);
	std::vector<std::vector<int>> level =
	{
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	this->map.load("assets\\textures\\tileset.png",
		sf::Vector2u(32, 32), level, &this->textures,
		&this->entities, &this->obstacles, this->player, this->window
	);
}

void Level1::setupTextures()
{
	this->textures["PLAYER"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\wizard.png", this->textures["PLAYER"]);

	this->textures["WRAITH"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\wraith.png", this->textures["WRAITH"]);

	this->textures["ENEMY_ATTACK"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\wraithAttack.png", this->textures["ENEMY_ATTACK"]);

	this->textures["FIREBALL"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\primaryAttack.png", this->textures["FIREBALL"]);

	this->textures["PARTICLE"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\particleSpell.png", this->textures["PARTICLE"]);

	this->textures["TREE"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\plant.png", this->textures["TREE"]);
}

Level1::~Level1()
{
	for (const auto& texture : this->textures) {
		delete texture.second;
	}

	delete this->playerGUI;

	for (const auto& entity : this->entities) {
		delete entity;
	}

	for (const auto& obstacle : this->obstacles) {
		delete obstacle;
	}
}

void Level1::update(const float& deltaTime)
{
	if (this->isPaused) {
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		this->isPaused = false;
	}

	// Handles pause screen
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->scenes->push(new PauseScene(this->window, this->scenes));
		this->isPaused = true;
	}


	for (size_t i = 0; i < this->entities.size(); i++) {
		this->entities[i]->update(deltaTime, &this->entities, this->map.getSize());

		// collision detection
		/*if (this->entities[i]->getIsBlocking()) {
			for (const auto& obstacle : this->obstacles) {
				if (this->entities[i]->getGlobalBounds().intersects(obstacle->getGlobalBounds())) {
					std::cout << "Colliding" << std::endl;
				}
			}
		}*/

		if (this->entities[i]->getCanDie()) {
			// Temporary workaround so I won't get flowed by erros
			if (typeid(*this->entities[i]) == typeid(Player)) {
				// Kills the scene and loads GameOverScreen
				auto* currentScene = this->scenes->top();
				this->scenes->pop();
				this->scenes->push(new GameOverScene(this->window, this->scenes));

				/*const auto& defaultView = this->window->getDefaultView();
				this->window->setView(defaultView);*/

				delete currentScene;
				// Return needed to avoid updating nonexisting PlayerGUI
				return;
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

	// Drawing for testing
	/*for (const auto& obstacle : this->obstacles) {

		this->window->draw(*obstacle);
	}*/

	this->playerGUI->setPosition(this->view.getCenter() - this->view.getSize() / 2.f);

	this->window->draw(*this->playerGUI);
}

void Level1::handleEvents(const sf::Event& event)
{
}
