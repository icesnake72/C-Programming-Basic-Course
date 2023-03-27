#include "GameUtil.h"


// 숫자 야구 게임입니다.
// 컴퓨터가 3자리의 숫자를 임의로 생각하고
// 사용자가 컴퓨터가 정한 숫자를 찾아가는 게임입니다.
// 
// 숫자를 찾기위해 컴퓨터는 힌트를 제공합니다.
// 사용자가 숫자를 입력하면 컴퓨터는 입력된 숫자를 판단해서
// 자리수와 숫자가 일치하면 strike, 숫자만 일치하고 자리수가 틀렸을 경우에는 ball로 알려줍니다.
//
// 일치하는게 숫자가 없으면 out입니다
// 예를들어 3자리의 숫자중 1개의 수가 자리수와 숫자가 일치하고 1개의 수는 숫자만 맞췄을 경우 1스트라이크 1볼이라고 알려줍니다.
// 3자리 모두 맞추면 성공이며 게임을 종료합니다.
// 


// 327
/*
* 123	// 1s 1b
* 124	// 1s  ---> 1또는 2가 맞으며, 3은 확실한데 자리가 틀리고, 4는 아님 확정
* 145	// out ---> 1,4,5 다 아님
* 323	// 2s
* 326	// 2S
* 327	// BINGO!!! CONGRATULATIONS!!! You have done at 6th time.
*/


int main()
{
	Randomize();

	// 규칙 : 겹치면 안됨
	// 컴퓨터가 지정하는 랜덤한 숫자, 3자리
	byte goal[GOAL_COUNT] = { 0 };
	byte user[GOAL_COUNT] = { 0 };

	int ch = 0;
	do
	{
		// ...
		memset(goal, 0, sizeof(byte) * GOAL_COUNT);

		// 컴퓨터가 랜덤한 숫자 3자리를 초기화
		initValues(goal, GOAL_COUNT, 9);

		//
#ifdef _DEBUG
		for (byte i = 0; i < GOAL_COUNT; i++)
			printf("%d", goal[i]);

		printf("\n");
#endif


		do
		{
			UINT result = inputFromUser(user, GOAL_COUNT);
			printf("%d\n", result);
			if (!result)
			{
				printf("bye!!!");
				return 0;
			}

			// 
			// goal배열과 user배열을 비교해서
			// 판단한 값을 반환한다.
			result = CheckThisOut(goal, GOAL_COUNT, user, GOAL_COUNT);
			if (result)
			{
				printf("Bingo!!! 정답입니다\n");
				break;
			}

		} while (1);

		printf("게임을 계속하시겠습니까?(y or n)");
		int ch = _getch();
		if (ch == 'n' || ch == 'N')
			return 0;

	} while (1);	// 무한 루프

	return 0;
}
