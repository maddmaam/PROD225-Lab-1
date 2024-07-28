#pragma once
#include "FGrid.h"
#include "../Hidden Treasure/IntegerMacros.hpp"
#include "../Hidden Treasure/Movement.hpp"


class GJPlayer
{
public:
    GJPlayer();
    ~GJPlayer();

    void Move(char& LastKey, FGrid& WorldGrid);
    int32& GetCurrentTreasureCount();
    void PlayerWon(FGrid& GameGrid);
    
private:
    FPosition CurrentPosition;
    int32 CurrentTreasureCount;
    int32 MoveCount = 0;
    static constexpr int8 LeftArrowKey = 75;
    static constexpr int8 RightArrowKey = 77;
    static constexpr int8 UpArrowKey = 72;
    static constexpr int8 DownArrowKey = 80;
};
