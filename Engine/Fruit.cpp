#include "Fruit.h"



Fruit::Fruit(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	Respawn(rng, brd, snake);
}

void Fruit::Respawn(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	std::uniform_int_distribution<int> xDist(3, brd.GetGridWidth() - 3);
	std::uniform_int_distribution<int> yDist(3, brd.GetGridHeight() - 3);
	Location new_Loc;
	do {
		new_Loc.x = xDist(rng);
		new_Loc.y = yDist(rng);
	} while (snake.IsInTile(new_Loc));

	loc = new_Loc;

}

void Fruit::Draw(Board & brd) const
{
	brd.DrawFruit(loc, c);
}

void Fruit::DrawGray(Board & brd) const
{
	brd.DrawFruit(loc, g);
}

