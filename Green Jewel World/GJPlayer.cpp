#include "GJPlayer.h"

#include <iostream>

#include "FGrid.h"

GJPlayer::GJPlayer() : CurrentPosition(0,0), CurrentTreasureCount(0)
{
}

GJPlayer::~GJPlayer()
= default;

void GJPlayer::Move(char& LastKey, FGrid& WorldGrid)
{
    MoveCount++;
    switch (LastKey)
    {
    case LeftArrowKey:
        WorldGrid.MoveCharacter(EMovementDirection::West, CurrentPosition, CurrentTreasureCount);
        break;
    case RightArrowKey:
        WorldGrid.MoveCharacter(EMovementDirection::East, CurrentPosition, CurrentTreasureCount);
        break;
    case UpArrowKey:
        WorldGrid.MoveCharacter(EMovementDirection::North, CurrentPosition, CurrentTreasureCount);
        break;
    case DownArrowKey:
        WorldGrid.MoveCharacter(EMovementDirection::South, CurrentPosition, CurrentTreasureCount);
        break;
    default: break;
    }
}

int32& GJPlayer::GetCurrentTreasureCount()
{
    return CurrentTreasureCount;
}

void GJPlayer::PlayerWon(FGrid& GameGrid)
{
    SetTextColour(WHITE, BLACK);
    // Erase the Playing Grid
    system("CLS");
    GameGrid.PrintMessageSurrounded("Well Done!");
    SetTextColour(WHITE, BLACK);
    std::cout << '\n' << '\n';
    std::cout << "  You collected all four jewels!" << '\n';
    std::cout << '\n' << "       It took you " << MoveCount << " moves!" << '\n';
    GameGrid.PrintMessageSurrounded("Game Over!");
}

