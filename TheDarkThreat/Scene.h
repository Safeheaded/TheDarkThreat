#pragma once

#include <iostream>
#include <stack>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>

class Scene
{
protected:
	sf::RenderWindow* window;
	std::stack<Scene*>* scenes;
public:
	Scene(sf::RenderWindow* window, std::stack<Scene*>* scenes);
	~Scene();
	virtual void update(const float& deltaTime) = 0;
	virtual void render(const float& deltaTime) = 0;
	virtual void handleEvents(const sf::Event& event) = 0;
};

