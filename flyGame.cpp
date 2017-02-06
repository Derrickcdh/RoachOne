//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859

#include "flyGame.h"
#include <stdlib.h>     /* srand, rand */

time_t start;		// timer
int gameStart = 0;	//gameMode
int scorePoint = 0; //player score
int objectPoints;
int webPoints;

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
	if (!player.initialize(this, playerNS::WIDTH, playerNS::HEIGHT, playerNS::TEXTURE_COLS, &playerTexture))
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

	//spitball texture
	if (!spitballTexture.initialize(graphics, SPITBALL_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing spitballTexture"));

	float test = sizeof(spitball) / sizeof(spitBall);
	for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
	{
		// spitball
		if (!spitball[i].initialize(this, spitballNS::WIDTH, spitballNS::HEIGHT, 0, &spitballTexture))
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing spitball"));
		
	}

	//fly texture
	if (!flyTexture.initialize(graphics, FLY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing flyTexture"));

	if (!fly.initialize(this, FlyNS::WIDTH, FlyNS::HEIGHT, 0, &flyTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing spiderWeb"));


	//spiderweb texture
	if (!spiderWebTexture.initialize(graphics, SPIDERWEB_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing spitballTexture"));

	// spiderWeb
	if (!spiderWeb.initialize(this, SpiderWebNS::WIDTH, SpiderWebNS::HEIGHT, 0, &spiderWebTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing spiderWeb"));

	if (!TornadoTexture.initialize(graphics, TORNADO_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing TornadoTexture"));

	if (!tornado.initialize(this, TornadoNS::WIDTH, TornadoNS::HEIGHT, 0, &TornadoTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Tornado"));
	background.setX(GAME_WIDTH / GAME_WIDTH);
	backgrounds.setX(GAME_WIDTH / 1);

	player.setX(100);
	player.setY(GAME_HEIGHT - 100);
	player.setFrames(playerNS::PLAYER_START_FRAME, playerNS::PLAYER_END_FRAME);
	player.setCurrentFrame(playerNS::PLAYER_START_FRAME);

	//frog.setX(GAME_WIDTH / 5);
	//frog.setY(GAME_HEIGHT / 2);

	//frog.setFrames(FLY_START_FRAME, FLY_END_FRAME);   // animation frames 
	//frog.setCurrentFrame(FLY_START_FRAME);             // starting frame
	//frog.setFrameDelay(FLY_ANIMATION_DELAY);

	for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
	{
		spitball[i].setX(GAME_WIDTH);
		spitball[i].setY((rand() % (GAME_HEIGHT/10)+1)*10);
		//spitball.setY(GAME_HEIGHT/2);
		//spitball[i].setScale(0.5);

		int ast = rand() % 5+200;
		spitball[i].setVelocity(VECTOR2(ast, -ast));
		//(VECTOR2(spitballNS::SPEED, -spitballNS::SPEED))
		spitball[i].setVisible(false);
	}
	spiderWeb.setVisible(false);
	spiderWeb.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);
	//fly.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);
	fly.setX(GAME_WIDTH);

	tornado.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);
	tornado.setX(GAME_WIDTH);
}

//=============================================================================
// Update all game items
//=============================================================================
void flyGame::update()
{
	if (input->isKeyDown(VK_RETURN) && gameStart == 0)            // Game start level 1, 
	{
		gameStart = 4;		//set the game mode
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
		timer = 0;
		elapsed_secs = 0;
		player.setActive(true);
		player.setVisible(true);
		resetObjects();
		player.setY(GAME_HEIGHT - 100);
		objectPoints = 10;
		selectObject();
	}
	if (gameStart == 1)
	{
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
		updateObjectMovement();
		
	}
	
	//spitball.update(frameTime);
}

void flyGame::selectObject()
{
	if (objectPoints >= 1)
	{
		//int randomCheck = rand() % 2 + 1;

		if (spiderWeb.getVisible()==false)
		{
			spiderWeb.setVisible(true);
			spiderWeb.setX(GAME_WIDTH);
			spiderWeb.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);
		}
		
	}
	
	if (objectPoints >= 3)
	{
		for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
		{
			if (spitball[i].getVisible()==false)
			{
				if (objectPoints < 3)
				{
					break;
				}
				spitball[i].setVisible(true);
				spitball[i].setX(GAME_WIDTH);
				objectPoints -= 3;
			}
		}
	}
	if (fly.getVisible() == false)
	{
		fly.setVisible(true);
		fly.setX(GAME_WIDTH);
		fly.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);
	}
}

void flyGame::updateObjectMovement()
{
	background.setX(background.getX() - frameTime * FLY_SPEED);
	backgrounds.setX(backgrounds.getX() - frameTime * FLY_SPEED);
	
	if (backgrounds.getX() <= 0)
	{
		background.setX(GAME_WIDTH / GAME_WIDTH);
		backgrounds.setX(GAME_WIDTH / 1);
		objectPoints += 1;
		selectObject();
	}
	if (spiderWeb.getX() < -300)
	{
		spiderWeb.setVisible(false);
	}
	frog.update(frameTime);
	spiderWeb.update(frameTime);
	fly.update(frameTime);
	tornado.update(frameTime);
	if (fly.getX() <= -150)
	{
		fly.setX(GAME_WIDTH);
		fly.setY(rand() % (GAME_HEIGHT-150)+50);
	}

	for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
	{
		spitball[i].update(frameTime);

		if (spitball[i].getX() < (-100))
		{
			spitball[i].setX(GAME_WIDTH);
			spitball[i].setY(rand() % (GAME_HEIGHT)+1);
			if (spitball[i].getY() < 5)
			{
				spitball[i].setY(spitball[i].getY() + 10);
			}
			if (spitball[i].getY() > GAME_HEIGHT - 5)
			{
				spitball[i].setY(spitball[i].getY() - 10);
			}
			//spitball[i].setVisible(false);
			//spitPoints += 3;
		}
	}
}

void flyGame::resetObjects()
{
	for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
	{
		spitball[i].update(frameTime);
		spitball[i].setX(GAME_WIDTH);
		spitball[i].setY(rand() % (GAME_HEIGHT)+1);
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
{
	VECTOR2 collisionVector;
	for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
	{
		if (player.collidesWith(spitball[i], collisionVector) && spitball[i].getVisible()==true)
		{
			gameOver();
		}
	}

	if (player.collidesWith(fly, collisionVector) && fly.getVisible() == true)
	{
		gameOver();
	}

	if (player.collidesWith(spiderWeb, collisionVector) && spiderWeb.getVisible() == true)
	{
		gameOver();
	}
	if (player.collidesWith(tornado, collisionVector) && tornado.getVisible() == true)
	{
		slowPlayer();
	}
	
}

void flyGame::gameOver()
{
	player.damage(SPITBALL);
	player.setActive(false);
	player.setVisible(false);
	gameStart = 0;
	objectPoints = 0;
	spiderWeb.setVisible(false);
	fly.setVisible(false);
	for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
	{
		spitball[i].setVisible(false);
	}
}

void flyGame::slowPlayer()
{
	player.setV(-(playerNS::SPEED / 5));
}

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
		//frog.draw();
		spiderWeb.draw();
		fly.draw();
		tornado.draw();
		for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
		{
			spitball[i].draw();
		}
		dxFontMedium->setFontColor(graphicsNS::WHITE);
		dxFontMedium->print(to_string(displayTimer()), 0, 20);
		//dxFontMedium->print(to_string(displayTimer()), 0, 120);
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
	spitballTexture.onLostDevice();
	flyTexture.onLostDevice();
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
	spitballTexture.onResetDevice();
	flyTexture.onResetDevice();
	Game::resetAll();
	return;
}

float flyGame::displayTimer(){
	return frameTime;
}