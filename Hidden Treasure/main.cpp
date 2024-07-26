#include <winerror.h>
#include <iostream>
#include <conio.h>
#include "Movement.hpp"
#include "Input.hpp"

int main()
{
	Player* CurrentPlayer = new Player();
	std::cout << "Find the hidden treasure!" << '\n';
	std::cout << "-------------------------" << '\n';
	std::cout << '\n' << "Press 'Q' to quit at any time..." << '\n';
	unsigned char LastKey = '\0';
	do
	{
		
		CurrentPlayer->PrintCurrentPosition();
		AskForPlayerMovement();
		LastKey = _getche();
		EMovementDirection DirectionToMove = GetMovementDirection(LastKey);
		CurrentPlayer->Move(DirectionToMove);
		std::cout << '\n';
	}
	while (LastKey != 'q' && LastKey != 'Q');
	std::cout << "Goodbye!" << '\n';
	delete CurrentPlayer;
	return ERROR_SUCCESS;
}