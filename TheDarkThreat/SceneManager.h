#pragma once

#include "Scene.h"

class SceneManager
{
private:
	// Variables
	std::stack<Scene*> scenes;
	sf::RenderWindow* window;

	// Methods
	void initScenes();
public:
	// Constructor / Destructor
	SceneManager(sf::RenderWindow* window);
	~SceneManager();

	// Methods
	void render(const float& deltaTime);
	void update(const float& deltaTime);
};

