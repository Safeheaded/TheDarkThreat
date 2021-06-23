#include "Level2.h"

Level2::Level2(sf::RenderWindow* window, std::stack<Scene*>* scenes) :
	Scene(window, scenes), isPaused(false), isFinalBattle(false), isBossResped(false)
{
	Utils::saveLevel(2);
	this->setupTextures();


	this->player = new Player(this->window, &this->textures, 10.0f);
	this->player->setPosition(80, 500);

	this->entities.emplace_back(this->player);

	this->view.setSize(800, 800);

	this->playerGUI = new PlayerGUI(window, this->player); 
	
	this->map.build("assets\\textures\\dungeont.png", { 60, 44 }, Map::getUnderworldMap(), &this->textures, &this->entities,
		this->player, this->window, {18, 18});
}

void Level2::setupTextures()
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

	this->textures["ENEMY_HEALTH"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\health.png", this->textures["ENEMY_HEALTH"]);

	this->textures["HEALTH_POTION"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\healthPotion.png", this->textures["HEALTH_POTION"]);

	this->textures["MANA_POTION"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\manaPotion.png", this->textures["MANA_POTION"]); 

	this->textures["SKELETON"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\skeleton.png", this->textures["SKELETON"]);

	this->textures["SPIKES"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\spikes.png", this->textures["SPIKES"]);

	this->textures["WIZARD"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\evilWizard.png", this->textures["WIZARD"]);

	this->textures["PORTAL"] = new sf::Texture();
	Utils::loadTexture("assets\\textures\\portal.png", this->textures["PORTAL"]);
}

Level2::~Level2()
{
	for (const auto& texture : this->textures) {
		delete texture.second;
	}

	delete this->playerGUI;

	for (const auto& entity : this->entities) {
		delete entity;
	}
}

void Level2::update(const float& deltaTime)
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
			else if (typeid(*this->entities[i]) == typeid(EvilWizard)) {
				auto* window = this->window;
				auto* scenes = this->scenes;

				std::string plot = Utils::loadFullText("assets\\plots\\plot3.txt");

				auto* currentScene = this->scenes->top();
				this->scenes->pop();
				this->scenes->push(new PlotScene(this->window, this->scenes, plot, [window, scenes]() {
					// TODO: Loads Level2
					auto* currentScene = scenes->top();
					scenes->pop();
					scenes->push(new MenuScene(window, scenes));
					delete currentScene;
					}));
			}
			else {
				delete this->entities[i];
				this->entities.erase(this->entities.begin() + i);
			}
		}
	}

	// Checking if there are any enemies
	auto areEnemies = std::find_if(entities.begin(), entities.end(), [](Entity* entity) {
		return typeid(*entity) == typeid(Wraith) || 
			typeid(*entity) == typeid(Skeleton);
		});

	if (areEnemies == std::end(entities) && !this->isBossResped)
		this->isFinalBattle = true;

	// Resps boss if no enemies
	if (this->isFinalBattle) {
		Portal* portal = new Portal(this->player, this->window, &this->textures, 7);
		portal->setPosition(
			this->map.getSize().x / 2 - portal->getGlobalBounds().width / 2,
			this->map.getSize().y / 2 - portal->getGlobalBounds().height / 2
		);

		this->entities.emplace_back(portal);
		this->isFinalBattle = false;
		this->isBossResped = true;
	}

	this->playerGUI->update(deltaTime);

	this->handleView();
}

void Level2::handleView()
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

void Level2::render(const float& deltaTime)
{
	this->window->draw(this->map);

	for (const auto& entity : this->entities) {
		this->window->draw(*entity);
	}

	this->playerGUI->setPosition(this->view.getCenter() - this->view.getSize() / 2.f);

	this->window->draw(*this->playerGUI);
}

void Level2::handleEvents(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::K) {
			for (size_t i = 0; i < this->entities.size(); i++) {
				if (typeid(*entities[i]) == typeid(Wraith) ||
					typeid(*entities[i]) == typeid(Skeleton) ||
					typeid(*entities[i]) == typeid(EvilWizard)) {
					this->entities[i]->dealDamage(this->entities[i]->getMaxHealth());
				}
			}
		}
	}
}
