/*
다음 xx 고등학교 학생들의 중간고사 과목별 점수입니다.
각 과목별 점수를 이용하여 총점과 평균을 구하고 석차를 구하십시요.
과목은 국어, 수학, 영어, 과학으로 총 4과목입니다.
데이터는 다음과 같습니다.
1 : 80, 75, 98, 63
2 : 90, 73, 85, 70
3 : 88, 65, 90, 88
4 : 100, 75, 66, 85
5 : 88, 63, 75, 80
6 : 66, 80, 94, 87
7 : 88, 63, 78, 82
8 : 78, 88, 62, 90
9 : 90, 88, 88, 70
10 : 90, 85, 75, 88

총원은 10명입니다.
소스 데이터는 10행 5열의 배열에 초기화한다.
출력 데이터는 10행 8열의 배열에 담아 출력한다.

학번은 1번부터 10번까지 순차적으로 한다.
점수는 0 ~ 100까지의 값만 갖는다.

출력 예)
학번        국어      수학      영어     과학      총점     평균     석차
1          80        75      98      63       xxx     xx     x/10
...
10         90        85      75      88       xxx     xx     x/10
*/


#include <stdio.h>

// 전처리문은 컴파일전에 실행된다.
// define 전처리문은 코드에 있는 해당 워드를 정의한 워드로 모두 대치한다.

// #define 대치될 워드   대치할 워드

#define MAX_COUNT     10
#define SOURCE_COL    5
#define DEST_COL      8
#define SUBJECT_COUNT 4
#define TOTAL         5
#define AVG           6
#define RANK          7

//
// typedef 키워드(명령어)를 데이터 형(재)정의를 할 수 있다!!!
// 구문 :
// typedef (재정의할 데이터 타입)   (사용자 정의 데이터 타입)
typedef unsigned short   ushort;
// typedef char            MY_CHAR;     // 일반적인 데이터 타입 재정의
// typedef MY_CHAR         YOUR_CHAR;   // 재정의한 데이터 타입을 다른 이름으로 재정의
// typedef unsigned char   BYTE;        // 이미 정의된 데이터 타입이라도 또 다른 이름으로 재정의 가능



int main() {

  ushort arrScore[MAX_COUNT][SOURCE_COL] = 
  { 
    {1, 80, 75, 98, 63},
    {2, 90, 73, 85, 70},
    {3, 88, 65, 90, 88},
    {4, 100, 75, 66, 85},
    {5, 88, 63, 75, 80},
    {6, 66, 80, 94, 87},
    {7, 88, 63, 78, 82},
    {8, 78, 88, 62, 90},
    {9, 90, 88, 88, 70},
    {10, 90, 85, 75, 88}
  };

  ushort arrOutputScore[MAX_COUNT][DEST_COL] = {0};

  for(ushort i=0; i<MAX_COUNT; i++)
  {
    for(ushort j=0; j<SOURCE_COL; j++)
    {
      arrOutputScore[i][j] = arrScore[i][j];
      if ( j!=0 )
        arrOutputScore[i][TOTAL] += arrOutputScore[i][j];
    }

    arrOutputScore[i][AVG] = arrOutputScore[i][TOTAL] / SUBJECT_COUNT;
    arrOutputScore[i][RANK] = 1;
  }

  for(ushort i=0; i<MAX_COUNT; i++)
  {
    for(ushort j=0; j<MAX_COUNT; j++)
    {
      if ( arrOutputScore[i][TOTAL] < arrOutputScore[j][TOTAL] )
        arrOutputScore[i][RANK] += 1;
    }
  }

  printf("=============================================================\n");
  printf("학번\t국어\t수학\t영어\t과학\t총점\t평균\t석차\n");
  printf("=============================================================\n");
  for(ushort i=0; i<MAX_COUNT; i++)
  {
    for(ushort j=0; j<DEST_COL; j++)
    {
      if ( j!=RANK )
        printf("%3d\t", arrOutputScore[i][j]);
      else
        printf("%2d/10", arrOutputScore[i][j]);    // 석차인 경우 /10 형식으로 출력!  
    }
    printf("\n");
  }

  return 0;
}