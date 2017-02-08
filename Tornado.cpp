//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, Ting hong yang
//  Student Number:     S10161350, S10159859, S10127976

#include "Tornado.h"

Tornado::Tornado() : Entity()
{
	spriteData.width = TornadoNS::WIDTH;           // size of asteroid
	spriteData.height = TornadoNS::HEIGHT;
	spriteData.x = TornadoNS::X;                   // location on screen
	spriteData.y = TornadoNS::Y;
	spriteData.rect.bottom = TornadoNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = TornadoNS::WIDTH;
	velocity.x = 100;                             // velocity X
	velocity.y = 100;                             // velocity Y
	mass = TornadoNS::MASS;
	collisionType = entityNS::CIRCLE;
	radius = TornadoNS::WIDTH/2;
	spriteData.scale = 1;
}
//=============================================================================
// Initialize the Asteroid.
// Post: returns true if successful, false if failed
//=============================================================================
bool Tornado::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}
void Tornado::draw()
{
	Image::draw();
}
void Tornado::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x -= frameTime * velocity.x;         
}
