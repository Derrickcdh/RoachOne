//  Module:             GamePlay Programming
//  Assignment2:        Sushi Master
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859



#include "sushi.h"
#include <iostream>
using namespace std;
#include <stdlib.h>     /* srand, rand */


int currentSushi[3];
int order;
int oldorder;
string sushiType;
int random = (rand() % 1);

//=============================================================================
// Constructor
//=============================================================================
sushi::sushi()
{

}

//=============================================================================
// Destructor
//=============================================================================
sushi::~sushi()
{

}


void sushi::initialize()
{

	return;
}

void sushi::setCurrentOrder(int i)
{
	if (i == 1)//if level one, only select the first 3 sushi
	{
		i = 3;
	}
	if (i == 2)// if level two, select all sushis
	{
		i = 9;
	}
	oldorder = order;			// remember the pervious order
	while (order == oldorder)	//ensure that the same order don't appear twice (just to make the game a little nicer to play)
	{
		order = rand() % (i) + 1; //randomize a number
	}
	if (order == 1)
	{
		currentSushi[0] = 5;	//set first item in the array
		currentSushi[1] = 3;	//set seconds item in the array
		currentSushi[2] = 1;	//set third item in the array
		int i = 1;				//just a buffer (some issues where the program forgot the first item in the array)
		sushiType = "Salmon Nigiri";	//to indicate which sushi
		order = 1;				//the order at this point (for bug fixes)
	}
	if (order == 2)
	{
		currentSushi[0] = 5;
		currentSushi[1] = 1;
		currentSushi[2] = 3;
		int i = 1;
		sushiType = "Salmon Gunkan";
		order = 2;
	}
	if (order == 3)
	{
		currentSushi[0] = 1;
		currentSushi[1] = 5;
		currentSushi[2] = 3;
		int i = 1;
		sushiType = "Salmon Maki";
		order = 3;
	}
	if (order == 4)
	{
		currentSushi[0] = 5;
		currentSushi[1] = 2;
		currentSushi[2] = 1;
		int i = 1;
		sushiType = "Cucumber Nigiri";
		order = 4;
	}
	if (order == 5)
	{
		currentSushi[0] = 5;
		currentSushi[1] = 1;
		currentSushi[2] = 2;
		int i = 1;
		sushiType = "Cucumber Gunkan";
		order = 5;
	}
	if (order == 6)
	{
		currentSushi[0] = 1;
		currentSushi[1] = 5;
		currentSushi[2] = 2;
		sushiType = "Cucumber Maki";
		order = 6;
	}
	if (order == 7)
	{
		currentSushi[0] = 5;
		currentSushi[1] = 4;
		currentSushi[2] = 1;
		sushiType = "Tamago Nigiri";
		order = 7;
	}
	if (order == 8)
	{
		currentSushi[0] = 5;
		currentSushi[1] = 1;
		currentSushi[2] = 4;
		sushiType = "Tamago Gunkan";
		order = 8;
	}
	if (order == 9)
	{
		currentSushi[0] = 1;
		currentSushi[1] = 5;
		currentSushi[2] = 4;
		sushiType = "Tamago Maki";
		order = 9;
	}
}

int sushi::getCurrentOrder() // returning order was odd, it kept returning 2 for some reason, i had to tweak it to return string instead
{
	if (sushiType == "Salmon Nigiri")
	{
		return 1;
	}
	if (sushiType == "Salmon Gunkan")
	{
		return 2;
	}
	if (sushiType == "Salmon Maki")
	{
		return 3;
	}
	if (sushiType == "Cucumber Nigiri")
	{
		return 4;
	}
	if (sushiType == "Cucumber Gunkan")
	{
		return 5;
	}
	if (sushiType == "Cucumber Maki")
	{
		return 6;
	}
	if (sushiType == "Tamago Nigiri")
	{
		return 7;
	}
	if (sushiType == "Tamago Gunkan")
	{
		return 8;
	}
	if (sushiType == "Tamago Maki")
	{
		return 9;
	}
	return 0;
}

//string sushi::getSushiType()
//{
//	return sushiType;
//}
bool sushi::checkSushi(int assembledSushi[3]) // checking sushi, if player had the wrong order, return false.
{
	int rounds = 0;
	while (true)
	{
		if (assembledSushi[rounds] == currentSushi[rounds])
		{
			rounds++;
			if (rounds == 3)
			{
				break;
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}
//int returnRandom()
//{
//	return random;
//}