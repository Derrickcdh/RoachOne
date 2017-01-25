#ifndef _SPIDERWEB_H               // Prevent multiple definitions if this 
#define _SPIDERWEB_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "game.h"

namespace SpiderWebNS
{
	const int WIDTH = 60;                   // image width
	const int HEIGHT = 60;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float SPEED = 0;                // pixels per second
	const float MIN_VY = 0;                 // minumum Y velocity
	const float MASS = 1.0f;
}

// inherits from Entity class
class SpiderWeb : public Entity
{
public:
	// constructor
	SpiderWeb();

	// inherited member functions
	void update(float frameTime);

	void spiderWebCollideWith();
};

#endif