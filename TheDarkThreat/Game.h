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
	sf::SoundBuffer buffer;
	sf::Sound sound;

	// Methods
	void initWindow();
	void updateEvents();
	void updateDeltaTime();
	void update();
	void render();
public:
	// Constructor / Destructor
	Game();
	void setupMusic();
	~Game();

	// Methods
	void run();
};

