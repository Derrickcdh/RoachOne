//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859

#include "invulnerable.h"

//=============================================================================
// default constructor
//=============================================================================
Invulnerable::Invulnerable() : Entity()
{
	spriteData.width = InvulnerableNS::WIDTH;           // size of Ship1
	spriteData.height = InvulnerableNS::HEIGHT;
	spriteData.x = InvulnerableNS::X;                   // location on screen
	spriteData.y = InvulnerableNS::Y;
	spriteData.rect.bottom = InvulnerableNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = InvulnerableNS::WIDTH;
	velocity.x = InvulnerableNS::SPEED;
	frameDelay = 1;
	startFrame = 0;                             // first frame of animation
	endFrame = 0;                           // last frame of animation
	currentFrame = startFrame;
	radius = InvulnerableNS::WIDTH / 2.0;
	collisionType = entityNS::CIRCLE;
	mass = InvulnerableNS::MASS;
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
bool Invulnerable::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}
void Invulnerable::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x = (spriteData.x - frameTime * velocity.x);
}