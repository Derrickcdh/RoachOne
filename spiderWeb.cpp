#include "spiderWeb.h"

//=============================================================================
// default constructor
//=============================================================================
SpiderWeb::SpiderWeb() : Entity()
{
	spriteData.width = SpiderWebNS::WIDTH;           // size of Ship1
	spriteData.height = SpiderWebNS::HEIGHT;
	spriteData.x = SpiderWebNS::X;                   // location on screen
	spriteData.y = SpiderWebNS::Y;
	spriteData.rect.bottom = SpiderWebNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = SpiderWebNS::WIDTH;
	velocity.y = SpiderWebNS::SPEED;
	frameDelay = 1;
	startFrame = 0;                             // first frame of animation
	endFrame = 0;                           // last frame of animation
	currentFrame = startFrame;
	radius = SpiderWebNS::WIDTH / 2.0;
	collisionType = entityNS::BOX;
	mass = SpiderWebNS::MASS;
}


//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void SpiderWeb::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x = (spriteData.x - frameTime * ZENTT_SPEED);
}