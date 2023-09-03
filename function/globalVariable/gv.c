#include "gvv.h"

int gtot = 0;

int main()
{

  int tot =0;
  for(int i=0; i<10; i++)
  {
    tot += i;
  }
  printf("tot = %d\n", tot);

  {
    printf("tot = %d\n", tot);

    int tot = 0;
    for(int i=0; i<100; i++)
    {
      tot += i;
    }
    printf("tot(local) = %d\n", tot);
  }

  printf("tot = %d\n", tot);

  gTotal();
  printf("gtot = %d\n", gtot);

  gTotal();
  printf("gtot = %d\n", gtot);

  tot = getTotal();
  printf("tot(from getTotal) = %d\n", tot);

  getTotal2();  
  getTotal2();

  return 0;
}