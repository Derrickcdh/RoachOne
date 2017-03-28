//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, Ting hong yang
//  Student Number:     S10161350, S10159859, S10127976

#include "flyGame.h"
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <fstream>

time_t start;		// timer
int gameStart = 0;	//gameMode
int scorePoint = 0; //player score
int objectPoints;
int webPoints;
bool control;
time_t buffTime;
float bTime;
int tip = 0;
int buttonScale = 0;
bool scaleType;
float scaleNum = 1.0;
int highscore;

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


	// backgrounds texture
	if (!enterTexture.initialize(graphics, ENTER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backgrounds texture"));

	// backgrounds
	if (!enter.initialize(graphics, 0, 0, 0, &enterTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backgrounds"));


	// backgrounds texture
	if (!num2Texture.initialize(graphics, NUMKEY2_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backgrounds texture"));

	// backgrounds
	if (!num2.initialize(graphics, 0, 0, 0, &num2Texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing backgrounds"));

	//credits
	// credits 1 texture
	if (!creditsTexture.initialize(graphics, CREDITS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff texture"));

	// credits 1
	if (!credits.initialize(graphics, 0, 0, 0, &creditsTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff"));


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

	// speed buff 1 texture
	if (!speedBuffTexture.initialize(graphics, SPEED_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff texture"));

	// speed buff 1
	if (!speedBuff.initialize(this, InvulnerableNS::WIDTH, InvulnerableNS::HEIGHT, 0, &speedBuffTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff"));

	// Tips
	if (!hostileTexture.initialize(graphics, HOSTILE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff texture"));

	// Tips
	if (!hostile.initialize(graphics, 0, 0, 0, &hostileTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff"));

	// Tips
	if (!powerTexture.initialize(graphics, POWERUP_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff texture"));

	// Tips
	if (!power.initialize(graphics, 0, 0, 0, &powerTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing buff"));

	// Tips arrows
	if (!rightTexture.initialize(graphics, RIGHT_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing right texture"));

	// Tips arrows
	if (!right.initialize(graphics, 0, 0, 0, &rightTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing right"));


	// Tips arrows
	if (!leftTexture.initialize(graphics, LEFT_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing left texture"));

	// Tips arrows
	if (!left.initialize(graphics, 0, 0, 0, &leftTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing left"));

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
	enter.setX(GAME_WIDTH / 1.6);
	enter.setY(GAME_HEIGHT / 1.7);
	num2.setY(GAME_HEIGHT / 9.5);
	num2.setX(GAME_WIDTH / 1.4);

	power.setY(GAME_HEIGHT / 4.01);
	power.setX(0);
	hostile.setY(GAME_HEIGHT/4.01);
	hostile.setX(0);

	right.setY(GAME_HEIGHT / 3.5);
	right.setX(GAME_WIDTH / 3);
	left.setY(GAME_HEIGHT / 3.5);
	left.setX(GAME_WIDTH / 3);


	hostile.setVisible(true);
	power.setVisible(false);
	right.setVisible(true);
	left.setVisible(false);
}

//=============================================================================
// Update all game items
//=============================================================================
void flyGame::update()
{
	if (input->isKeyDown(VK_RETURN) && gameStart == 0)            // Game start level 1, 
	{
		fstream file1("pictures\\highscore.txt");
		int scores;
		while (!file1.eof())
		{
			file1 >> scores;
		}
		file1.close();
		highscore = (int)scores;
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
	
	if (input->isKeyDown(VK_RIGHT) && gameStart == 3 && tip == 0)
	{
		tip = 1;
		hostile.setVisible(false);
		power.setVisible(true);
		right.setVisible(false);
		left.setVisible(true);
	}
	if (input->isKeyDown(VK_LEFT) && gameStart == 3 && tip == 1)
	{
		tip = 0;
		hostile.setVisible(true);
		power.setVisible(false);
		right.setVisible(true);
		left.setVisible(false);
	}

	if (input->isKeyDown(VK_2) && gameStart == 3)
	{
		gameStart = 4;
	}
	if (input->isKeyDown(VK_RETURN) && gameStart == 4)
	{
		gameStart = 3;
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

	if (gameStart == 3)
	{
		if (gameStart == 3)
		{
			if (scaleType == true)
			{
				buttonScale++;
				scaleNum = scaleNum - 0.0002;
				right.setScale(scaleNum);
				left.setScale(scaleNum);
			}
			if (scaleType == false)
			{
				buttonScale--;
				scaleNum = scaleNum + 0.0002;
				right.setScale(scaleNum);
				left.setScale(scaleNum);
			}
			/*if (buttonScale == 5)
			{
				right.setScale(0.98);
				left.setScale(0.98);
			}
			if (buttonScale == 10)
			{
				right.setScale(0.9);
				left.setScale(0.9);
			}
			else if (buttonScale == 15)
			{
				right.setScale(0.85);
				left.setScale(0.85);
			}
			else if (buttonScale == 20)
			{
				right.setScale(0.8);
				left.setScale(0.8);
			}
			else if (buttonScale == 25)
			{
				right.setScale(0.75);
				left.setScale(0.75);
			}
			else if (buttonScale == 30)
			{
				right.setScale(0.70);
				left.setScale(0.70);
			}*/
			if (buttonScale > 50)
			{
				scaleType = false;
			}
			if (buttonScale <= 0)
			{
				scaleType = true;
			}
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
	if (scorePoint > highscore)
	{
		ofstream myfile("pictures\\highscore.txt");
		if (myfile.is_open())
		{
			myfile << scorePoint;
			myfile.close();
		}
		else cout << "Unable to open file";
		
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
	const int BUF_SIZE = 50;
	static char buffer[BUF_SIZE];
	graphics->spriteBegin();                // begin drawing sprites

	if (gameStart == 0)//render main menu
	{
		menu.draw();
		enter.draw();
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
		num2.draw();
		hostile.draw();
		power.draw();
		right.draw();
		left.draw();
		_snprintf_s(buffer, BUF_SIZE, "High Score: %d", highscore);
		dxFont->print(buffer, GAME_WIDTH / 1.8, GAME_HEIGHT / 4);

	}
	if (gameStart == 4) // game mode screen
	{
		credits.draw();
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
	creditsTexture.onLostDevice();
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
	creditsTexture.onResetDevice();
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

//int getHiscore()
//{
//	char currentHiscoreArray[15];
//	int currentHiscore;
//	fstream myfile;
//	myfile.open("pictures\\highscore.txt");
//	if (myfile.is_open())
//	{
//		myfile.getline(currentHiscoreArray, 128);
//		currentHiscore = (int)currentHiscoreArray;
//		return currentHiscore;
//	}
//	else return 0;
//}
//
//int getHiscore()
//{
//	fstream file1("pictures\\highscore.txt");
//	char scores;
//	while (!file1.eof())
//	{
//		file1 >> scores;
//	}
//	file1.close();
//	return (int)scores;
//}