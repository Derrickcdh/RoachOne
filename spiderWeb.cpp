//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859

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
	collisionType = entityNS::CIRCLE;
	mass = SpiderWebNS::MASS;
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
//bool SpiderWeb::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
//{
//	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
//}
void SpiderWeb::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x = (spriteData.x - frameTime * FLY_SPEED);
}