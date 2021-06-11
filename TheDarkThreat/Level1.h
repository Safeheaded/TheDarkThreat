#pragma once
#include "Scene.h"
#include "Player.h"
#include "Missile.h"
#include "Wraith.h"

class Level1 :
    public Scene
{
private:
    std::map<std::string, sf::Texture*> textures;
    Player* player;
    std::vector<Missile*> missiles;
    std::vector<Entity*> entities;
public:
    Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes);
    void setupTextures();
    ~Level1();

    void update(const float& deltaTime);
    void render(const float& deltaTime);
    void handleEvents(const sf::Event& event);
};

