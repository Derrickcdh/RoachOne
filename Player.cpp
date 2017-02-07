//  Module:             GamePlay Programming
//  Assignment2:        Roach One
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, Ting hong yang
//  Student Number:     S10161350, S10159859, S10127976

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
	velocity.y = playerNS::SPEED;                 // velocity Y
	frameDelay = playerNS::PLAYER_ANIMATION_DELAY;
	startFrame = playerNS::PLAYER_START_FRAME;                             // first frame of animation
	endFrame = playerNS::PLAYER_END_FRAME;
	currentFrame = startFrame;
	radius = playerNS::WIDTH / 2.0;
	collisionType = entityNS::BOX;
	mass = playerNS::MASS;
	dying = false;
	flying = false;
	status = 0;
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
		//velocity.y -= frameTime * GRAVITY;              // gravity
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
	}
	//velocity.y = 0;
	velocity.y += frameTime * GRAVITY;              // gravity
}

void Player::setV(float v)
{
	velocity.y = v;
}

void Player::setflying(bool state)
{
	flying = state;
}

void Player::damage(WEAPON weapon)
{
	dying = true;
}

int Player::returnStatus()
{
	return status;
}


void Player::setStatus(int v)
{
	status = v;
}