#include "GameEngine.h"
int main(int argc, char* argv[])
{
	GameEngine* NewGame = new GameEngine();
	NewGame->Window->WindowSetup(new char[3] {'L','S','B'}, 1280, 720);
	NewGame->GameLoop();
	delete NewGame;
	NewGame = nullptr;
	return 0;
}