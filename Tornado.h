//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, Ting hong yang
//  Student Number:     S10161350, S10159859, S10127976

#ifndef _TORNADO_H
#define _TORNADO_H
#define WIN32_LEAN_AND_MEAN
#include "entity.h"
#include "constants.h"
#include <math.h>

namespace TornadoNS
{
	const int WIDTH = GAME_WIDTH/2;
	const int HEIGHT = 300;
	const int X = 0;   // location on screen
	const int Y = 0;
	const float ROTATION_RATE = 0; // radians per second
	const float SPEED = 0;                  // 0 pixels per second
	const float MASS = 100.0f;              // mass
}
class Tornado : public Entity
{
private:
	boolean active = true;
public:
	// constructor
	Tornado();
	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	boolean getActive();
	void setActive(boolean flag);
};
#endif 
