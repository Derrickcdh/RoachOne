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

	// background texture
	if (!backgroundTexture.initialize(graphics, BACKGROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	// background
	if (!background.initialize(graphics, 0, 0, 0, &backgroundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));

	// backgrounds texture
	if (!backgroundsTexture.initialize(graphics, BACKGROUNDS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backgrounds texture"));

	// backgrounds
	if (!backgrounds.initialize(graphics, 0, 0, 0, &backgroundsTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backgrounds"));

	if (!playerTexture.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));

	if (!player.initialize(this, playerNS::WIDTH, playerNS::HEIGHT, 0, &playerTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));

	// roach one menu texture
	if (!menuTexture.initialize(graphics, ROACHONE_MENU))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing roach one menu texture"));

	// roach one menu
	if (!menu.initialize(graphics, 0, 0, 0, &menuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing roach one menu"));

	// game mode texture
	if (!gamemodeTexture.initialize(graphics, GAMEMODE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game mode texture"));

	// game mode
	if (!gamemode.initialize(graphics, 0, 0, 0, &gamemodeTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game mode menu"));

	// mode 1 texture
	if (!mode1Texture.initialize(graphics, MODE1_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing mode 1 texture"));

	// mode 1
	if (!mode1.initialize(graphics, 0, 0, 0, &mode1Texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing mode 1"));

	// mode 2 texture
	if (!mode2Texture.initialize(graphics, MODE2_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing mode 2 texture"));

	// mode 2
	if (!mode2.initialize(graphics, 0, 0, 0, &mode2Texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing mode 2"));

	// timer
	if (dxFontMedium->initialize(graphics, 62, true, false, "Calibri") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	// score
	if (dxFontMedium->initialize(graphics, 62, true, false, "Calibri") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	background.setX(GAME_WIDTH / 700);
	backgrounds.setX(GAME_WIDTH / 1);

	player.setX(100);
	player.setY(GAME_HEIGHT - 100);

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void flyGame::update()
{
	if (input->isKeyDown(VK_RETURN) && gameStart == 0)            // Game start level 1, 
	{
		gameStart = 3;		//set the game mode
	}
	if (input->isKeyDown(VK_1) && gameStart == 3)
	{
		gameStart = 4;
	}
	if (input->isKeyDown(VK_SPACE) && gameStart == 4)
	{
		begin = clock();
		gameStart = 1;		//set the game mode
		start = time(0);	//start the timer
		scorePoint = 0;		//reset the score
		timer = 60;
		elapsed_secs = 0;

	}
	if (input->isKeyDown(VK_2) && gameStart == 3)
	{
		gameStart = 5;
	}
	if (input->isKeyDown(VK_SPACE) && gameStart == 5)
	{
		begin = clock();
		gameStart = 1;		//set the game mode
		start = time(0);	//start the timer
		scorePoint = 0;		//reset the score
		timer = 60;
		elapsed_secs = 0;
	}

	if (gameStart == 1 && input->isKeyDown(VK_SPACE))
	{
		player.setY(player.getY() - playerNS::SPEED * 1);
		player.update(frameTime);
	}
	else
	{
		player.setY(player.getY() - playerNS::SPEED * 1);
		player.drop(frameTime);
	}

	background.setX(background.getX() + frameTime * ZENTT_SPEED);
	if (background.getX() > GAME_WIDTH)               // if off screen right
	{
		background.setX((float)-background.getWidth());     // position off screen left
	}

	backgrounds.setX(backgrounds.getX() + frameTime * ZENTT_SPEED);
	if (backgrounds.getX() > GAME_WIDTH)               // if off screen right
	{
		backgrounds.setX((float)-backgrounds.getWidth());     // position off screen left
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
		background.draw();
		backgrounds.draw();
		player.draw();
		dxFontMedium->setFontColor(graphicsNS::WHITE);
		dxFontMedium->print(to_string(displayTimer()), 0, 20);
	}
	if (gameStart == 2) // render level two sprites
	{
		background.draw();
		backgrounds.draw();
		player.draw();
		dxFontMedium->setFontColor(graphicsNS::WHITE);
		dxFontMedium->print(to_string(displayTimer()), 0, 20);
	}
	// Game Mode
	if (gameStart == 3) // game mode screen
	{
		gamemode.draw();
	}
	if (gameStart == 4)
	{
		mode1.draw();
	}
	if (gameStart == 5)
	{
		mode2.draw();
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
	backgroundsTexture.onLostDevice();
	gamemodeTexture.onLostDevice();
	mode1Texture.onLostDevice();
	mode2Texture.onLostDevice();

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
	backgroundsTexture.onResetDevice();
	gamemodeTexture.onResetDevice();
	mode1Texture.onResetDevice();
	mode2Texture.onResetDevice();

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