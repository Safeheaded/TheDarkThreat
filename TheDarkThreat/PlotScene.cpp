#include "PlotScene.h"

void PlotScene::setupText(const std::string& text)
{
	this->text.setString(text);
	this->text.setFont(this->font);
	this->text.setCharacterSize(20);
	this->text.setLineSpacing(2);
	this->text.setPosition(
		this->window->getSize().x / 2 - this->text.getGlobalBounds().width/2,
		this->window->getSize().y / 2 - this->text.getGlobalBounds().height/2
	);

	this->instructionText.setString("Press \'Space\' to continue");
	this->instructionText.setCharacterSize(15);
	this->instructionText.setFont(this->font);
	this->instructionText.setPosition(
		this->window->getSize().x/2 - this->instructionText.getGlobalBounds().width/2, 
		this->window->getSize().y - this->instructionText.getGlobalBounds().height - 10
	);
}

PlotScene::PlotScene(sf::RenderWindow* window, std::stack<Scene*>* scenes, std::string text,
	std::function<void()> fun):
	Scene(window, scenes), fun(fun)
{
	Utils::loadFont("PressStart2P-Regular.ttf", &this->font);

	this->setupText(text);
}

PlotScene::~PlotScene()
{
}

void PlotScene::update(const float& deltaTime)
{
	sf::View view;
	view.setSize(this->window->getSize().x, this->window->getSize().y);
	view.setCenter(this->window->getSize().x / 2, this->window->getSize().y / 2);
	this->window->setView(view);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		// TODO: Load 1 st game level
		//auto* currentScene = this->scenes->top();
		//this->scenes->pop();
		//this->scenes->push(new Level1(this->window, this->scenes));
		//delete currentScene;
		this->fun();
	}
}

void PlotScene::render(const float& deltaTime)
{
	this->window->draw(this->text);
	this->window->draw(this->instructionText);
}

void PlotScene::handleEvents(const sf::Event& event)
{
	if (event.type == sf::Event::Resized) {
		this->text.setPosition(
			this->window->getSize().x / 2 - this->text.getGlobalBounds().width / 2,
			this->window->getSize().y / 2 - this->text.getGlobalBounds().height / 2
		);
		this->instructionText.setPosition(
			this->window->getSize().x / 2 - this->instructionText.getGlobalBounds().width / 2,
			this->window->getSize().y - this->instructionText.getGlobalBounds().height - 10
		);
	}
	
}
