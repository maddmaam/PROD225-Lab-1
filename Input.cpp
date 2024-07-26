#include "Input.hpp"
#include <iostream>


void AskForPlayerMovement()
{
    std::cout << "Move (N/E/S/W)? ";
}

EMovementDirection GetMovementDirection(const unsigned char DirectionInput)
{
    switch (DirectionInput)
    {
    case 'N':
        // Falls through
    case 'n':
        return EMovementDirection::North;
    case 'E':
        // Falls through
    case 'e':
        return EMovementDirection::East;
    case 'S':
        // Falls through
    case 's':
        return EMovementDirection::South;
    case 'W':
        // Falls through
    case 'w':
        return EMovementDirection::West;
    case 'Q':
        // Falls through
    case 'q':
        return EMovementDirection::QuitApp;
    default:
        return EMovementDirection::None;
    }
}
