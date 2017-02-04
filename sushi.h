//  Module:             GamePlay Programming
//  Assignment2:        Sushi Master
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859


#ifndef _SUSHI_H             // prevent multiple definitions if this 
#define _SUSHI_H             // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN
using namespace std;

class sushi
{
protected:

public:
	// Constructor
	sushi();
	// Destructor
	virtual ~sushi();
	void initialize();
	void setCurrentOrder(int i);
	int getCurrentOrder();
	bool checkSushi(int assembledsushi[]);
	//string getSushiType();
	int getRandom();
	//int returnRandom();
};
#endif