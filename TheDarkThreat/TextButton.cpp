#include "TextButton.h"

TextButton::TextButton(Button button, std::string text, sf::Font* font): button(button), font(font)
{
	this->text.setString(text);
	this->text.setFont(*font);
	this->setPosition(100, 0);
}

TextButton::~TextButton()
{
}

void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();
	target.draw(button, states);
	target.draw(text, states);
}
