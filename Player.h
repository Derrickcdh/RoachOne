#ifndef Player_h               // Prevent multiple definitions if this 
#define Player_h               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "game.h"

namespace playerNS
{
	const int WIDTH = 60;                   // image width
	const int HEIGHT = 60;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float SPEED = 0.1;                // pixels per second
	const float MIN_VY = 0;                 // minumum Y velocity
	const float MASS = 1.0f;
}

// inherits from Entity class
class Player : public Entity
{
public:
	// constructor
	Player();

	// inherited member functions
	void update(float frameTime);

	void drop(float frameTime);
};
#endif