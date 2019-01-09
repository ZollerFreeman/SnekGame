#include "Board.h"
#include <assert.h>

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{}

void Board::DrawSnek(const Location& loc, Color c)
{
	gfx.DrawRectDim(loc.x*dimension, loc.y*dimension, dimension-2, dimension-2, c);
}

void Board::DrawCell(const Location & loc, Color c)
{
	gfx.DrawRectDim(loc.x*dimension, loc.y*dimension, dimension, dimension, c);
}

void Board::DrawFruit(const Location & loc, Color c)
{
	gfx.DrawRectDim(loc.x*dimension, loc.y*dimension, dimension-2, dimension-2, c);
}

void Board::DrawMap(Color& c)
{
	int a = Graphics::ScreenWidth - 15;
	int b = Graphics::ScreenHeight - 15;
	for (int x = 15; x <= a; ++x) {
		for (int y = 15; y <= b; ++y) {
			if (y == 15 || x == 15 || x == a || y == b) gfx.PutPixel(x, y, c);
		}
	}
}

void Board::wallContact(const Location& snek, bool& b)
{
	if (snek.x*dimension < 20 || snek.x*dimension > Graphics::ScreenWidth - 20 ||
		snek.y*dimension < 15 || snek.y*dimension > Graphics::ScreenHeight - 20) b = true;
}
