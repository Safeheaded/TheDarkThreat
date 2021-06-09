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
	sf::Texture* texture;
	float timePerFrame;
	float timeCounter;
	float counter;

	virtual void animationEnd() = 0;
public:
	Entity(sf::Texture* texture, const float& fps, bool isBlocking = false, EntityState state = EntityState::Idle);
	virtual ~Entity() = default;

	const bool getIsBlocking() const;
	const EntityState getState() const;

	virtual void update(const float& deltaTime) = 0;
	void addAnimation(EntityState state, const std::vector<sf::IntRect>& frames);
	void animate(const float& deltaTime);
	void setFirstFrame();
};

