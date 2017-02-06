//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859

#ifndef _INVULNERABLE_H                 // Prevent multiple definitions if this 
#define _INVULNERABLE_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "game.h"

namespace InvulnerableNS
{
	const int WIDTH = 150;                   // image width
	const int HEIGHT = 150;                  // image height
	const int X = 0;   // location on screen
	const int Y = 0;
	const float SPEED = 200;                // pixels per second
	const float MIN_VY = 0;                 // minumum Y velocity
	const float MASS = 1.0f;
}

// inherits from Entity class
class Invulnerable : public Entity
{
private:
	boolean active = true;
public:
	// constructor
	Invulnerable();

	// inherited member functions
	void update(float frameTime);

	void InvulnerableCollideWith();
	//virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM);
	boolean getActive();
	void setActive(boolean flag);

};

#endif