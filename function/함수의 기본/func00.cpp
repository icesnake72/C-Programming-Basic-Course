/*
func00.cpp

함수의 오버로딩 기능을 설명하기 위해 cpp파일로 제작합니다.
함수의 오버로딩은 c에서는 지원되지 않습니다.

함수의 정의와 호출에 대해 알아봅니다.
함수의 파라미터와 반환값에 대해 알아봅니다.
헤더 파일의 사용법에 대해 알아봅니다.
함수의 반환값, 함수명, 함수의 파라미터들에 대해 알아봅니다.
기본값이 주어지는 파라미터를 갖는 함수에 대해 알아보고 활용해봅니다.
*/

#include <stdio.h>
// #include "myheader.h"

// 반환값과 파라미터가 모두 없는 함수
void printHello(void)
{
  printf("Hello\n");
}

// 반환값은 있고 파라미터가 없는 함수
short getTen()
{
  short n = 10;
  return n;
}

// 반환값은 없고 파라미터가 있는 함수
void printShort(short n)
{
  printf("%d\n", n);
}

// 반환값과 파라미터가 있는 함수
int add(int n1, int n2)
{
  return n1 + n2;
}

/*
함수의 선언
함수의 반환값(Return Value)은 단 한개만 가능하다.
함수의 파라미터는 여러개가 있을 수 있다. 

type of function function_name(data type n1, data type n2, ...)

함수의 활용은 함수의 정의(선언+구현)와 함수의 호출로 이루어진다.
함수의 정의는 해당 함수의 호출보다 항상 먼저 되어야 한다.
*/

void printMultiTable(short n)
{
  printf("%d 단\n", n);
  for(short i=1; i<=9; i++)
    printf("%d x %d = %d\n", n, i, i*n);
}

double getAreaOfCircle(int r)
{
  return 3.14 * (r * r);
}

char uppercase(char ch)
{
  if (ch < 'a' || ch > 'z')
    return 0; // 이럴때는 에러를 반환한다. 0이라서 에러가 아니라 에러코드를 알아서 정하는 것임.

  return ch - 32;
}

double divide(double div, double fact)
{
  double res = div / fact;
  res *= 1000.;  

  int nRes = (int)res;
  int nam = nRes % 10;
  nRes = nRes / 10 * 10;
  
  res = nRes / 1000.;
  if ( nam > 4 )
    res += 0.01;
  
  return res;
}


double divide(double div, double fact, int place)
{
  double weight = 1;
  for(int i=0; i<=place; i++)
    weight *= 10;

  double res = div / fact;
  res *= weight;  

  int nRes = (int)res;
  int nam = nRes % 10;
  nRes = nRes / 10 * 10;
  
  res = nRes / weight;

  weight = 1;
  for(int i=0; i<place; i++)
    weight *= 0.1;
  if ( nam > 4 )
    res += weight;
  
  return res;
}

double divideEx(double div, double fact, int place=2)
{
  return divide(div, fact, place);
}


int main() 
{
  printHello();
  printf("%d\n", getTen());
  printShort(5);
  printf("%d\n", add(5,3));

  // 단수를 (파라미터)입력하면 해당 단수의 구구단을 출력하는 함수를 만드시요.
  printMultiTable(3);
  printMultiTable(6);

  // 반지름을 매개변수로 입력하면 원의 넓이를 구해주는 함수를 만드시요.
  double aoc = getAreaOfCircle(3);
  printf("%.3f\n", aoc);

  aoc = getAreaOfCircle(4);
  printf("%.3f\n", aoc);

  aoc = getAreaOfCircle(5);
  printf("%.3f\n", aoc);

  // 소문자를 매개변수로 입력하면 대문자로 변환해주는 함수를 만드시요.
  char ch = uppercase('a');
  if ( ch ) printf("%c\n", ch);

  ch = uppercase('z');
  if ( ch ) printf("%c\n", ch);

  ch = uppercase('k');
  if ( ch ) printf("%c\n", ch);

  ch = uppercase('!');
  if ( ch ) printf("%c\n", ch);

  ch = uppercase('n');
  if ( ch ) printf("%c\n", ch);

  ch = uppercase('.');
  if ( ch ) 
    printf("%c\n", ch);
  else
    printf("소문자 a~z 까지를 입력해주세요\n");

  // 제곱미터를 입력하면 평을 구해주는 함수를 만드세요 (1m^2 == 0.3025평)

  // 마일(Mile)을 입력하면 킬로미터(Km)을 구하는 함수를 만드세요 (1mile == 1.609344 Km)

  // 재수와 피재수를 입력하여 나눗셈의 몫을 구하는 함수를 만드세요, 
  // 단 나눗셈의 결과는 소수이며 소숫점 이하 3자리에서 반올림하여 
  // 소숫점 2자리까지 표현하는 결과를 반환하도록 해주세요.
  printf("divide함수 호출\n");
  printf("%f\n", divide(5,3));
  printf("%f\n", divide(5,2));
  printf("%f\n", divide(909238.747,2855564.488386));
  printf("\n");

  printf("divide함수 호출, 소숫점 2자리까지표현, 소수점 3번째자리에서 반올림\n");
  printf("%f\n", divide(5,3,2));
  printf("%f\n", divide(5,2,2));
  printf("%f\n", divide(909238.747,2855564.488386,2));
  printf("\n");

  printf("divide함수 호출, 소숫점 3자리까지표현, 소수점 4번째자리에서 반올림\n");
  printf("%f\n", divide(5,3,3));
  printf("%f\n", divide(5,2,3));
  printf("%f\n", divide(909238.747,2855564.488386,3));
  printf("\n");

  printf("divide함수 호출, 소숫점 5자리까지표현, 소수점 6번째자리에서 반올림\n");
  printf("%f\n", divide(7,3,5));
  printf("%f\n", divide(7,2,5));
  printf("%f\n", divide(909238.747,2855564.488386,5));
  printf("\n");

  printf("Default 파라미터를 이용한 divideEx함수 호출, 소숫점 2자리까지표현, 소수점 3번째자리에서 반올림\n");
  printf("%f\n", divideEx(7,3));
  printf("%f\n", divideEx(7,2));
  printf("%f\n", divideEx(909238.747,2855564.488386));
  printf("\n");

  return 0;
}