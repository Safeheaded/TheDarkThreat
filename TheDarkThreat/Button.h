#pragma once
#include "Scene.h"
#include "UICommand.h"

class Button: public sf::RectangleShape
{
private:
	UICommand* command;
	bool isPressed;
	sf::Text text;
	sf::RectangleShape rect;

	// Methods
	void textSetup(std::string text, const sf::Font& font);
public:
	Button(
		sf::Vector2f pos, sf::Vector2f size, UICommand* command, 
		std::string text, const sf::Font& font, const sf::Color& color
	);
	~Button();

	// Methods
	void handleMouse(const sf::Vector2f& pos, sf::RenderWindow* window);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

