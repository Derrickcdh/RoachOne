//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, Ting hong yang
//  Student Number:     S10161350, S10159859, S10127976

#include "frogTongue.h"

//=============================================================================
// default constructor
//=============================================================================
FrogTongue::FrogTongue() : Entity()
{
	spriteData.width = frogtongueNS::WIDTH;           // size of Ship1
	spriteData.height = frogtongueNS::HEIGHT;
	spriteData.x = frogtongueNS::X;                   // location on screen
	spriteData.y = frogtongueNS::Y;
	spriteData.rect.bottom = frogtongueNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = frogtongueNS::WIDTH;
	velocity.x = frogtongueNS::SPEED;                 // velocity Y
	radius = frogtongueNS::WIDTH / 2.0;
	collisionType = entityNS::CIRCLE;
	mass = frogtongueNS::MASS;
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
bool FrogTongue::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void FrogTongue::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.x -= frameTime * velocity.x;         // move along Y
}

/*void FrogTongue::draw()
{
	Image::draw();
}*/