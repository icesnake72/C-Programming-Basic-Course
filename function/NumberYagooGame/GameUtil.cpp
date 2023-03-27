#include "GameUtil.h"


void Randomize()
{
    srand((UINT)time(NULL));
}


// arr(배열)안에 toFind가 있는지 검색하는 함수
// toFind가 arr(배열)안에 같은 값이 있으면 1을 반환
// 같은 값이 없으면 0을 반환!!!
byte findInArray(byte* arr, int nSize, byte toFind)
{
    for (int i = 0; i < nSize; i++)
    {
        if (arr[i] == toFind)
            return 1;
    }

    return 0;
}


// 1차원 배열만 처리가 가능하도록 만들어짐
void initValues(byte* arr, int nSize, byte n)
{
    byte i = 0;
    while (i < nSize)
    {
        int rnd = (rand() % n) + 1;
        if (findInArray(arr, nSize, rnd))
            continue;

        arr[i++] = rnd;
    }
}

UINT inputFromUser(byte* arr, int nSize)
{
    printf("숫자를 입력하세요\n");

    byte i = 0;
    int res = 0;
    do
    {
        printf("%d번째 숫자를 입력하세요 ===> ", i + 1);
        res = _getch();
        if (isdigit(res))
        {
            res = res - '0'; //
            arr[i] = res;
            ++i;
            printf("%d\n", res);
            if (i >= GOAL_COUNT)
                break;
        }
        else
        {
            if (res == 'x' || res == 'X')
                return 0;

            printf("숫자를 입력해주세요\n");
        }

    } while (1);

    return arrayToDigit(arr);
}

// 배열안에 있는 값을 양의 정수로 변환하는 함수
UINT arrayToDigit(byte* arr)
{
    // arr의 갯수가 3개인걸 확실하게 안다고 가정했을때!!!
    return arr[0] * 100 + arr[1] * 10 + arr[2];
}



UINT CheckThisOut(byte* arrGoal, int nSize, byte* arrUser, int nSize2)
{
    UINT s = 0;
    UINT b = 0;

    for (byte i = 0; i < nSize; i++)
    {
        for (byte j = 0; j < nSize2; j++)
        {
            if (arrGoal[i] == arrUser[j])
            {
                if (i == j)
                    s++;
                else
                    b++;
            }
        }
    }

    // 스트라이크의 갯수가 3이면 모두 맞혔으므로 게임을 끝낸다!!!
    if (s == GOAL_COUNT)
        return 1;

    printf("%d 스트라이크, %d 볼입니다\n", s, b);

    // 어쨋든 아직 더 맞춰봐야 한다... 아직 못 맞힘
    return 0;
}
