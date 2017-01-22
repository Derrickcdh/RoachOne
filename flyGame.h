//  Module:             GamePlay Programming
//  Assignment2:        Sushi Master
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859



#ifndef _FLYGAME_H             // prevent multiple definitions if this 
#define _FLYGAME_H             // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include <ctime>
#include "textDX.h"
using namespace std;
#define VK_W 0x57
#define VK_A 0x41
#define VK_D 0x44
#define VK_Q 0x51
#define VK_E 0x45
#define VK_0 0x30
#define VK_1 0x31
#define VK_2 0x32
#define VK_3 0x33
#define VK_4 0x34
#define VK_5 0x35
//=============================================================================
// Create game class
//=============================================================================
class flyGame : public Game
{
private:
	// variables
	TextureManager backgroundTexture;   // nebula texture
	TextureManager menuTexture;   // menu texture
	TextureManager arrowTexture;
	TextureManager arrowsTexture;
	TextureManager plateTexture;

	Image   background;                 // nebula image
	Image   menu;                 // menu image
	Image	arrow;
	Image	arrows;
	Image	plate;

	//timer

	int timer = 60;
	int elapsed_secs = 0;

	int gameStart = 0;
	clock_t begin;
	clock_t end;

	TextDX  *dxFontMedium;
public:
	// Constructor
	flyGame();

	// Destructor
	virtual ~flyGame();

	// Initialize the game

	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
	void printScore(int score);
	void printFilled();
	int displayTimer();
};

#endif
