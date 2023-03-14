#include <stdio.h>

int main() {
  
  // 2차원 배열의 선언과 초기화
  short nums[2][3] = {{8,9,10},{11,12,13}};
  for(int i=0; i<2; i++)
  {
    for(int j=0; j<3; j++) 
      printf("%d, ", nums[i][j]);
    
    printf("\n");
  }

  // 다른 방법으로 초기화 해보자
  // 위 nums 2차원 배열에 1부터 6까지 저장하고 출력하기
  for(int i=0; i<2; i++)
  {
    for(int j=0; j<3; j++) {
      nums[i][j] = (j+1)+(i*3);
      printf("%d, ", nums[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}