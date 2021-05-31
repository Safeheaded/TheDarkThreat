#pragma once

#include "SceneManager.h"

class Game
{
private:
	// Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock clock;
	float deltaTime;
	SceneManager* sceneManager;

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

