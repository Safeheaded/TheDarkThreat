#pragma once
#include "Scene.h"
#include "Button.h"

class TextButton: public sf::Sprite
{
private:
	Button button;
	sf::Text text;
	sf::Font* font;
public:
	TextButton(Button button, std::string text, sf::Font* font);
	~TextButton();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

