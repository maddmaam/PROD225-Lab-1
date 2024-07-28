#include "FGrid.h"

#include <iostream>
#include <cstdlib>

constexpr int8 JewelStartLetter = 'a';

FGrid::FGrid() : GridSizeX(50), GridSizeY(50), TreasureLocations{{0, 0}, {0, 0}, {0, 0}, {0, 0}}
{
}

FGrid::FGrid(const int32 XSize, const int32 YSize) : TreasureLocations{{0,0},{0,0}, {0,0}, {0,0}}
{
    srand(static_cast<int>(time(0)));
    GridSizeX = XSize;
    GridSizeY = YSize;

    for (int32 y = 0; y < GridSizeY; y++)
    {
        for (int32 x = 0; x < GridSizeX; x++)
        {
            // if (x == 0 && y == 0)
            // {
            //     SetTextColour(BLACK, WHITE);
            //     std::cout << 'P';
            //     continue;
            // }
            SetTextColour(WHITE, GREEN);
            std::cout << '-';
        }
        std::cout << '\n';
    }

    MoveCursorTo(0,0);
    SetTextColour(BLACK, WHITE);
    std::cout << 'P';
    CreateJewels();
}

void FGrid::CreateJewels()
{
    for (int32 JewelNumber = 0; JewelNumber < NumberOfJewels; JewelNumber++)
    {
        int32 XPos = rand() % GridSizeX;
        int32 YPos = rand() % GridSizeY;
        MoveCursorTo(XPos, YPos);
        SetTextColour(BLACK, JewelColours[JewelNumber]);
        std::cout << static_cast<char>(JewelStartLetter + JewelNumber);
        TreasureLocations[JewelNumber] = {XPos, YPos};
    }
}

void FGrid::MoveCharacterOnScreen(const FPosition& CurrentPlayerPosition, const FPosition& NewPlayerPosition)
{
    MoveCursorTo(CurrentPlayerPosition.x, CurrentPlayerPosition.y);
    SetTextColour(WHITE, LIGHTGREEN);
    std::cout << '-';
    const FPosition NewPosition = CurrentPlayerPosition + NewPlayerPosition;
    MoveCursorTo(NewPosition.x, NewPosition.y);
    SetTextColour(BLACK, WHITE);
    std::cout << 'P';
}

void FGrid::CheckForTreasure(int32& OutCurrentTreasureCount, FPosition& CurrentPlayerPosition)
{
    for (const FPosition& TreasureLocation : TreasureLocations)
    {
        if (TreasureLocation == CurrentPlayerPosition)
        {
            OutCurrentTreasureCount++;
            std::erase(TreasureLocations, TreasureLocation);
        }
    }
}

void FGrid::PrintMessageSurrounded(const char* MessageString)
{
    SetTextColour(MAGENTA, BLACK);
    std::cout << '\n' << "[] ";
    SetTextColour(LIGHTRED, BLACK);
    std::cout << "[] ";
    SetTextColour(RED, BLACK);
    std::cout << "[] ";
    SetTextColour(YELLOW, BLACK);
    std::cout << "[] ";
    SetTextColour(WHITE, BLACK);
    std::cout << MessageString;
    SetTextColour(RED, BLACK);
    std::cout << " []";
    SetTextColour(WHITE, BLACK);
    std::cout << " []";
    SetTextColour(YELLOW, BLACK);
    std::cout << " []";
    SetTextColour(LIGHTRED, BLACK);
    std::cout << " []";
}

void FGrid::MoveCharacter(EMovementDirection MoveDirection, FPosition& InOutCurrentPlayerPosition, int32& OutCurrentJewelCount)
{
    switch (MoveDirection)
    {
    case EMovementDirection::North:
        if (InOutCurrentPlayerPosition.y > 0)
        {
            FPosition NewCharacterPosition;
            NewCharacterPosition.y -= 1;
            MoveCharacterOnScreen(InOutCurrentPlayerPosition, NewCharacterPosition);
            InOutCurrentPlayerPosition += NewCharacterPosition;
        }
        break;
    case EMovementDirection::East:
        if (InOutCurrentPlayerPosition.x < 49)
        {
            FPosition NewCharacterPosition;
            NewCharacterPosition.x += 1;
            MoveCharacterOnScreen(InOutCurrentPlayerPosition, NewCharacterPosition);
            InOutCurrentPlayerPosition += NewCharacterPosition;
        }
        break;
    case EMovementDirection::South:
        if (InOutCurrentPlayerPosition.y < 9)
        {
            FPosition NewCharacterPosition;
            NewCharacterPosition.y += 1;
            MoveCharacterOnScreen(InOutCurrentPlayerPosition, NewCharacterPosition);
            InOutCurrentPlayerPosition += NewCharacterPosition;
        }
        break;
    case EMovementDirection::West:
        if (InOutCurrentPlayerPosition.x > 0)
        {
            FPosition NewCharacterPosition;
            NewCharacterPosition.x -= 1;
            MoveCharacterOnScreen(InOutCurrentPlayerPosition, NewCharacterPosition);
            InOutCurrentPlayerPosition += NewCharacterPosition;
        }
        break;
    default: return;
    }
    CheckForTreasure(OutCurrentJewelCount, InOutCurrentPlayerPosition);
}

void FGrid::PlayerQuit()
{
    SetTextColour(WHITE, BLACK);
    // Erase the Playing Grid
    system("CLS");
    MoveCursorTo(1, 0);
    std::cout <<'\n' << "         Oh no! You Quit!!" << '\n';
    PrintMessageSurrounded("Game over!");
}

int32 FGrid::GetTotalTreasureCount()
{
    return NumberOfJewels;
}
