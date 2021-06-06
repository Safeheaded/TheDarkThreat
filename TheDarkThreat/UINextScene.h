#pragma once
#include "UICommand.h"
class UINextScene :
    public UICommand
{
private:
    std::stack<Scene*>* scenes;
    Scene* currentScene;
    Scene* nextScene;
public:
    UINextScene(std::stack<Scene*>* scenes, Scene* scene, Scene* nextScene);
    ~UINextScene();

    void execute(sf::RenderWindow* window);
};

