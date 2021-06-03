#pragma once
#include "Scene.h"
class MenuScene :
    public Scene
{
public:
    MenuScene(sf::RenderWindow* window, std::stack<Scene*>* scenes);
    ~MenuScene();

    void update(const float& deltaTime);
    void render(const float& deltaTime);
};

