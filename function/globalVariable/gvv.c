#include "gvv.h"

extern int gtot;

void gTotal()
{
  for(int i=0; i<10; i++)
  {
    gtot += i;
  }
}

int getTotal()
{
  int tot = 0;
  for(int i=0; i<10; i++)
  {
    tot += i;
  }

  return tot;
}

void getTotal2()
{
  static int stot;
  for(int i=0; i<10; i++)
  {
    stot += i;
  }

  printf("stot(from getTotal) = %d\n", stot);
}