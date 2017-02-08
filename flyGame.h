//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, Ting hong yang
//  Student Number:     S10161350, S10159859, S10127976

#ifndef _FLYGAME_H             // prevent multiple definitions if this 
#define _FLYGAME_H             // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include <ctime>
#include "textDX.h"
#include "Player.h"
#include "spiderWeb.h"
#include "spitBall.h"
#include "Fly.h"
#include "frogTongue.h"
#include "Tornado.h"
#include "invulnerable.h"
#include "speedUp.h"
#include <fstream>
using namespace std;

#define VK_0 0x30
#define VK_1 0x31
#define VK_2 0x32
#define VK_RETURN 0x0D
#define VK_SPACE 0x20

//=============================================================================
// Create game class
//=============================================================================
class flyGame : public Game
{
private:
	// variables
	TextureManager backgroundTexture;   // nebula texture
	TextureManager backgroundsTexture;   // nebula texture
	TextureManager menuTexture;   // menu texture
	TextureManager gamemodeTexture;
	TextureManager playerTexture;
	TextureManager frogtongueTexture;
	TextureManager frogTexture;
	TextureManager spitballTexture;
	TextureManager spiderWebTexture;
	TextureManager flyTexture;
	TextureManager TornadoTexture;
	TextureManager buffInvulnerabletexture;
	TextureManager speedBuffTexture;

	Image   background;                 // nebula image
	Image   backgrounds;                 // nebula image
	Image   menu;                 // menu image
	Image	gamemode;
	Image	playerImage;
	Image	frog;
	Image	TornadoImage;
	
	SpeedUp speedBuff;
	Invulnerable	buffInvulnerable;
	FrogTongue	frogtongue;
	Player player;
	SpiderWeb spiderWeb;
	spitBall spitball[10];
	Fly fly;
	Tornado tornado;

	//timer
	float buffTimer = 5;
	int elapsed_secs = 0;

	int gameStart = 0;
	clock_t begin;
	clock_t end;

	TextDX  *dxFontMedium;
	TextDX	*dxFont;

public:
	// Constructor
	flyGame();

	// Destructor
	virtual ~flyGame();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void updateObjectMovement();
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
	void printScore(int score);
	void printFilled();
	float displayTimer();
	void resetObjects();
	void selectObject();
	void gameOver();
	void slowPlayer();
	void updateObjFrameTime();
	float displayDifference();
	int getHiscore(int score);
};

#endif