#include "Game.h"

int main()
{
	Game game;

	// ゲームフローは
	// スタートアップ、プレイ、シャットダウン
	// のようになる
	game.Startup();
	game.Playing();
	game.Shutdown();

	return 0;
}
