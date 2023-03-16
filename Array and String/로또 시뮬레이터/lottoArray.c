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

#define LOTTO_COUNT       6
#define MAX_LOTTO_VALUE   45

typedef unsigned char     byte;


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




int main() 
{
  srand((unsigned int)time(NULL));

  // int n = rand();       // 랜덤값을 생성해주는 함수, 반드시 srand()를 이용하여 초기화해주어야 한다.
  // printf("n=%d\n", n);

  // 1부터 45까지의 랜덤한 값을 생성하여, arrWins에 저장한다.
  byte arrWins[LOTTO_COUNT] ={0};  // 배열을 0으로 초기화한다.  
  byte i = 0;
  byte tmp = 0;
  byte existValue = 0;
  while(i < LOTTO_COUNT)
  {
    tmp = rand() % MAX_LOTTO_VALUE + 1;    
    for(byte j=0; j<i; j++)
    {
      // 이미 배열안에 같은 값이 존재한다면 입력하면 안된다.
      if ( arrWins[j]==tmp )
      {
        existValue = 1;   // 지금 생성한 랜덤값이 배열에 존재한다고 플래그 변수에 체크한다.
        break;
      }        
    }

    // 플래그 변수: existValue의 값이 0이면 배열에 현재 생성한 랜덤값이 존재하지 않으므로
    // 배열에 현재 생성한 랜덤값을 저장한다.
    if ( !existValue )
    {
      arrWins[i] = tmp;
      ++i;
    }
    // 다시 플래그 변수를 0으로 초기화한다.
    existValue = 0;
  }

  // 가장 기본적인 Sequential Sort Algorithm을 이용해 Ascending Sort를 한다.  
  for(byte i=0; i<LOTTO_COUNT-1; i++)
  {
    for(byte j=i+1; j<LOTTO_COUNT; j++)
    {
      if ( arrWins[i] > arrWins[j] )
      {
        tmp = arrWins[j];
        arrWins[j] = arrWins[i];
        arrWins[i] = tmp;
      }
    }    
  }

  printf("로또 당첨 번호\n");
  printf("=========================\n");  
  for(byte i=0; i<LOTTO_COUNT; i++)
    printf("%2d, ", arrWins[i]);

  printf("\n=========================\n");  

  // 시뮬레이션을 위해 구매자 로또 번호를 자동으로 생성한다.  
  byte arrLotto[5][LOTTO_COUNT] = {0};
  for(byte k=0; k<5; k++)
  {
    existValue = 0;
    i = 0;
    while(i < LOTTO_COUNT)
    {
      tmp = rand() % MAX_LOTTO_VALUE + 1;    
      for(byte j=0; j<i; j++)
      {
        // 이미 배열안에 같은 값이 존재한다면 입력하면 안된다.
        if ( arrLotto[k][j]==tmp )
        {
          existValue = 1;   // 지금 생성한 랜덤값이 배열에 존재한다고 플래그 변수에 체크한다.
          break;
        }        
      }

      // 플래그 변수: existValue의 값이 0이면 배열에 현재 생성한 랜덤값이 존재하지 않으므로
      // 배열에 현재 생성한 랜덤값을 저장한다.
      if ( !existValue )
      {
        arrLotto[k][i] = tmp;
        ++i;
      }
      // 다시 플래그 변수를 0으로 초기화한다.
      existValue = 0;
    }
  }

  // sort
  for(byte k=0; k<5; k++)
  {
    for(byte i=0; i<LOTTO_COUNT-1; i++)
    {
      for(byte j=i+1; j<LOTTO_COUNT; j++)
      {
        if ( arrLotto[k][i] > arrLotto[k][j] )
        {
          tmp = arrLotto[k][j];
          arrLotto[k][j] = arrLotto[k][i];
          arrLotto[k][i] = tmp;
        }
      }    
    }
  }

  // 구매자 로또 번호와 당첨번호를 맞춰본다
  // 여기에서 각 라인에 몇개가 맞았는지 여부를 체크하고 출력한다.
  byte count = 0;
  const char *strInfo = NULL;
  printf("구매자 로또 번호\n");
  printf("=========================\n");  
  for(byte i=0; i<5; i++)
  {
    for(byte j=0; j<LOTTO_COUNT; j++)
    {
      printf("%2d, ", arrLotto[i][j]);
      for(byte k=0; k<6; k++)
      {
        if (arrLotto[i][j]==arrWins[k])
        {
          count++;
          break;
        }          
      }      
    }

    switch(count)
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
    if ( count < 3)
      printf("(%d)", count);
    
    printf("\n");
    count = 0;
  }
  
  

    
  return 0;
}