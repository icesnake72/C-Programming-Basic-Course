/*
func01.c
coded by k.e.b

함수를 이용하지 않고 로또 시뮬레이터를 코딩해봅니다.
그리고 함수를 만들어 버전을 개선시킵니다.
포인터 변수를 갖는 파라미터에 대해 알아봅니다.
Call by Value 와 Call by Reference에 대해 알아봅니다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_COUNT 6
#define MAX_LOTTO_VALUE 45

typedef unsigned char byte;

// 로또 시뮬레이터

// 미션 :
// 로또 당첨번호 6개를 랜덤으로 생성한다.
// 로또 당첨번호 6개를 오름차순 정렬하여 출력한다.
//
// 구매자 시뮬레이션을 위해 5행 6열 2차원 배열에 랜덤 로또 번호를 생성하여 저장한다.
// 구매자 로또번호와 당첨번호를 맞춰보고
// 6개가 모두 맞으면 1등
// 5개가 맞으면 2등
// 4개가 맞으면 3등
// 3개가 맞으면 4등 을 해당 라인 옆에 출력한다.
// 3개 미만으로 맞으면 꽝 과 맞은 갯수를 출력한다

/*
로또 당첨 번호
=========================
10, 11, 15, 16, 29, 32,
=========================
구매자 로또 번호
=========================
10, 11, 15, 16, 29, 32, <=== 1등
10, 11, 15, 20, 27, 30, <=== 4등
 1,  3, 14, 20, 27, 30, <=== 꽝(0)
 7, 23, 30, 32, 38, 45, <=== 꽝(1)
15, 19, 31, 32, 42, 44, <=== 꽝(1)
*/


void initLotto(byte *arr, int nSize);
void sortArray(byte *arr, int nSize);
void swap(byte *a, byte *b);

byte findInArray(byte *arr, int nSize, byte toFind);

int main()
{
  srand((unsigned int)time(NULL));

  // 1부터 45까지의 랜덤한 값을 생성하여, arrWins에 저장한다.
  byte arrWins[LOTTO_COUNT] = {0}; // 배열을 0으로 초기화한다.
  initLotto(arrWins, LOTTO_COUNT);
  
  // 가장 기본적인 Sequential Sort Algorithm을 이용해 Ascending Sort를 한다.
  sortArray(arrWins, LOTTO_COUNT);

  // 시뮬레이션을 위해 구매자 로또 번호를 자동으로 생성한다.
  byte arrLotto[5][LOTTO_COUNT] = {0};

  for (byte k = 0; k < 5; k++)
    initLotto(arrLotto[k], LOTTO_COUNT);

  // sort
  for (byte k = 0; k < 5; k++)
    sortArray(arrLotto[k], LOTTO_COUNT);
    
  printf("로또 당첨 번호\n");
  printf("=========================\n");
  for (byte i = 0; i < LOTTO_COUNT; i++)
    printf("%2d, ", arrWins[i]);

  // 구매자 로또 번호와 당첨번호를 맞춰본다
  // 여기에서 각 라인에 몇개가 맞았는지 여부를 체크하고 출력한다.
  // byte 타입의 변수 count를 0으로 초기화
  byte count = 0;
  byte existValue = 0;
  const char *strInfo = NULL;

  // "구매자 로또 번호" 출력
  printf("\n=========================\n");  
  printf("구매자 로또 번호\n");  
  printf("=========================\n");
  // 5번 반복하는 for 루프
  for (byte i = 0; i < 5; i++)
  {    
    // LOTTO_COUNT(6)번 반복하는 for 루프
    for (byte j = 0; j < LOTTO_COUNT; j++)
    {
      // arrLotto[i][j] 출력
      printf("%2d, ", arrLotto[i][j]);
      existValue = 0;
      existValue = findInArray(arrWins, LOTTO_COUNT, arrLotto[i][j]);
      if ( existValue )
      {
        // count를 1 증가시키고 for 루프 탈출
        count++;
        break;
      }      
    }

    // count에 따라 strInfo에 문자열 할당
    switch (count)
    {
    case 0:
    case 1:
    case 2:
      strInfo = "꽝";
      break;
    case 3:
      strInfo = "4등";
      break;
    case 4:
      strInfo = "3등";
      break;
    case 5:
      strInfo = "2등";
      break;
    case 6:
      strInfo = "1등";
    }

    printf(" <=== %s", strInfo);
    if (count < 3)
      printf("(%d)", count);

    printf("\n");
    count = 0;
  }
  return 0;
}


void initLotto(byte *arr, int nSize)
{
  byte i = 0;
  byte tmp = 0;
  byte existValue = 0;
  while (i < LOTTO_COUNT)
  {
    tmp = rand() % MAX_LOTTO_VALUE + 1;
    existValue = findInArray(arr, (int)i, tmp);
    
    // 플래그 변수: existValue의 값이 0이면 배열에 현재 생성한 랜덤값이 존재하지 않으므로
    // 배열에 현재 생성한 랜덤값을 저장한다.
    if (!existValue)
    {
      arr[i] = tmp;
      ++i;
    }
    // 다시 플래그 변수를 0으로 초기화한다.
    existValue = 0;
  }
}

void sortArray(byte *arr, int nSize)
{  
  // 가장 기본적인 Sequential Sort Algorithm을 이용해 Ascending Sort를 한다.
  for (byte i = 0; i < LOTTO_COUNT - 1; i++)
  {
    for (byte j = i + 1; j < LOTTO_COUNT; j++)
    {
      if (arr[i] > arr[j])
        swap(&arr[j], &arr[i]);            
    }
  }
}

void swap(byte *a, byte *b)
{
  byte tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

byte findInArray(byte *arr, int nSize, byte toFind)
{
  for(byte i=0; i<nSize; i++)
  {
    if ( arr[i] == toFind )
      return 1;
  }

  return 0;
}