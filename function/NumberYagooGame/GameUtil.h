#ifndef ___NUMBER_YAGOO_GAME_H___20230323__18195700___
#define ___NUMBER_YAGOO_GAME_H___20230323__18195700___

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
// #include <curses.h>

#define CHECK_PARAM(x,y)    if ( x==NULL || y==0 ) return 0;


typedef unsigned char   byte;
typedef unsigned short  USHORT;
typedef unsigned int    UINT;

void randomize();
byte findInArray(byte *arr, UINT nSize, byte toFind);
byte initRandomValues(byte *arr, UINT nSize, UINT range);

#endif