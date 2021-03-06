//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, Ting hong yang
//  Student Number:     S10161350, S10159859, S10127976

#include "Fly.h"

Fly::Fly() : Entity()
{
	spriteData.width = FlyNS::WIDTH;           // size of asteroid
	spriteData.height = FlyNS::HEIGHT;
	spriteData.x = FlyNS::X;                   // location on screen
	spriteData.y = FlyNS::Y;
	spriteData.rect.bottom = FlyNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = FlyNS::WIDTH;
	velocity.x = 100;                             // velocity X
	velocity.y = 100;                             // velocity Y
	mass = FlyNS::MASS;
	collisionType = entityNS::CIRCLE;
	radius = FlyNS::WIDTH / 2.0;
	spriteData.scale = 1;
}
//=============================================================================
// Initialize the Asteroid.
// Post: returns true if successful, false if failed
//=============================================================================
bool Fly::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}
void Fly::draw()
{
	Image::draw();
}
void Fly::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x -= frameTime * velocity.x;         // move ship along X
	spriteData.y += (sin(spriteData.x / 10) * amplitude) / 5;

	if (spriteData.y > GAME_HEIGHT - FlyNS::HEIGHT) // if hit bottom screen edge
	{
		spriteData.y = GAME_HEIGHT - FlyNS::HEIGHT; // position at bottom screen edge
	}
}