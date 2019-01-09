#pragma once
#include "Location.h"
#include <random>
#include "Snek.h"
#include "Board.h"


struct Fruit {

	Fruit() { loc.x = 0; loc.y = 0; }
	Fruit(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Draw(Board& brd) const;
	const Location& GetLocation() const { return loc; }

	void DrawGray(Board& brd) const;

private:
	static constexpr Color g = Colors::Gray;
	static constexpr Color c = Colors::Red;
	Location loc;
	
};