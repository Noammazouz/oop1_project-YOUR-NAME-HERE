#pragma once

#include <vector>
#include <string>


const int HEIGHT = 900;
const int WIDTH = 1602;
const int END_GAME = 0;
const int BOARD_STARTING_X = WIDTH / 8;
const int BOARD_STARTING_Y = HEIGHT / 10;
const float SPEED = 100.f;
const int NUM_OF_BUTTON = 4;
const int NUM_OF_LIVES = 3;
enum menuButtons {
	START_GAME,
	HELP,
	EXIT,
	BACK
};
enum MovingID 
{
	GUARD,
	BOMBS
};