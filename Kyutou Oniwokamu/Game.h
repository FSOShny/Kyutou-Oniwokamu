#pragma once
#include <iostream>
using namespace std;

class Game
{
public:
	Game();
	void Startup();
	void Playing();
	void Shutdown();
private:
	void Setting();
	void PeachTurn();
	void DemonTurn();
	bool Input(int p);

	string cmd;
	bool loop;
	bool win;
};
