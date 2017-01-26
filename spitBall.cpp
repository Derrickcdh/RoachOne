//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859

#include "Spitball.h"

spitBall::spitBall() : Entity()
{
spriteData.width = spitballNS::WIDTH;           // size of asteroid
spriteData.height = spitballNS::HEIGHT;
spriteData.x = spitballNS::X;                   // location on screen
spriteData.y = spitballNS::Y;
spriteData.rect.bottom = spitballNS::HEIGHT;    // rectangle to select parts of an image
spriteData.rect.right = spitballNS::WIDTH;
velocity.x = 0;                             // velocity X
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
	spriteData.x += frameTime * velocity.x;         // move ship along X
}
