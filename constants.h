//  Module:             GamePlay Programming
//  Assignment2:        Sushi Master
//  Student Name:       Choong Di Han Derrick, Andre hiu yuan xiang, ting hong yang
//  Student Number:     S10161350, S10127976, S10159859



#ifndef _CONSTANTS_H            // prevent multiple definitions if this 
#define _CONSTANTS_H            // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#define VK_0 0x30

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)


//-----------------------------------------------
//                  Constants
//-----------------------------------------------
// window
const char CLASS_NAME[] = "SushiMaster";
const char GAME_TITLE[] = "SushiMaster";
const bool FULLSCREEN = true;              // windowed or fullscreen
const UINT GAME_WIDTH =  1280;               // width of game in pixels
const UINT GAME_HEIGHT = 720;               // height of game in pixels
 
// game
const double PI = 3.14159265;
const float FRAME_RATE  = 200.0f;               // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const float GRAVITY = 500.0f;                   // acceleration of gravity pixels/sec

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY      = VK_ESCAPE;   // escape key
const UCHAR ALT_KEY      = VK_MENU;     // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;   // Enter key

// graphic images
const char BACKGROUND_IMAGE[] = "pictures\\background.png";
const char BACKGROUNDS_IMAGE[] = "pictures\\background.png";
const char ROACHONE_MENU[] = "pictures\\RoachOne.jpg";  // Photo of Japan flag
const char GAMEMODE_IMAGE[] = "pictures\\Intro&GameMode.jpg";
const char MODE1_IMAGE[] = "pictures\\gamemode1.jpg";
const char MODE2_IMAGE[] = "pictures\\gamemode2.jpg";
const char PLAYER_IMAGE[] = "pictures\\roach.jpg";
const int  ZENTT_START_FRAME = 0;         // starting frame of ship animation
const int  ZENTT_END_FRAME = 0;           // last frame of ship animation
const float ZENTT_ANIMATION_DELAY = 0.2f; // time between frames of ship animation
const int  ZENTT_COLS = 2;                // ship texture has 2 columns
const int  ZENTT_WIDTH = 300;              // width of ship image
const int  ZENTT_HEIGHT = 300;             // height of ship image
const float ROTATION_RATE = 30.0f;             // degrees per second
const float SCALE_RATE = 0.42f;                  // % change per second
const float ZENTT_SPEED = 100.0f;                // pixels per second
const float ZENTT_SCALE = 1.5f;                  // starting ship scale

//Score and start A
const int SCORE_COLS = 1;
const int SCORE_WIDTH = 65;
const int SCORE_HEIGHT = 65;

#endif