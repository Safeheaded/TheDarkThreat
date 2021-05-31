#include "Scene.h"

Scene::Scene(sf::RenderWindow* window, std::stack<Scene*>* scenes):
	window(window), scenes(scenes)
{
}

Scene::~Scene()
{
}
