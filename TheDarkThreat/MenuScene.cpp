#include "MenuScene.h"

void MenuScene::setupButtons()
{
	sf::Color color(122, 58, 18);
	if (this->savedLevel != 0 || this->savedLevel == 1) {
		this->buttons.emplace_back(sf::Vector2f(0, 0), sf::Vector2f(230, 80), this->commands["CONTINUE"], "Continue", this->font, color);
	}
	this->buttons.emplace_back(sf::Vector2f(0, 0), sf::Vector2f(230, 80), this->commands["NEXT"], "New Game", this->font, color);
	this->buttons.emplace_back(sf::Vector2f(0, 0), sf::Vector2f(230, 80), this->commands["CLOSE"], "Exit", this->font, color);
	
}

void MenuScene::setButtonsPosition()
{
	float padding = 50;

	float buttonsHeight = getButtonsHeight() + padding * (this->buttons.size() - 1);
	float y = (this->window->getSize().y - buttonsHeight) / 2;

	for (size_t i = 0; i < this->buttons.size(); i++) {

		float x = this->window->getSize().x / 2 - this->buttons[i].getSize().x / 2;

		if (i != 0) {
			y += this->buttons[i].getSize().y + i + padding;
		}

		this->buttons[i].setPosition(x, y);
	}
}

float MenuScene::getButtonsHeight()
{
	float height = 0;
	for (const auto& btn : this->buttons) {
		height += btn.getGlobalBounds().height;
	}
	return height;
}

void MenuScene::setupCommands()
{
	this->commands["CLOSE"] = new UIClose();

	auto* scenes = this->scenes;
	auto* window = this->window;
	std::string text = Utils::loadFullText("assets\\plots\\plot1.txt");
	this->commands["NEXT"] = new UINextScene(
		this->scenes, this, new PlotScene(this->window, this->scenes, text, [scenes, window]() {
				auto* currentScene = scenes->top();
				scenes->pop();
				scenes->push(new Level1(window, scenes));
				delete currentScene;
			})
	);
	if (this->savedLevel != 0) {
		auto savedLevel = this->savedLevel;
		this->commands["CONTINUE"] = new UINextScene(
			this->scenes, this, new PlotScene(this->window, this->scenes, text, [scenes, window, savedLevel]() {
				auto* currentScene = scenes->top();
				scenes->pop();
				if (savedLevel == 1) {
					scenes->push(new Level1(window, scenes));
				}
				else if (savedLevel == 2) {
					scenes->push(new Level2(window, scenes));
				}
				else {
					scenes->push(new Level1(window, scenes));
				}
				delete currentScene;
				})
		);
	}
}

MenuScene::MenuScene(sf::RenderWindow* window, std::stack<Scene*>* scenes) :
	Scene(window, scenes)
{
	Utils::loadFont("assets\\fonts\\PressStart2P-Regular.ttf", &this->font);
	this->savedLevel = Utils::getSavedLevel();

	this->setupCommands();
	this->setupButtons();
	this->setButtonsPosition();
}

MenuScene::~MenuScene()
{
	// Deleting UICommands
	for (auto command : this->commands) {
		delete command.second;
	}
}

void MenuScene::update(const float& deltaTime)
{
	//std::cout << "Menu !!!" << std::endl;
}

void MenuScene::render(const float& deltaTime)
{
	for (auto& btn : this->buttons) {
		this->window->draw(btn);
	}
}

// This one runs in events' loop
void MenuScene::handleEvents(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			auto pos = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
			for (auto& btn : this->buttons) {
				btn.handleMouse(pos, this->window);
			}
		}
	}
}
