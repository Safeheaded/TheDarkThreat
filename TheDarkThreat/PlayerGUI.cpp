#include "PlayerGUI.h"

PlayerGUI::PlayerGUI(sf::RenderWindow* window, Player* player): player(player), window(window)
{
	this->barsLength = 200;

	Utils::loadFont("akaFrivolity.ttf", &this->font);
	this->spellName.setString(this->player->getSpellName());
	this->spellName.setFont(this->font);

	this->prevHealth = this->player->getHealth();

	this->healthBar.setFillColor(sf::Color::Red);
	this->healthBar.setPosition(20, 20);
	this->healthBar.setSize({ this->barsLength, 40 });

	this->prevMana = this->player->getMana();

	this->manaBar.setFillColor(sf::Color::Blue);
	this->manaBar.setPosition(20, 70);
	this->manaBar.setSize({ this->barsLength, 40 });

	this->spellName.setFillColor(sf::Color::Black);
	this->spellName.setPosition(20, 130);
}

PlayerGUI::~PlayerGUI()
{
}

void PlayerGUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();
	target.draw(this->healthBar, states);
	target.draw(this->manaBar, states);
	target.draw(this->spellName, states);
}

void PlayerGUI::update(const float& deltaTime)
{
	float healthY = this->healthBar.getSize().y;

	float newHealthX = this->barsLength * this->player->getHealth() / this->player->getMaxHealth();

	if (this->prevHealth != this->player->getHealth() && this->player->getHealth() >=0) {
		this->healthBar.setSize({ newHealthX, healthY });
		this->prevHealth = this->player->getHealth();
	}
	else if (this->player->getHealth() <= 0) {
		this->healthBar.setSize({ 0, healthY });
		this->prevHealth = this->player->getHealth();
	}

	float y = this->manaBar.getSize().y;

	float newX = this->barsLength * this->player->getMana() / this->player->getMaxMana();

	if (this->prevMana != this->player->getMana()) {
		this->manaBar.setSize({ newX, y });
		this->prevMana = this->player->getMana();
	}


	this->spellName.setString(this->player->getSpellName());
}
