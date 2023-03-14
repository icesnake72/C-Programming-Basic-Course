#include <stdio.h>

int main() {
  
  short nums[2][3] = {{8,9,10},{11,12,13}};
  for(int i=0; i<2; i++)
  {
    for(int j=0; j<3; j++) 
      printf("%d, ", nums[i][j]);
    
    printf("\n");
  }
    

  return 0;
}