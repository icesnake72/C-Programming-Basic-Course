#include <stdio.h>

int main() 
{
  printf("============================\n");
  // 2차원 배열의 선언과 초기화
  short nums[2][3] = {{8,9,10},{11,12,13}};
  for(int i=0; i<2; i++)
  {
    for(int j=0; j<3; j++) 
      printf("%d, ", nums[i][j]);
    
    printf("\n");
  }

  printf("============================\n");

  // 다른 방법으로 초기화 해보자
  // 위 nums 2차원 배열에 1부터 6까지 저장하고 출력하기
  for(int i=0; i<2; i++)
  {
    for(int j=0; j<3; j++) {
      // 일반적으로 다차원배열에 순차적으로 접근할때는
      // 첨자(index)의 뒷부분부터 증가시키며 값을 대입하는것이 좋다.
      nums[i][j] = (j+1)+(i*3);
      printf("%d, ", nums[i][j]);
    }
    printf("\n");
  }

  printf("============================\n");

  // 1차원 배열에서 배열의 이름은 포인터였다.
  // 2차원 배열에서도 배열의 이름은 당연히 포인터일것이다.
  // 어떻게 사용되는지 알아보자.
  printf("nums = %p\n", nums);
  for(int i=0; i<2; i++)
  {
    for(int j=0; j<3; j++) {
      printf("&nums[%d][%d] = %p\n", i, j, &nums[i][j]);
      printf("nums[%d][%d] = %hd\n", i, j, nums[i][j]);
    }
  }

  printf("============================\n");

  // 2차원 배열 nums에서 포인터를 1 증가시켜 보자.
  printf("nums = %p\n", nums);
  printf("nums+1 = %p\n", nums+1);  // 2차원 배열에서 포인터를 1증가시키면 1행을 증가한것과 같은 결과임을 알 수 있다.

  printf("============================\n");

  // 2차원 배열(포인터) nums가 가르키고 있는곳의 값을 출력해보자
  printf("*nums = %hd\n", *nums); // 이렇게하면 이상한 값이 출력되고 있다. 이렇게하면 출력되는 값은 1행의 시작 주소이다. (warning 발생!!!)
  printf("**nums = %hd\n", **nums);  // nums는 2차원 배열이고, 즉 2차원 포인터인것이다.
  printf("*(*nums) = %hd\n", *(*nums));
  
  printf("============================\n");

  for(int i=0; i<2; i++)
  {
    for(int j=0; j<3; j++)
    {
      printf("%hd, ", *(*(nums+i)+j));
    }
    printf("\n");
  }

  printf("============================\n");
  // sizeof nums는 12를 반환한다.
  // 이것은 sizeof(short) * 6칸(2행 * 3열)의 결과이다.
  printf("sizeof(nums) = %lu\n", sizeof(nums));
  for(int i=0; i<6; i++)
  {
    printf("%hd,", *((*nums)+i));
  }
    
  return 0;
}