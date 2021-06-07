#pragma once
#include "Scene.h"
#include "Player.h"
class Level1 :
    public Scene
{
private:
    std::map<std::string, sf::Texture*> textures;
    Player* player;
public:
    Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes);
    ~Level1();

    void update(const float& deltaTime);
    void render(const float& deltaTime);
    void handleEvents(const sf::Event& event);
};

