//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, Ting hong yang
//  Student Number:     S10161350, S10159859, S10127976

#include "speedUp.h"

//=============================================================================
// default constructor
//=============================================================================
SpeedUp::SpeedUp() : Entity()
{
	spriteData.width = SpeedUpNS::WIDTH;           // size of Ship1
	spriteData.height = SpeedUpNS::HEIGHT;
	spriteData.x = SpeedUpNS::X;                   // location on screen
	spriteData.y = SpeedUpNS::Y;
	spriteData.rect.bottom = SpeedUpNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = SpeedUpNS::WIDTH;
	velocity.x = SpeedUpNS::SPEED;
	frameDelay = 1;
	startFrame = 0;                             // first frame of animation
	endFrame = 0;                           // last frame of animation
	currentFrame = startFrame;
	radius = SpeedUpNS::WIDTH / 2.0;
	collisionType = entityNS::CIRCLE;
	mass = SpeedUpNS::MASS;
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
bool SpeedUp::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}
void SpeedUp::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x = (spriteData.x - frameTime * velocity.x);
}