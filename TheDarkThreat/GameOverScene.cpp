#include "GameOverScene.h"

GameOverScene::GameOverScene(sf::RenderWindow* window, std::stack<Scene*>* scenes) :
	Scene(window, scenes)
{
	sf::View view = this->window->getDefaultView();
	view.setSize((float)this->window->getSize().x, (float)this->window->getSize().y);
	view.setCenter((float)this->window->getSize().x/2, (float)this->window->getSize().y/2);
	this->window->setView(view);

	this->font.loadFromFile("assets\\fonts\\PressStart2P-Regular.ttf");

	// Setting up text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setString("You Died!");
	this->gameOverText.setFillColor(sf::Color::White);
	this->gameOverText.setCharacterSize(80);

	this->gameOverText.setPosition(
		this->window->getSize().x / 2 - this->gameOverText.getGlobalBounds().width / 2, 70);
	// setting up commands

	this->commands.emplace("TRY_AGAIN", new UIRepeatLevel(this->scenes));
	this->commands.emplace("CLOSE", new UIClose());
	this->commands.emplace("GOTO_MENU", new UIGotoMenu(this->scenes));

	// setting up buttons
	this->buttons.emplace_back(
		Button({ 0, 0 }, { 300, 70 }, this->commands["TRY_AGAIN"], "Try Again",
			this->font, sf::Color(122, 58, 18))
	);
	this->buttons.emplace_back(
		Button({ 0, 0 }, { 300, 70 }, this->commands["GOTO_MENU"], "Main Menu",
			this->font, sf::Color(122, 58, 18))
	);
	this->buttons.emplace_back(
		Button({ 0, 0 }, { 300, 70 }, this->commands["CLOSE"], "Exit Game",
			this->font, sf::Color(122, 58, 18))
	);

	this->setButtonsPosition();
}

GameOverScene::~GameOverScene()
{
	for (const auto& command : this->commands) {
		delete command.second;
	}
}

void GameOverScene::update(const float& deltaTime)
{
	//std::cout << "GameOverScene" << std::endl;
}

void GameOverScene::render(const float& deltaTime)
{
	this->window->draw(this->gameOverText);

	for (const auto& button : this->buttons) {
		this->window->draw(button);
	}
}

void GameOverScene::handleEvents(const sf::Event& event)
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

void GameOverScene::setButtonsPosition()
{
	float padding = 30;
	float offset = 50;

	float buttonsHeight = getButtonsHeight() + padding * (this->buttons.size() - 1);
	float y = (this->window->getSize().y - buttonsHeight) / 2 + offset;

	for (size_t i = 0; i < this->buttons.size(); i++) {

		float x = this->window->getSize().x / 2 - this->buttons[i].getSize().x / 2;

		if (i != 0) {
			y += this->buttons[i].getSize().y + padding;
		}

		this->buttons[i].setPosition(x, y);
	}
}

float GameOverScene::getButtonsHeight()
{
	float height = 0;
	for (const auto& btn : this->buttons) {
		height += btn.getGlobalBounds().height;
	}
	return height;
}
