#pragma once

#include "Board.h"


class Snake {
	//Snekment
private:
	class Segment {
	public:
		void InitHead(const Location& loc);
		void InitBody(Color col);
	
		void Follow(const Segment& next);
		bool IsHit(const Segment& next)const;
		
		void MoveBy(const Location& delta_move);
		void Draw(Board& brd)const;
		
		const Location& getLoc() const { return loc; }

	private:
		Location loc;
		Color c;
	};

	//main Snek
public:
	Snake(const Location& loc);
	
	void MoveBy(const Location& delta_move);
	void Grow();
	void Draw( Board& brd) const;

	const int getN () const { return nSegments; }
	const Location& getLoc () { return segments[0].getLoc(); }

	bool CheckCollison() const;

	bool IsInTile(const Location& target) const;

private:
	static constexpr Color headColor = Colors::Yellow;
	
	static constexpr Color lg = { 0, 200, 0 };
	static constexpr Color g = { 0,150,0 };
	static constexpr Color dg = { 0, 100, 0 };


	int nSegments = 1;
	static constexpr int nSegmentsMax = 500;
	Segment segments[nSegmentsMax];
	
};