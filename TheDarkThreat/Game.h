#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class Game
{
private:
	// Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock clock;
	float deltaTime;

	// Methods
	void initWindow();
	void updateEvents();
	void updateDeltaTime();
	void update();
	void render();
public:
	// Constructor / Destructor
	Game();
	~Game();

	// Methods
	void run();
};

