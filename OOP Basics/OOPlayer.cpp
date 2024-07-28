#include <iostream>
#include "OOPlayer.h"


OOPlayer::OOPlayer(): Health(10), ExperienceLevel(0), PowerUpLevel(0)
{
    std::cout << "A Player object was created!" << '\n';
}

OOPlayer::~OOPlayer()
{
    std::cout << "A Player object was destroyed!" << '\n';
}

void OOPlayer::PrintStats() const
{
    std::cout << "Current Health: " << Health << '\n';
    std::cout << "Current Experience Level: " << ExperienceLevel << '\n';
    std::cout << "Current Power Up Level: " << PowerUpLevel << '\n';
}

void OOPlayer::SetHealth(const int32& NewHealth)
{
    Health = NewHealth;
}

int32& OOPlayer::GetHealth()
{
    return Health;
}

void OOPlayer::SetExperience(const int32& Experience)
{
    ExperienceLevel = Experience;
}

int32& OOPlayer::GetExperience()
{
    return ExperienceLevel;
}

void OOPlayer::SetPowerUp(const int32& PowerUp)
{
    PowerUpLevel = PowerUp;
}

int32& OOPlayer::GetPowerUp()
{
    return PowerUpLevel;
}
