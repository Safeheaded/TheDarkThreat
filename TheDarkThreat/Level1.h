#pragma once
#include "Scene.h"
#include "Player.h"
#include "Missile.h"
#include "Wraith.h"
#include "PlayerGUI.h"
#include "OverworldMap.h"
#include "GameOverScene.h"
#include "PauseScene.h"
#include <thread>
#include <chrono>
#include "Map.h"
#include "PlotScene.h"
#include "Level2.h"

class Level1 :
    public Scene
{
private:
    std::map<std::string, sf::Texture*> textures;
    Player* player;
    std::vector<Entity*> entities;
    PlayerGUI* playerGUI;
    OverworldMap map;
    sf::View view;
    bool isPaused;
public:
    Level1(sf::RenderWindow* window, std::stack<Scene*>* scenes);
    void setupTextures();
    ~Level1();

    void update(const float& deltaTime);
    void handleView();
    void render(const float& deltaTime);
    void handleEvents(const sf::Event& event);
};

