//#pragma once

#include <stdio.h>
#include <stdlib.h>	// 랜덤함수
#include <time.h>	// 랜덤함수 초기화의 time(NULL)때문에 포함시킴
#include <memory.h>	// memset() 때문에 포함시킴
#include <conio.h>	// _getch()라는 함수때문에 포함시킴
#include <ctype.h>	// isdigit()라는 함수때문에 포함시킴


#define isTerminate(x)	(x == 'x' || x == 'X')

#define GOAL_COUNT		3

typedef unsigned int	UINT;
typedef unsigned char   byte;


void Randomize();

byte findInArray(byte* arr, int nSize, byte toFind);

void initValues(byte* arr, int nSize, byte n);

UINT arrayToDigit(byte* arr);

UINT inputFromUser(byte* arr, int nSize);

UINT CheckThisOut(byte* arrGoal, int nSize, byte* arrUser, int nSize2);
