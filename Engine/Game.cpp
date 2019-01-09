/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Color mapColor = Colors::White;

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snek1(snekLoc),
	fruit( rng, brd, snek1)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_SPACE)) start = true;
	if(start){
		if (!snek1.CheckCollison() && !veg) {


			if (wnd.kbd.KeyIsPressed(VK_UP) && speed.y != 1) {
				delta_move = { 0,-1 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN) && speed.y != -1) {
				delta_move = { 0, 1 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT) && speed.x != -1) {
				delta_move = { 1, 0 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT) && speed.x != 1) {
				delta_move = { -1, 0 };
			}

			++SnekCounter;

			if (SnekCounter >= SnekMovePeriod) {
				SnekCounter = 0;
				snek1.MoveBy(speed);
				brd.wallContact(snek1.getLoc(), veg);
				Eat(snek1, fruit);
				speed = delta_move;

				++fruitTimer;
				if (fruitTimer >= 20 && db < N_reserve - 1) { fruitTimer = 0; ++db; reserve[db].Respawn(rng, brd, snek1); }
				else if (fruitTimer > 20)fruitTimer = 0;


				for (int i = 0; i <= db && i < N_reserve; ++i) {
					if (Consume(snek1, reserve[i])) {
						for (int j = i; j < N_reserve && j <= db; ++j) {
							reserve[j] = reserve[j + 1];
						}
					}
				}
			}
		}
		else {
			Location end = { 0,0 };
			speed = end;
			veg = true;

		}
	}
	else {
		SpriteCodex::DrawTitle(300, 100, gfx);
	}
}

void Game::ComposeFrame()
{
	brd.DrawMap(mapColor);

	snek1.Draw(brd);
	fruit.Draw(brd);


		for (int i = 0; i <= db && i<= N_reserve; ++i) {
			reserve[i].DrawGray(brd);
		}



	if (veg) {
		SpriteCodex::DrawGameOver(Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2, gfx);
	}
}

void Game::Eat(Snake &snek, Fruit &fruit) {
	if (snek.getLoc().x == fruit.GetLocation().x && snek.getLoc().y == fruit.GetLocation().y) {
		snek.Grow();
		fruit.Respawn(rng,brd,snek1);
	}
}

bool Game::Consume(Snake &snek, Fruit &fruit) {

	if (snek.getLoc().x == fruit.GetLocation().x && snek.getLoc().y == fruit.GetLocation().y) {
		--db;
		snek.Grow();
		return true;
	}
	return false;
}