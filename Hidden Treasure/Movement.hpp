#pragma once

#include "IntegerMacros.hpp"

struct FPosition
{
	int32 x;
	int32 y;

	FPosition() : x(0), y(0)
	{
	}

	FPosition(int32 xPosition, int32 yPosition)
	{
		x = xPosition;
		y = yPosition;
	}

	bool operator ==(FPosition OtherPosition) const
	{
		return x == OtherPosition.x && y == OtherPosition.y;
	}
};

enum class EMovementDirection : int8
{
	QuitApp = -2,
	None = -1,
	North,
	East,
	South,
	West
};

class Player
{
public:
	Player();
	~Player();

private:
	FPosition CurrentPosition;
	void CheckForTreasure() const;
	void CheckForWorldEdge() const;

public:
	void Move(const EMovementDirection& direction);
	void PrintCurrentPosition() const;

};