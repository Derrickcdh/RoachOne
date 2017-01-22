//  Module:             GamePlay Programming
//  Assignment2:        Sushi Master
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859



#include<time.h> 
#include "flyGame.h"
#include <time.h>
#include <Windows.h>
#include <ctime>
time_t start;		// timer
int seconds;		//seconds for the timer
time_t animationTime;//animation time for each animation that is executed
int aTime;			//to take in the animation time
int gameStart = 0;	//gameMode
int scorePoint = 0; //player score

//double seconds;
//=============================================================================
// Constructor
//=============================================================================
flyGame::flyGame()
{
	dxFontMedium = new TextDX();
}

//=============================================================================
// Destructor
//=============================================================================
flyGame::~flyGame()
{
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void flyGame::initialize(HWND hwnd)
{
	//PlaySound("pictures\\BGM.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);				// play sound file

	Game::initialize(hwnd); // throws GameError
	// jap menu texture
	if (!menuTexture.initialize(graphics, JAP_MENU))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Japanese menu texture"));

	// jap menu
	if (!menu.initialize(graphics, 0, 0, 0, &menuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	// timer
	if (dxFontMedium->initialize(graphics, 62, true, false, "Calibri") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void flyGame::update()
{
	if (input->isKeyDown(VK_1) && gameStart == 0)            // Game start level 1, 
	{
		begin = clock();
		gameStart = 1;		//set the game mode
		start = time(0);	//start the timer
		scorePoint = 0;		//reset the score
		timer = 60;
		elapsed_secs = 0;
	}

	arrow.setX(arrow.getX() + frameTime * ZENTT_SPEED);
	if (arrow.getX() > GAME_WIDTH)               // if off screen right
	{
		arrow.setX((float)-arrow.getWidth());     // position off screen left
	}

	arrows.setX(arrows.getX() + frameTime * ZENTT_SPEED);
	if (arrows.getX() > GAME_WIDTH)               // if off screen right
	{
		arrows.setX((float)-arrows.getWidth());     // position off screen left
	}

	plate.setX(plate.getX() + frameTime * ZENTT_SPEED);
	if (plate.getX() > GAME_WIDTH)               // if off screen right
	{
		plate.setX((float)-plate.getWidth());     // position off screen left
		plate.setVisible(false);
	}
	aTime = difftime(time(0), animationTime);		//when controls and animation played for a second, the controls are returned to the player and player model reset
	if (aTime == 1)
	{
		
	}
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void flyGame::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void flyGame::collisions()
{}

//=============================================================================
// Render game items
//=============================================================================
void flyGame::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	if (gameStart == 0)//render main menu
	{
		menu.draw();

	}
	if (gameStart == 1) // render level one sprites
	{
		dxFontMedium->setFontColor(graphicsNS::WHITE);
		dxFontMedium->print(to_string(displayTimer()), 0, 20);
	}
	if (gameStart == 2) // render level two sprites
	{

	}
	// Print credits
	if (gameStart == 3) // render credits screen
	{

	}
	//print game over screen at the end of game
	if (gameStart == 4)
	{

	}
	//Intro to the game
	if (gameStart == 5)
	{

	}
	//food list in the game
	if (gameStart == 6)
	{

	}

	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void flyGame::releaseAll()
{
	backgroundTexture.onLostDevice();


	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void flyGame::resetAll()
{
	backgroundTexture.onResetDevice();


	Game::resetAll();
	return;
}


int flyGame::displayTimer(){
	if (timer - elapsed_secs > 0){
		end = clock();
		elapsed_secs = int(end - begin) / CLOCKS_PER_SEC;
		return timer - elapsed_secs;
	}
	else
		return 0;
}