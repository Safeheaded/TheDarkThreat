#pragma once
#include "Player.h"

class PlayerGUI : public sf::RectangleShape
{
private:
	Player* player;
	sf::RenderWindow* window;
	sf::RectangleShape healthBar;
	sf::RectangleShape manaBar;
	float prevHealth;
	float prevMana;
	float barsLength;
public:
	PlayerGUI(sf::RenderWindow* window, Player* player);
	~PlayerGUI();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(const float& deltaTime);
};

