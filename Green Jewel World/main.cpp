
#include <conio.h>
#include <winerror.h>

#include "FGrid.h"
#include "GJPlayer.h"

int main()
{
    constexpr unsigned char ArrowKey = 224;
    FGrid Grid(50,10);
    GJPlayer Player;
    unsigned char LastKey = '\0';
    do
    {
        LastKey = _getch();
        if (LastKey == ArrowKey)
        {
            char ArrowKey = _getch();
            Player.Move(ArrowKey, Grid);
        }
    }
    while (LastKey != 'q' && LastKey != 'Q' && Player.GetCurrentTreasureCount() < FGrid::GetTotalTreasureCount());
    if (LastKey == 'q' || LastKey == 'Q')
    {
        Grid.PlayerQuit();
    }
    else
    {
        Player.PlayerWon(Grid);
    }
    LastKey = _getche(); // This is left here because rider auto closes the terminal when the program returns success
    return ERROR_SUCCESS;
}
