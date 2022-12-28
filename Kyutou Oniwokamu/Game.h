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
	bool Input(int p);

	bool winner;
};
