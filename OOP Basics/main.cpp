﻿#include <iostream>
#include <winerror.h>
#include "Player.h"

int main()
{
    Player CurrentPlayer;
    CurrentPlayer.PrintStats();
    CurrentPlayer.SetHealth(100);
    CurrentPlayer.SetExperience(85);
    CurrentPlayer.SetPowerUp(-1);
    std::cout << "Health: " << CurrentPlayer.GetHealth() << '\n';
    std::cout << "Experience: " << CurrentPlayer.GetExperience() << '\n';
    std::cout << "Power Up: " << CurrentPlayer.GetPowerUp() << '\n';
    Player* PlayerPointer = new Player();
    PlayerPointer->SetHealth(999);
    PlayerPointer->SetExperience(-10);
    PlayerPointer->SetPowerUp(42);
    PlayerPointer->PrintStats();
    delete PlayerPointer;
    return ERROR_SUCCESS;
}
