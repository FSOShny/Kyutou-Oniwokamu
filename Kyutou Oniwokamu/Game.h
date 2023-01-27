#pragma once
#include <iostream>
#include "Peach.h"
#include "Demon.h"
using namespace std;

class Game
{
public:
	Game();
	void Startup();
	void Playing();
	void Shutdown();
private:
	void PeachTurn();
	void DemonTurn();
	bool Input(int pattern);

	string cmd;
	bool win;
	bool lose;
	int turn;
	int damage;
	Peach peach;
	Demon demon;
};
