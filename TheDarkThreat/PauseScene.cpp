#include "PauseScene.h"

PauseScene::PauseScene(sf::RenderWindow* window, std::stack<Scene*>* scenes): 
	Scene(window, scenes)
{
	this->font.loadFromFile("8bitOperatorPlus8-Regular.ttf");

	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(50);
	this->text.setString("Pause Menu");
	this->text.setFont(this->font);
	this->text.setPosition(
		this->window->getSize().x/2 - this->text.getGlobalBounds().width/2,
		10
	);

	this->commands.emplace("GOTO_MENU", new UIGotoMenu(this->scenes));
	this->commands.emplace("CONTINUE", new UIClosePause(this->scenes));
	this->commands.emplace("EXIT", new UIClose());

	this->buttons.emplace_back(
		Button({ 0, 300 }, { 200, 70 }, this->commands["CONTINUE"], "Continue",
			this->font, sf::Color(122, 58, 18))
	);

	this->buttons.emplace_back(
		Button({ 0, 0 }, { 200, 70 }, this->commands["GOTO_MENU"], "Main Menu", 
			this->font, sf::Color(122, 58, 18))
	);

	this->buttons.emplace_back(
		Button({ 0, 0 }, { 200, 70 }, this->commands["EXIT"], "Quit",
			this->font, sf::Color(122, 58, 18))
	);

	this->setButtonsPosition();
}

PauseScene::~PauseScene()
{
	for (const auto& command : this->commands) {
		delete command.second;
	}
}

void PauseScene::update(const float& deltaTime)
{
	sf::View view;
	view.setSize(this->window->getSize().x, this->window->getSize().y);
	view.setCenter(this->window->getSize().x / 2, this->window->getSize().y / 2);
	this->window->setView(view);
}

void PauseScene::render(const float& deltaTime)
{
	this->window->draw(this->text);

	for (const auto& button : this->buttons) {
		this->window->draw(button);
	}
}

void PauseScene::handleEvents(const sf::Event& event)
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

void PauseScene::setButtonsPosition()
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

float PauseScene::getButtonsHeight()
{
	float height = 0;
	for (const auto& btn : this->buttons) {
		height += btn.getGlobalBounds().height;
	}
	return height;
}
