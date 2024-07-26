#include <iostream>
#include "Player.h"


Player::Player(): Health(10), ExperienceLevel(0), PowerUpLevel(0)
{
    std::cout << "A Player object was created!" << '\n';
}

Player::~Player()
{
    std::cout << "A Player object was destroyed!" << '\n';
}

void Player::PrintStats() const
{
    std::cout << "Current Health: " << Health << '\n';
    std::cout << "Current Experience Level: " << ExperienceLevel << '\n';
    std::cout << "Current Power Up Level: " << PowerUpLevel << '\n';
}

void Player::SetHealth(const int32& NewHealth)
{
    Health = NewHealth;
}

int32& Player::GetHealth()
{
    return Health;
}

void Player::SetExperience(const int32& Experience)
{
    ExperienceLevel = Experience;
}

int32& Player::GetExperience()
{
    return ExperienceLevel;
}

void Player::SetPowerUp(const int32& PowerUp)
{
    PowerUpLevel = PowerUp;
}

int32& Player::GetPowerUp()
{
    return PowerUpLevel;
}
