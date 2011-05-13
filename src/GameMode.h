#ifndef __TUNNEL_GAMEMODE_INC
#define __TUNNEL_GAMEMODE_INC

#define GAME

#ifdef GAME
    #define WINDOW_MODE OF_GAME_MODE
    #define WIDTH 1680
    #define HEIGHT 1050
#else
    #define WINDOW_MODE OF_WINDOW
    #define WIDTH 1024
    #define HEIGHT 768
#endif

#endif