// https://www.acmicpc.net/problem/1463
// 쉬운 계단 수  실버1


// 계단수는 끝에 위로 한칸올라가거나 아래로 한칸 내려가는 수가 붙는다고 생각하자.
// 0으로 시작하는 수는 계단수가 아니란다. 1, 2, 3, 4,5,6,7,8,9
//										1에선 0으로 내려갈 수 있음. 그럼 음수도 된다는거임? ㅇㅋ.
//										21 32 43 54 65 76 87 98  12 23 34 45 56 67 78 89 10
// 시작수는 1~9까지
// 아 음수는안됨. "수" 니까 4-1234 이런건 수가 될수없음
// 



#include <iostream>
#include <vector>




using namespace std;
using ll = long long;
ll dp[10][101] = { 0, };
ll N = 0;

int main()
{
	cin >> N;

	for (size_t i = 1; i < 10; i++)
	{
		dp[i][0] = 1;
	}

	// 0으로 시작하는 계단식은 어차피 0임으로 더해도 0임
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			// 끝자리가 9인녀석은 8에 +1
			// 끝자리가 0인녀석은 1에 +1
			if(j == 9)
				dp[j - 1][i + 1] += dp[j][i] % 1000000000;
			else if(j == 0)
				dp[j + 1][i + 1] += dp[j][i] % 1000000000;
			else
			{
				dp[j - 1][i + 1] += dp[j][i] % 1000000000;
				dp[j + 1][i + 1] += dp[j][i] % 1000000000;
			}

		}
	}
	int sum = 0;
	for (size_t i = 0; i < 10; i++)
	{
		sum += dp[i][N - 1] % 1000000000;
		sum %= 1000000000;
	}

	cout << sum << endl;

	return 0;
}