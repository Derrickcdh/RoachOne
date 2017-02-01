//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859

#ifndef _SPITBALL_H
#define _SPITBALL_H
#define WIN32_LEAN
#include "entity.h"
#include "constants.h"

namespace spitballNS
{
const int WIDTH = 150;
const int HEIGHT = 150;
const int X = 0;   // location on screen
const int Y = 0;
const float ROTATION_RATE = 0; // radians per second
const float SPEED = 0;                  // 0 pixels per second
const float MASS = 100.0f;              // mass
const int   TEXTURE_COLS = 8;
const int   ASTEROID_START_FRAME = 0;
const int   ASTEROID_END_FRAME = 7;
const float ASTEROID_ANIMATION_DELAY = 0.1f;    // time between frames
}

class spitBall : public Entity
{
private:
	boolean active = true;

public:
	// constructor
	spitBall();
	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM);
	void update(float frameTime);
	boolean getActive();
	void setActive(boolean flag);
};
#endif // !_SPITBALL_H
