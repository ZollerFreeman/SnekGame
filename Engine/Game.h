/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snek.h"
#include "Location.h"
#include <random>
#include "Fruit.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */

	void Eat(Snake &snek, Fruit &fruit);
	bool Consume(Snake &snek, Fruit &fruit);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Board brd;
	std::mt19937 rng;
	Location snekLoc = { brd.GetGridWidth() / 2, brd.GetGridHeight() / 2 };
	Snake snek1;
	Fruit fruit;
	bool start = false;
	Location speed = { 0,0 };
	Location delta_move = { 0,0 };
	static constexpr int SnekMovePeriod = 8;
	int SnekCounter = 0;

	int db = -1;
	int fruitTimer = 0;
	static int constexpr N_reserve = 10;
	Fruit reserve[N_reserve];

	bool veg = false;
	/********************************/

};
	
	
