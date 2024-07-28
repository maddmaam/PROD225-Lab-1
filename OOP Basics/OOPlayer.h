// Copyright Madi Reilly 2024
// PROD225 Lab 1 is licensed under a
// Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License.
// See <http://creativecommons.org/licenses/by-nc-nd/3.0/>

#pragma once

#include "../Hidden Treasure/IntegerMacros.hpp"

class OOPlayer
{
public:
    OOPlayer();
    ~OOPlayer();

    void PrintStats() const;
private:
    int32 Health;
    int32 ExperienceLevel;
    int32 PowerUpLevel;

public:
    void SetHealth(const int32& NewHealth);
    int32& GetHealth();

    void SetExperience(const int32& Experience);
    int32& GetExperience();

    void SetPowerUp(const int32& PowerUp);
    int32& GetPowerUp();
};
