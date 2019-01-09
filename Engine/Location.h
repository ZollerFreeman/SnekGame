#pragma once
#include <random>
#include "Graphics.h"



struct Location {

	void Add(const Location& val) {
		x += val.x;
		y += val.y;
	}

	int x;
	int y;
};