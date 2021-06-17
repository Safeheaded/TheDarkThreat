#include "Button.h"

void Button::textSetup(std::string text, const sf::Font& font)
{
	this->text.setString(text);
	this->text.setFont(font);
	this->text.setCharacterSize(20);

	// Centering text

	float x = this->getGlobalBounds().width / 2 - this->text.getGlobalBounds().width / 2;
	float y = this->getGlobalBounds().height / 2 - this->text.getGlobalBounds().height / 2;

	this->text.setPosition(x, y);
}

Button::Button(
	sf::Vector2f pos, sf::Vector2f size, UICommand* command,
	std::string text, const sf::Font& font, const sf::Color& color): RectangleShape(size), command(command)
{
	this->textSetup(text, font);
	this->isPressed = false;
	this->setPosition(pos);

	this->rect.setFillColor(color);
	this->rect.setSize(size);
}

Button::~Button()
{
}

void Button::handleMouse(const sf::Vector2f& pos, sf::RenderWindow* window)
{
	
	if (this->getGlobalBounds().contains(pos) && !this->isPressed) {
		this->isPressed = true;
		this->command->execute(window);
	}
	else {
		this->isPressed = false;
	}
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();
	target.draw(this->rect, states);
	target.draw(this->text, states);

}
