#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME  20

typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef byte  RESULT;

#define NOERROR     0
#define ALLOC_FAIL  1

// typedef struct _MY_ITEM {
//   void * pPrev;
//   void * pNext;
// } MY_ITEM; 

typedef struct _EMPLOYEE {
  uint num = 0;
  char name[MAX_NAME] = {0};
  uint buseo = 0;
  uint jikguep = 0;
  // MY_ITEM link;
} EMPLOYEE;

typedef struct _LINKED_LIST {
  void *pStart = NULL;
  void *pCur = NULL;
  void *pEnd = NULL;
} LINKED_LIST;