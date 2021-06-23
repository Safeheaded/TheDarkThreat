#include "Level1.h"

Level1::Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes) :
	Scene(window, scenes), isPaused(false)
{
	Utils::saveLevel(1);
	setupTextures();

	// Setups player
	this->player = new Player(this->window, &this->textures, 10.0f);
	this->player->setPosition(291, 257);

	this->entities.emplace_back(player);

	this->playerGUI = new PlayerGUI(this->window, this->player);

	this->view.setSize(800, 800);
	std::vector<std::vector<int>> map = Map::getOverworldMap();

	this->map.build("assets\\textures\\tileset.png",
		sf::Vector2u(32, 32), map, &this->textures,
		&this->entities, &this->obstacles, this->player, this->window, {0, 0}
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

	this->textures["ENEMY_HEALTH"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\health.png", this->textures["ENEMY_HEALTH"]);

	this->textures["HEALTH_POTION"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\healthPotion.png", this->textures["HEALTH_POTION"]);

	this->textures["MANA_POTION"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\manaPotion.png", this->textures["MANA_POTION"]);

	this->textures["CEMETERY"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\cemetery.png", this->textures["CEMETERY"]);

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
	// Waits after exiting pause screen
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

		if (this->entities[i]->getCanDie()) {
			// Temporary workaround so I won't get flowed by erros
			if (typeid(*this->entities[i]) == typeid(Player)) {
				// Kills the scene and loads GameOverScreen
				auto* currentScene = this->scenes->top();
				this->scenes->pop();
				this->scenes->push(new GameOverScene(this->window, this->scenes));

				delete currentScene;
				// Return needed to avoid updating nonexisting PlayerGUI
				return;
			}
			else {
				delete this->entities[i];
				this->entities.erase(this->entities.begin() + i);
			}
		}
		else {
			Crypt* crypt = dynamic_cast<Crypt*>(this->entities[i]);
			if (crypt != nullptr) {
				// crypt->getIsNextLevel()
				if (crypt->getIsNextLevel()) {
					auto* window = this->window;
					auto* scenes = this->scenes;

					std::string plot = Utils::loadFullText("assets\\plots\\plot2.txt");

					auto* currentScene = this->scenes->top();
					this->scenes->pop();
					this->scenes->push(new PlotScene(this->window, this->scenes, plot, [window, scenes]() {
							// TODO: Loads Level2
							auto* currentScene = scenes->top();
							scenes->pop();
							scenes->push(new Level2(window, scenes));
							delete currentScene;
						}));
				}
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

	this->playerGUI->setPosition(this->view.getCenter() - this->view.getSize() / 2.f);

	this->window->draw(*this->playerGUI);
}

void Level1::handleEvents(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::K) {
			for (size_t i = 0; i < this->entities.size(); i++) {
				if (typeid(*entities[i]) == typeid(Wraith)) {
					this->entities[i]->dealDamage(this->entities[i]->getMaxHealth());
				}
			}
		}
	}
}
