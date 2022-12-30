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
	bool Input(int p);

	string cmd;
	bool win;
	bool lose;
	int turn;
	Peach peach;
	Demon demon;
};
