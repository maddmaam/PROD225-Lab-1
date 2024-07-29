#include "GameManager.h"

#include <iostream>

GameManager::GameManager() : GameZuurp()
{
    StartGame();
}

GameManager::~GameManager() = default;

void GameManager::StartGame()
{
    PrintMessageSurrounded("   Welcome to SPACEMAN, a word-guessing game!  ");
    PrintStartGameMessage();
    GameZuurp.Start();
}

void GameManager::PrintMessageSurrounded(const char* Message) const
{
    std::cout << LeftHandIndent << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << '\n';
    std::cout << LeftHandIndent << Message << '\n';
    std::cout << LeftHandIndent << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << '\n';
}

void GameManager::PrintStartGameMessage()
{
    std::cout << "    " << "Zuurp, an alien, has crashed on planet Earth! Zuurp" << '\n';
    std::cout << "      " << "mistakes you for Earth's leader and demands you" << '\n';
    std::cout << "   " << "guess their secret word, one letter at a time. Zuurp's" << '\n';
    std::cout << "   " << "people have been monitoring Earth for years, and hence" << '\n';
    std::cout << "           " << "know the English language quite well!" << '\n';

    std::cout << '\n' << "     " << "If you don't guess the word quickly enough, Zuurp" << '\n';
    std::cout << "   " << "will rebuild their spaceship and leave, but if you do" << '\n';
    std::cout << "  " << "manage to guess Zuurp's secret word then they will stay" << '\n';
    std::cout << "  " << "to play again! Beware, Zuurp likes numbers, and will be" << '\n';
    std::cout << "            " << "recording your data as you guess!" << '\n';
}
