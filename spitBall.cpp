//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, Ting hong yang
//  Student Number:     S10161350, S10159859, S10127976

#include "Spitball.h"
#include <stdlib.h>     /* srand, rand */

spitBall::spitBall() : Entity()
{
	spriteData.width = spitballNS::WIDTH;           // size of asteroid
	spriteData.height = spitballNS::HEIGHT;
	spriteData.x = spitballNS::X;                   // location on screen
	spriteData.y = spitballNS::Y;
	spriteData.rect.bottom = spitballNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = spitballNS::WIDTH;
	velocity.x = 150;                             // velocity X
	velocity.y = 0;                             // velocity Y
	radius = spitballNS::WIDTH / 2.0;
	mass = spitballNS::MASS;
	collisionType = entityNS::CIRCLE;
	spriteData.scale = 1;
}

//=============================================================================
// Initialize the Spit Ball.
// Post: returns true if successful, false if failed
//=============================================================================
bool spitBall::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}
void spitBall::draw()
{
	Image::draw();
}
void spitBall::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x -= frameTime * velocity.x;         // move ship along X
	if (spriteData.y > GAME_HEIGHT - spitballNS::HEIGHT) // if hit bottom screen edge
	{
		spriteData.y = GAME_HEIGHT - spitballNS::HEIGHT; // position at bottom screen edge
	}
	spriteData.angle += (frameTime*spitballNS::ROTATION_RATE);
	/*if (spriteData.x < (-100));
	{
		spriteData.x = GAME_WIDTH;
		spriteData.y= (rand() % (GAME_HEIGHT)+1);
	}*/
}
