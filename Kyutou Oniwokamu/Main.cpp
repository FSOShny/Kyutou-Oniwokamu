#include "Game.h"

int main()
{
	/* 
	
	ゲームの流れとしては以下のようになる
	
	スタートアップ -> プレイ -> シャットダウン
	
	*/

	Game game;

	game.Startup();
	game.Playing();
	game.Shutdown();

	return 0;
}
