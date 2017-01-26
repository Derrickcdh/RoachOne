//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859

#include "flyGame.h"

time_t start;		// timer
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

	// fly texture
	if (!playerTexture.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));

	// fly
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

	// frog texture
	if (!frogTexture.initialize(graphics, FROG_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frog texture"));

	// frog
	if (!frog.initialize(graphics, FROG_WIDTH, FROG_HEIGHT, FROG_COLS, &frogTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frog"));

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

	frog.setX(GAME_WIDTH / 10);
	frog.setY(GAME_HEIGHT / 2);

	frog.setFrames(FLY_START_FRAME, FLY_END_FRAME);   // animation frames 
	frog.setCurrentFrame(FLY_START_FRAME);             // starting frame
	frog.setFrameDelay(FLY_ANIMATION_DELAY);

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
		gameStart = 2;		//set the game mode
		start = time(0);	//start the timer
		scorePoint = 0;		//reset the score
		timer = 60;
		elapsed_secs = 0;
	}

	if (gameStart == 1 && input->isKeyDown(VK_SPACE))
	{
		player.update(frameTime);
		player.setY(player.getY() - playerNS::SPEED * 1);
		player.setV(0);
	}
	else
	{	
		player.drop(frameTime);
		player.setY(player.getY() - playerNS::SPEED * 1);
	}

	background.setX(background.getX() - frameTime * FLY_SPEED);
	backgrounds.setX(backgrounds.getX() - frameTime * FLY_SPEED);

	if (backgrounds.getX() <= 0)
	{
		background.setX(GAME_WIDTH / GAME_WIDTH);
		backgrounds.setX(GAME_WIDTH / 1);
	}

	frog.update(frameTime);
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
		frog.draw();

		dxFontMedium->setFontColor(graphicsNS::WHITE);
		dxFontMedium->print(to_string(displayTimer()), 0, 20);
	}
	if (gameStart == 2) // render level two sprites
	{
		background.draw();
		backgrounds.draw();
		player.draw();
		frog.draw();

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
	playerTexture.onLostDevice();
	frogTexture.onLostDevice();

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
	playerTexture.onResetDevice();
	frogTexture.onResetDevice();

	Game::resetAll();
	return;
}

float flyGame::displayTimer(){
	return frameTime;
}