#include "Player.h"
#include <cmath>

Player::Player(
	sf::RenderWindow* window, sf::Texture* texture, 
	const float& fps, std::vector<Missile*>* missiles
):
	Entity(texture, fps), speed(500), 
	window(window), isRunning(false), 
	prevState(EntityState::Idle), maxHealth(100), health(100), missiles(missiles),
	maxMana(100), mana(100)
{
	this->selectedSpell = 0;
	this->setupAnimations();
	this->setFirstFrame();
	this->canChangeState = true;

	this->spellTexture = new sf::Texture();
	this->particleSpellTexture = new sf::Texture();
	Utils::loadTexture("primaryAttack.png", this->spellTexture);
	Utils::loadTexture("particleSpell.png", this->particleSpellTexture);

	this->spells.emplace_back(new FireballSpell(this->missiles, this->spellTexture));
	this->spells.emplace_back(new ParticleSpell(this->missiles, this->particleSpellTexture));
}

Player::~Player()
{
	delete this->spellTexture;
	delete this->particleSpellTexture;

	for (const auto& spell : this->spells) {
		delete spell;
	}
}

void Player::update(const float& deltaTime)
{
	this->isRunning = false;
	auto playerBounds = this->getGlobalBounds();

	// Handles movement
	sf::Vector2f velocity;
	if (this->canChangeState) {
		handleMovement(velocity, deltaTime, playerBounds);
	}

	// changes state & resets counter if needed
	if (this->canChangeState) {
		EvaluateState(missiles);
	}

	// fires animation
	this->animate(deltaTime);

	// moves sprite
	if (this->state == EntityState::Move) {
		this->move(velocity);
	}

	// Window collision
	handleWindowCollision(playerBounds);

}

void Player::EvaluateState(std::vector<Missile*>* missiles)
{
	// Handles running / idle state
	if (this->isRunning) {
		this->state = EntityState::Move;
	}
	else {
		this->state = EntityState::Idle;
	}

	// handles death
	if (this->health <= 0) {
		this->state = EntityState::Death;
		this->canChangeState = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->state = EntityState::PrimaryAttack;
		this->canChangeState = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		this->selectedSpell = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		this->selectedSpell = 1;
	}

	// TESTING!!!

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->health = 0;
	}*/

	// resets animation counter if animation has changed
	if (this->state != this->prevState) {
		this->counter = 0;
		this->prevState = this->state;
	}
}

void Player::handleWindowCollision(sf::FloatRect& playerBounds)
{
	if (getPosition().x < 0) {
		setPosition(0, getPosition().y);
	}
	if (getPosition().y < 0) {
		setPosition(getPosition().x, 0);
	}
	if (getPosition().x + playerBounds.width > window->getSize().x) {
		setPosition(window->getSize().x - playerBounds.width, getPosition().y);
	}
	if (getPosition().y + playerBounds.height > window->getSize().y) {
		setPosition(getPosition().x, window->getSize().y - playerBounds.height);
	}
}

void Player::setupAnimations()
{
	this->addAnimation(EntityState::Idle, {
		{82, 55, 57, 86},
		{313, 55, 57, 86},
		{544, 55, 57, 86},
		{775, 55, 57, 86},
		{1006, 55, 57, 86},
		{1237, 55, 57, 86}
		});
	this->addAnimation(EntityState::Move, {
		{73, 255, 75, 75},
		{308, 255, 70, 75},
		{547, 255, 59, 75},
		{764, 255, 71, 75},
		{997, 255, 75, 75},
		{1234, 255, 63, 75},
		{1474, 255, 55, 75},
		{1691, 255, 71, 75}
		});
	this->addAnimation(EntityState::Death, {
		{80, 801, 65, 99},
		{305, 801, 73, 99},
		{535, 801, 84, 99},
		{781, 801, 102, 99},
		{1012, 801, 88, 99},
		{1243, 801, 84, 99},
		{1474, 801, 88, 99}
		});
	this->addAnimation(EntityState::PrimaryAttack, {
		{86, 625, 82, 79},
		{317, 625, 79, 79},
		{540, 625, 76, 79},
		{783, 625, 81, 79},
		{1014, 625, 96, 79},
		{1245, 625, 130, 79},
		{1476, 625, 134, 79},
		{1707, 625, 140, 79}
		});
}

void Player::animationEnd()
{
	if (this->state == EntityState::PrimaryAttack) {
		this->state = EntityState::Idle;
		this->attack();
		this->canChangeState = true;
	}
}

void Player::attack()
{
	// Fires only when enough mana
	if (this->mana >= this->spells[this->selectedSpell]->getManaCost()) {
		sf::Vector2f target = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
		this->spells[this->selectedSpell]->fire(
			this->window, 8.0f, target, this->getPosition()
		);

		// Decreases mana
		this->mana -= this->spells[this->selectedSpell]->getManaCost();
	}
}

void Player::handleMovement(sf::Vector2f& velocity, const float& deltaTime, sf::FloatRect& playerBounds)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		velocity.y = -this->speed * deltaTime;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		velocity.y = this->speed * deltaTime;
	}

	// TODO (low priority): change scale / origin only after direction change
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocity.x = -this->speed * deltaTime;
		this->setScale(-1, 1);
		this->setOrigin({ playerBounds.width, 0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x = this->speed * deltaTime;
		this->setScale(1, 1);
		this->setOrigin({ 0, 0 });
	}

	// Checks if player is moving
	if (
		sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->isRunning = true;
	}
}
