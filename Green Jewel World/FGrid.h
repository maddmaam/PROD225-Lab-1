#pragma once
#include <vector>

#include "prod225colour.h"
#include "../Hidden Treasure/IntegerMacros.hpp"
#include "../Hidden Treasure/Movement.hpp"

struct FGrid
{
    int32 GridSizeX;
    int32 GridSizeY;

    FGrid();
    FGrid(int32 XSize, int32 YSize);

private:
    void CreateJewels();
    void MoveCharacterOnScreen(const FPosition& CurrentPlayerPosition, const FPosition& NewPlayerPosition);
    void CheckForTreasure(int32& OutCurrentTreasureCount, FPosition& CurrentPlayerPosition);
    static constexpr int32 NumberOfJewels = 4;
    static constexpr PROD225Colours JewelColours[] {LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED};
    // FPosition TreasureLocations[NumberOfJewels];
    std::vector<FPosition> TreasureLocations;
public:
    void MoveCharacter(EMovementDirection MoveDirection, FPosition& InOutCurrentPlayerPosition, int32& OutCurrentJewelCount);
    void PlayerQuit();
    static int32 GetTotalTreasureCount();
    void PrintMessageSurrounded(const char* MessageString);
};
