#include "Player.h"
//=============================================================================
// default constructor
//=============================================================================
Player::Player() : Entity()
{
	spriteData.width = playerNS::WIDTH;           // size of Ship1
	spriteData.height = playerNS::HEIGHT;
	spriteData.x = playerNS::X;                   // location on screen
	spriteData.y = playerNS::Y;
	spriteData.rect.bottom = playerNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = playerNS::WIDTH;
	velocity.x = playerNS::SPEED;                 // velocity X
	velocity.y = playerNS::SPEED;                 // velocity Y
	frameDelay = 1;
	startFrame = 0;                             // first frame of animation
	endFrame = 0;                           // last frame of animation
	currentFrame = startFrame;
	radius = playerNS::WIDTH / 2.0;
	collisionType = entityNS::BOX;
	mass = playerNS::MASS;
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Player::update(float frameTime)
{
	Entity::update(frameTime);
	spriteData.y -= frameTime * velocity.y;         // move along Y

	
	if (spriteData.y > GAME_HEIGHT - playerNS::HEIGHT) // if hit bottom screen edge
	{
		spriteData.y = GAME_HEIGHT - playerNS::HEIGHT; // position at bottom screen edge
	}
	else if (spriteData.y < 0)                    // else if hit top screen edge
	{
		spriteData.y = 0;                           // position at top screen edge
		//velocity.y = -velocity.y;                   // reverse Y direction
	}

}

void Player::drop(float frameTime)
{
	Entity::update(frameTime);
	spriteData.y += frameTime * velocity.y;         // move along Y
	if (spriteData.y > GAME_HEIGHT - playerNS::HEIGHT) // if hit bottom screen edge
	{
		spriteData.y = GAME_HEIGHT - playerNS::HEIGHT; // position at bottom screen edge
	}
	else if (spriteData.y < 0)                    // else if hit top screen edge
	{
		spriteData.y = 0;                           // position at top screen edge
		//velocity.y = -velocity.y;                   // reverse Y direction
	}
	velocity.y -= frameTime * GRAVITY;              // gravity
}
