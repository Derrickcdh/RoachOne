#ifndef _FLY_H
#define _FLY_H
#define WIN32_LEAN_AND_MEAN
#include "entity.h"
#include "constants.h"
#include <math.h>
namespace FlyNS
{
	const int WIDTH = 150;
	const int HEIGHT = 150;
	const int X = 0;   // location on screen
	const int Y = 0;
	const float ROTATION_RATE = 0; // radians per second
	const float SPEED = 0;                  // 0 pixels per second
	const float MASS = 100.0f;              // mass
}
class Fly : public Entity
{
private:
	boolean active = true;
	int amplitude = 5;
public:
	// constructor
	Fly();
	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
	boolean getActive();
	void setActive(boolean flag);
};
#endif // !_SPITBALL_H
