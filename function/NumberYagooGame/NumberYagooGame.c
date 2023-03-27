#include "GameUtil.h"

int main()
{
  randomize();

  byte goal[3] = {0};

  for(int i=0; i<10; i++)
  {
    initRandomValues(goal, 3, 9);
    for(int j=0; j<3; j++)
      printf("%d", goal[j]);

    printf("\n");
  }

  // char ch = getch(); 
  // printf("%c", ch);

  return 0;
}