/*
ptrEx02.c
coded by k.e.b

연도와 달을 입력하면 해당 달의 달력을 출력하는 예제입니다.
윤년의 계산과 달력의 시작일자는 1년 1월 1일이 월요일이었음이 중요한 정보입니다.

추가적으로 전처리문에 대해 알아봅니다.
추가적으로 printf()에서 formatted string에 대해 알아봅니다.
*/

#include <stdio.h>

#define isYunnyun(x)    ((x%4==0 && x%100!=0) || x%400==0)
#define DAYS_OF_YEAR    365
#define DAYS_OF_YUNDAL  29
#define DAYS_OF_WEEK    7
#define MAX_CAL_ROW     6

int main() 
{
  int year = 0;
  int month = 0;

  printf("출력 연도 : ");
  scanf("%d", &year);
  // printf("\n");

  printf("출력할 달 : ");
  scanf("%d", &month);

  int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

  //
  // 1년 1월 1일은 월요일, 1년 1월 7일은 일요일
  // 따라서, 7로 나누어 나머지가 0이면 일요일이고, 나머지가 1부터 월요일 ~ 나머지가 6은 토요일
  // 

  // 총 날짜 계산
  int days = 0; 
  for(int i=1; i<=year-1; i++) {
    days += isYunnyun(i) ? DAYS_OF_YEAR+1 : DAYS_OF_YEAR; // 윤년이면 366, 일반년도이면 365씩 누적
  }
 
  if isYunnyun(year)
    day[1] = DAYS_OF_YUNDAL;   
  
  for(int i=0; i<month-1; i++) {
    days += day[i];
  }

  // 달력은 맥시멈 6행, 7열 
  // 0행이 일요일임, 
  int start_dow = days%DAYS_OF_WEEK + 1;     // 전달 마지막 요일 + 1 요일에서 시작
  int end_day = day[month-1];     // 그달의 마지막 일자를 배열에서 구함
  int dom = 1;                    // 1로 그달의 표시할 날짜 초기화
  int arrCalendar[MAX_CAL_ROW][DAYS_OF_WEEK] = {0};    // 달력을 표시할 2차원 배열
  for(int i=0; i<MAX_CAL_ROW; i++){
    for(int j=start_dow; j<DAYS_OF_WEEK; j++) {
      if ( dom > end_day ) break; // 표시할 날짜가 마지막 날짜보다 커졌으면 루프 탈출
      arrCalendar[i][j] = dom++;  // 달력 행열(2차원 배열)에 날짜 추가      
    }
    start_dow = 0;  // 한주가 끝났으면 다음주의 시작일자는 0부터 다시...
  }

  printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");
  printf("====================================================\n");
  // 2차원 배열을 다시 돌면서 2차원 배열에 저장된 내용을 그대로 출력해줌
  // 단 0이 저장된 공간에는 0을 출력하지 않음
  for(int i=0; i<MAX_CAL_ROW; i++){
    for(int j=start_dow; j<DAYS_OF_WEEK; j++) {
      if ( arrCalendar[i][j]==0 )   
        printf("\t");                       // 0이 저장된 공간에는 출력하지 않고 다음칸으로 넘어감
      else  
        printf("%3d\t", arrCalendar[i][j]); // 3칸의 자리를 확보하고, 오른쪽 정렬하여 출력함
    }
    printf("\n");
  }
  
  return 0;
}