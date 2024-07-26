#include "Movement.hpp"
#include <iostream>

const FPosition PiratesChest = {2, 3};
const FPosition GoldenIdol = {-5, -3};
const FPosition PreciousGems = {1, -2};
const FPosition LostArtwork = {5, 2};
const FPosition FifthTreasure = {-1, -1};


Player::Player() : CurrentPosition(0,0)
{
}

Player::~Player()
= default;

void Player::CheckForTreasure() const
{
	std::string ItemFound;
	if (CurrentPosition == PiratesChest)
	{
		ItemFound = " a pirates chest!";
	}
	else if (CurrentPosition == GoldenIdol)
	{
		ItemFound = " a golden idol!";
	}
	else if (CurrentPosition == PreciousGems)
	{
		ItemFound = " precious gemstones!";
	}
	else if (CurrentPosition == LostArtwork)
	{
		ItemFound = " a lost artwork!";
	}
	else if (CurrentPosition == FifthTreasure)
	{
		ItemFound = " the secret treasure!";
	}
	else
	{
		return;
	}

	const std::string FoundMessage = "* You found" + ItemFound + " *";
	
	for (size_t TopDecorationCounter = 0; TopDecorationCounter < FoundMessage.length(); TopDecorationCounter++)
	{
		std::cout << "*";
	}
	std::cout << '\n';
	std::cout << FoundMessage << '\n';
	for (size_t BottomDecorationCounter = 0; BottomDecorationCounter < FoundMessage.length(); BottomDecorationCounter++)
	{
		std:: cout << "*";
	}
	std::cout << '\n';
}

void Player::CheckForWorldEdge() const
{
	const int32& CurrentX = CurrentPosition.x;
	const int32& CurrentY = CurrentPosition.y;
	
	if (CurrentX != 10 && CurrentX != -10 && CurrentY != 10 && CurrentY != -10)
	{
		return;
	}
	std::cout << "+-----------------------------------------+" << '\n';
	std::cout << "| You have reached the edge of the world! |" << '\n';
	std::cout << "+-----------------------------------------+" << '\n';
}

void Player::Move(const EMovementDirection& direction)
{
	int32& CurrentX = CurrentPosition.x;
	int32& CurrentY = CurrentPosition.y;
	switch (direction)
	{
	case EMovementDirection::North:
		if (CurrentY >= -10 && CurrentY < 10)
		{
			CurrentY += 1;
		}
		break;
	case EMovementDirection::East:
		if (CurrentX >= -10 && CurrentX < 10)
		{
			CurrentX += 1;
		}
		break;
	case EMovementDirection::South:
		if (CurrentY > -10 && CurrentY <= 10)
		{
			CurrentY -= 1;
		}
		break;
	case EMovementDirection::West:
		if (CurrentX > -10 && CurrentY <= 10)
		{
			CurrentX -= 1;
		}
		break;
	case EMovementDirection::None:
		std::cout << '\n' << "Invalid command!" << '\n';
		return;
	case EMovementDirection::QuitApp:
		return;
	}
	std::cout << '\n';
	CheckForWorldEdge();
	CheckForTreasure();
}

void Player::PrintCurrentPosition() const
{
	std::cout << "You are at (" << CurrentPosition.x << ", " << CurrentPosition.y << "). ";
}


