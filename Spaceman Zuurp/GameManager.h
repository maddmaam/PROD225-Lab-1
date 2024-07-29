// Copyright Madi Reilly 2024
// PROD225 Lab 1 is licensed under a
// Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License.
// See <http://creativecommons.org/licenses/by-nc-nd/3.0/>

#pragma once
#include "Zuurp.h"

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void StartGame();
    void PrintMessageSurrounded(const char* Message) const;

private:
    const char* LeftHandIndent = "      ";
    static void PrintStartGameMessage();
    Zuurp GameZuurp;
};
