#include "Snek.h"
#include <assert.h>

Snake::Snake(const Location & loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_move) {

		for (int i = nSegments - 1; i > 0; --i) {
			segments[i].Follow(segments[i - 1]);
		}
	segments[0].MoveBy(delta_move);
}

void Snake::Grow() { if (nSegments < nSegmentsMax) { 
	++nSegments; 
	segments[nSegments - 1].InitBody(lg);
	segments[nSegments - 1].Follow(segments[nSegments - 2]);

	++nSegments;
	segments[nSegments - 1].InitBody(g);
	segments[nSegments - 1].Follow(segments[nSegments - 2]);

	if (nSegments <= 81) {
		++nSegments;
		segments[nSegments - 1].InitBody(dg);
		segments[nSegments - 1].Follow(segments[nSegments - 2]);
	}

} }

void Snake::Draw(Board & brd) const {
	for (int i = nSegments - 1; i > 0; --i) {
		segments[i].Draw(brd);
	}
	segments[0].Draw(brd);
}

bool Snake::CheckCollison() const
{
	for (int i = nSegments - 1; i > 3; --i) {
		if(segments[0].IsHit(segments[i]) == true) return true;
	}
	return false;
}

bool Snake::IsInTile(const Location & target) const
{
	for (int i = nSegments - 1; i >= 0; --i) {
		if (segments[i].getLoc().x == target.x && segments[i].getLoc().y == target.y) return true;
	}
	return false;
}

//Segment functions

void Snake::Segment::InitHead(const Location & in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(Color col)
{
	c = col;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

bool Snake::Segment::IsHit(const Segment & next)const
{
	return loc.x == next.loc.x && loc.y == next.loc.y;
}

void Snake::Segment::MoveBy(const Location& delta_move)
{
	loc.Add(delta_move);
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawSnek(loc, c);
}
