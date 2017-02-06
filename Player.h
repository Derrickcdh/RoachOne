//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859

#ifndef Player_h               // Prevent multiple definitions if this 
#define Player_h               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "game.h"

namespace playerNS
{
	const int WIDTH = 180;                   // image width
	const int HEIGHT = 130;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float SPEED = 1;                // pixels per second
	const float MIN_VY = 0;                 // minumum Y velocity
	const float MASS = 1.0f;
	const int   TEXTURE_COLS = 2;           // texture has 8 columns
	const int   PLAYER_START_FRAME = 0;      // ship1 starts at frame 0
	const int   PLAYER_END_FRAME = 3;        // ship1 animation frames 0,1,2,3
	const int   FLYPLAYER_START_FRAME = 4;      // ship1 starts at frame 4
	const int   FLYPLAYER_END_FRAME = 4;        // ship1 animation frames 4
	const float PLAYER_ANIMATION_DELAY = 0.2f;    // time between frames
}

// inherits from Entity class
class Player : public Entity
{
private:
	bool flying;
	bool dying;
	int status;
public:
	// constructor
	Player();

	// inherited member functions
	void update(float frameTime);

	void drop(float frameTime);
	
	void setV(float v);

	void setflying(bool f);

	void damage(WEAPON);

	void setStatus(int i);

	int returnStatus();
	
};
#endif