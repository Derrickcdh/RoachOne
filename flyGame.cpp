//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, Ting hong yang
//  Student Number:     S10161350, S10159859, S10127976

#include "flyGame.h"
#include <stdlib.h>     /* srand, rand */

time_t start;		// timer
int gameStart = 0;	//gameMode
int scorePoint = 0; //player score
int objectPoints;
int webPoints;
bool control;
time_t buffTime;
float bTime;

//double seconds;
//=============================================================================
// Constructor
//=============================================================================
flyGame::flyGame()
{
	dxFontMedium = new TextDX();
	dxFont = new TextDX();
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

	// frog tongue texture
	if (!frogtongueTexture.initialize(graphics, FROGTONGUE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frog tongue texture"));

	// frog tongue
	if (!frogtongue.initialize(this, frogtongueNS::WIDTH, frogtongueNS::HEIGHT, 0, &frogtongueTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frog tongue"));

	// frog texture
	if (!frogTexture.initialize(graphics, FROG_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frog texture"));

	// frog
	if (!frog.initialize(graphics, FROG_WIDTH, FROG_HEIGHT, FROG_COLS, &frogTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing frog"));

	// score
	if (dxFontMedium->initialize(graphics, 62, true, false, "Calibri") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	// buff & game over
	if (dxFont->initialize(graphics, 62, true, false, "Calibri") == false)
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

	// buff 1 texture
	if (!buffInvulnerabletexture.initialize(graphics, Invulnerable_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff texture"));

	// buff 1
	if (!buffInvulnerable.initialize(this, InvulnerableNS::WIDTH, InvulnerableNS::HEIGHT, 0, &buffInvulnerabletexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff"));

	// buff 1 texture
	if (!speedBuffTexture.initialize(graphics, SPEED_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff texture"));

	// buff 1
	if (!speedBuff.initialize(this, InvulnerableNS::WIDTH, InvulnerableNS::HEIGHT, 0, &speedBuffTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff"));


	background.setX(GAME_WIDTH / GAME_WIDTH);
	backgrounds.setX(GAME_WIDTH / 1);

	player.setX(100);
	player.setY(GAME_HEIGHT - 100);
	player.setFrames(playerNS::PLAYER_START_FRAME, playerNS::PLAYER_END_FRAME);
	player.setCurrentFrame(playerNS::PLAYER_START_FRAME);

	/*frogtongue.setVisible(false);
	frogtongue.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);

	frog.setVisible(true);
	frog.setX(GAME_WIDTH / 1.05);
	frog.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);*/

	for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
	{
		spitball[i].setX(GAME_WIDTH);
		spitball[i].setY((rand() % (GAME_HEIGHT/10)+1)*10);

		int ast = rand() % 5+200;
		spitball[i].setVelocity(VECTOR2(ast, -ast));
		spitball[i].setVisible(false);
	}
	spiderWeb.setVisible(false);
	spiderWeb.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);
	fly.setX(GAME_WIDTH);

	tornado.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);
	tornado.setX(GAME_WIDTH);

	buffInvulnerable.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);
	buffInvulnerable.setX(GAME_WIDTH);

	speedBuff.setY((rand() % (GAME_HEIGHT / 10) + 10) * 10);
	speedBuff.setY(GAME_HEIGHT/2);
	speedBuff.setX(GAME_WIDTH);
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
	if (input->isKeyDown(VK_SPACE) && gameStart == 3)
	{
		PlaySound(TEXT("pictures\\dotto.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

		gameStart = 1;		//set the game mode
		start = time(0);	//start the timer
		scorePoint = 0;		//reset the score
		elapsed_secs = 0;
		player.setActive(true);
		player.setVisible(true);
		resetObjects();
		player.setY(GAME_HEIGHT - 100);
		objectPoints = 10;
		selectObject();
		control = true;
		
		/*if (fly.getVisible() == false)
		{
		PlaySound(TEXT("pictures\\FlyBuzzing.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		}

		if (tornado.getVisible() == false)
		{
		PlaySound(TEXT("pictures\\Wind.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		}*/
	}
	if (gameStart == 1 && control == true)
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
		if (player.returnStatus() == 3)
		{
			updateObjectMovement();
		}
		if (player.returnStatus() != 0 || player.returnStatus() != 2)
		{
			bTime = difftime(time(0), buffTime);
			if (bTime > buffTimer)
			{
				player.setStatus(0);
				buffTime = 0;
			}
		}
		
	}
	else if (gameStart == 1 && control == false)
	{
		player.drop(frameTime);
		player.setY(player.getY() - playerNS::SPEED * 1);
		updateObjFrameTime();
		for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
		{
			spitball[i].update(frameTime);
		}
		if (input->isKeyDown(VK_RETURN))
		{
			spiderWeb.setVisible(false);
			fly.setVisible(false);
			//frogtongue.setVisible(false);
			//frog.setVisible(false);
			for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
			{
				spitball[i].setVisible(false);
			}
			player.flipVertical(false);
			gameStart = 0;
			elapsed_secs = 0;
			player.setStatus(0);
		}
	}
}

void flyGame::selectObject()
{
	if (objectPoints >= 1)
	{
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

	/*if (frogtongue.getVisible() == false)
	{
		frogtongue.setVisible(true);
		frogtongue.setX(GAME_WIDTH);
		frogtongue.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);
	}

	if (frog.getVisible() == false)
	{
		frog.setVisible(true);
		frog.setX(GAME_WIDTH);
		frog.setY((rand() % (GAME_HEIGHT / 10) + 1) * 10);
	}*/
}

void flyGame::updateObjectMovement()
{
	background.setX(background.getX() - frameTime * FLY_SPEED);
	backgrounds.setX(backgrounds.getX() - frameTime * FLY_SPEED);
	scorePoint++;

	if (backgrounds.getX() <= 0)
	{
		background.setX(GAME_WIDTH / GAME_WIDTH);
		backgrounds.setX(GAME_WIDTH / 1);
		objectPoints += 1;
		selectObject();
	}

	/*if (frogtongue.getX() < -1025)
	{
		frogtongue.setVisible(false);
	}

	if (frog.getX() < -150)
	{
		frog.setVisible(false);
	}*/

	if (spiderWeb.getX() < -300)
	{
		spiderWeb.setVisible(false);
	}
	updateObjFrameTime();
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
		}
	}
	if (tornado.getX() < -1000)
	{
		tornado.setX(rand() % (GAME_WIDTH * 2)+(GAME_WIDTH));
		tornado.setY(rand() % (GAME_HEIGHT/2)+10);
	}
	if (buffInvulnerable.getX() < -1000)
	{
		buffInvulnerable.setX(rand() % (GAME_WIDTH * 10) + (GAME_WIDTH));
		buffInvulnerable.setY(rand() % (GAME_HEIGHT / 2) + 10);
		buffInvulnerable.setVisible(true);
	}

	if (speedBuff.getX() < -1000)
	{
		speedBuff.setX(rand() % (GAME_WIDTH * 5) + (GAME_WIDTH));
		speedBuff.setY(rand() % (GAME_HEIGHT / 2) + 10);
		speedBuff.setVisible(true);
	}
}

void flyGame::updateObjFrameTime()
{
	//frogtongue.update(frameTime);
	//frog.update(frameTime);
	spiderWeb.update(frameTime);
	fly.update(frameTime);
	tornado.update(frameTime);
	buffInvulnerable.update(frameTime);
	speedBuff.update(frameTime);
}

void flyGame::resetObjects()
{
	//frogtongue.setVisible(false);
	//frog.setVisible(false);
	spiderWeb.setVisible(false);
	fly.setVisible(false);
	for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
	{
		spitball[i].setVisible(false);
	}
	for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
	{
		spitball[i].update(frameTime);
		spitball[i].setX(GAME_WIDTH);
		spitball[i].setY(rand() % (GAME_HEIGHT)+1);
	}
	speedBuff.setX(rand() % (GAME_WIDTH * 5) + (GAME_WIDTH));
	speedBuff.setY(rand() % (GAME_HEIGHT / 2) + 10);
	buffInvulnerable.setX(rand() % (GAME_WIDTH * 10) + (GAME_WIDTH));
	buffInvulnerable.setY(rand() % (GAME_HEIGHT / 2) + 10);
	tornado.setX(GAME_WIDTH);
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
	if (player.returnStatus() != 1)
	{
		for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
		{
			if (player.collidesWith(spitball[i], collisionVector) && spitball[i].getVisible() == true)
			{
				gameOver();
			}
		}

		/*if (player.collidesWith(frogtongue, collisionVector) && frogtongue.getVisible() == true)
		{
		gameOver();
		}*/
		if (player.collidesWith(fly, collisionVector) && fly.getVisible() == true)
		{
			gameOver();
		}

		if (player.collidesWith(spiderWeb, collisionVector) && spiderWeb.getVisible() == true)
		{
			gameOver();
		}
		
	}
	if (player.collidesWith(tornado, collisionVector) && tornado.getVisible() == true)
	{
		slowPlayer();
	}
	if (player.collidesWith(buffInvulnerable, collisionVector) && buffInvulnerable.getVisible() == true && player.returnStatus() != 2)
	{
		player.setStatus(1);
		buffInvulnerable.setVisible(false);
		buffTime = time(0);
		begin = clock();
	}
	if (player.collidesWith(speedBuff, collisionVector) && speedBuff.getVisible() == true && player.returnStatus()!=2)
	{
		player.setStatus(3);
		speedBuff.setVisible(false);
		buffTime = time(0);
		begin = clock();
	}
}

void flyGame::gameOver()
{
	player.damage(SPITBALL);
	player.setActive(false);
	player.flipVertical(true);
	objectPoints = 0;
	control = false;
	player.setStatus(2);
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
	const int BUF_SIZE = 50;
	static char buffer[BUF_SIZE];
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
		//frogtongue.draw();
		//frog.draw();
		spiderWeb.draw();
		fly.draw();
		tornado.draw();
		buffInvulnerable.draw();
		speedBuff.draw();

		for (int i = 0; i < (sizeof(spitball) / sizeof(spitBall)); i++)
		{
			spitball[i].draw();
		}
		dxFontMedium->setFontColor(graphicsNS::WHITE);
		dxFontMedium->print(to_string((int)displayTimer()), 0, 20);
		dxFont->setFontColor(graphicsNS::BLACK);
		if (player.returnStatus() == 1)
		{
			
			_snprintf_s(buffer, BUF_SIZE, "         Invulnerable %d", (int)displayDifference());
			dxFont->print(buffer, GAME_WIDTH / 4, GAME_HEIGHT / 2);
		}

		if (player.returnStatus() == 2)
		{
			_snprintf_s(buffer, BUF_SIZE, "Game Over, Press Enter to return");
			dxFont->print(buffer, GAME_WIDTH / 4, GAME_HEIGHT / 2);
		}

		if (player.returnStatus() == 3)
		{
			_snprintf_s(buffer, BUF_SIZE, "         Speed UP! %d", (int)displayDifference());
			dxFont->print(buffer, GAME_WIDTH / 4, GAME_HEIGHT / 2);
		}
	}
	// Game Mode
	if (gameStart == 3) // game mode screen
	{
		gamemode.draw();
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
	playerTexture.onLostDevice();
	//frogtongueTexture.onLostDevice();
	//frogTexture.onLostDevice();
	spitballTexture.onLostDevice();
	flyTexture.onLostDevice();
	spiderWebTexture.onLostDevice();
	TornadoTexture.onLostDevice();
	speedBuffTexture.onLostDevice();
	buffInvulnerabletexture.onLostDevice();
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
	playerTexture.onResetDevice();
	//frogtongueTexture.onResetDevice();
	//frogTexture.onResetDevice();
	spitballTexture.onResetDevice();
	flyTexture.onResetDevice();
	TornadoTexture.onResetDevice();
	speedBuffTexture.onResetDevice();
	buffInvulnerabletexture.onResetDevice();
	Game::resetAll();
	return;
}

float flyGame::displayTimer(){
	return (float)scorePoint;
}

float flyGame::displayDifference(){
	end = clock();
	elapsed_secs = int(end - begin) / CLOCKS_PER_SEC;
	return buffTimer - elapsed_secs;

}

int getHiscore(int score)
{
	char currentHiscoreArray[10];
	int currentHiscore;
	fstream myfile;
	myfile.open("hiscore.txt");
	if (myfile.is_open())
	{
		myfile.getline(currentHiscoreArray, 128);

		return 0;
	}
}