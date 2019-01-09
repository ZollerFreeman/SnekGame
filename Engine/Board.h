#pragma once

#include "Graphics.h"
#include "Location.h"


class Board {
public:
	Board(Graphics& gfx);
	void DrawSnek(const Location& loc, Color c);
	void DrawCell(const Location& loc, Color c);
	void DrawFruit(const Location& loc, Color c);
	void DrawMap(Color& c);

	int GetGridWidth() const { return width; };
	int GetGridHeight()const { return height; };
	int GetDimension()const { return dimension; }

	void wallContact(const Location& snek, bool& b);
	int getMapHeight() const { return height; }
	int getMapWidth() const { return width; }
private:
	static constexpr int dimension = 15;
	static constexpr int width = Graphics::ScreenWidth/ dimension;
	static constexpr int height = Graphics::ScreenHeight/ dimension;
	Graphics& gfx;
	
	
};