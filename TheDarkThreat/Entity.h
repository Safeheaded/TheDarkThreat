#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

enum class EntityState {
	Idle,
	PrimaryAttack,
	SecondaryAttack,
	Move,
	Death
};

class Entity : public sf::Sprite
{
protected:
	bool isBlocking;
	EntityState state;
	std::map<EntityState, std::vector<sf::IntRect>> animations;
	std::map<std::string, sf::Texture*>* textures;
	float timePerFrame;
	float timeCounter;
	float counter;
	bool canDie;

	virtual void animationEnd(std::vector<Entity*>* entities) = 0;
	void setFirstFrame();
	void animate(const float& deltaTime, std::vector<Entity*>* entities);
	void addAnimation(EntityState state, const std::vector<sf::IntRect>& frames);
public:
	Entity(std::map<std::string, sf::Texture*>* textures, const float& fps, bool isBlocking = false,
		EntityState state = EntityState::Idle);
	virtual ~Entity() = default;

	const bool getIsBlocking() const;
	const EntityState getState() const;

	virtual void update(const float& deltaTime, 
		std::vector<Entity*>* entities, sf::Vector2f mapSize) = 0;

	virtual void dealDamage(const float& damage);
	const bool getCanDie() const;
};

