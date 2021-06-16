#include "PlotScene.h"

void PlotScene::setupText(const std::string& text)
{
	this->text.setString(text);
	this->text.setFont(this->font);
	this->text.setPosition(20, 20);

	this->instructionText.setString("Wciœnij \'Space\', aby kontynuowaæ");
	this->instructionText.setFont(this->font);
	this->instructionText.setPosition(
		this->window->getSize().x/2 - this->instructionText.getGlobalBounds().width/2, 
		this->window->getSize().y - this->instructionText.getGlobalBounds().height - 10
	);
}

PlotScene::PlotScene(sf::RenderWindow* window, std::stack<Scene*>* scenes, const std::string& text):
	Scene(window, scenes)
{
	Utils::loadFont("akaFrivolity.ttf", &this->font);

	this->setupText(text);
}

PlotScene::~PlotScene()
{
}

void PlotScene::update(const float& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		// TODO: Load 1 st game level
		auto* currentScene = this->scenes->top();
		this->scenes->pop();
		this->scenes->push(new Level1(this->window, this->scenes));
		delete currentScene;
	}
}

void PlotScene::render(const float& deltaTime)
{
	this->window->draw(this->text);
	this->window->draw(this->instructionText);
}

void PlotScene::handleEvents(const sf::Event& event)
{
}
