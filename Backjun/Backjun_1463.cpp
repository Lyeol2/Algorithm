// https://www.acmicpc.net/problem/1463
// 1로 만들기  실버3

// X가 3으로 나누어 떨어지면, 3으로 나눈다
// X가 2로 나누어 떨어지면, 2로 나눈다.
// 1을 뺀다.
// 연산을 사용하는 횟수의 최솟값

// 정수 N을 만들때 
// 나누어 떨어지지 않으면 무조건 1을 빼야함
// 나누어 떨어진다면 2보단 3으로 나누는게 조금더 많이 나눌수 있음
// ㄴ 틀린 추론 EX ) 1을 빼서 3으로 나누는게 효율적인 경우도 존재함
// 그렇다면 3가지로 계산효율을 나눌수있음 메모리 넉넉하니 함해봅시다
// 바텀업 방식으로 N을 만드는과정이 조금더 DP를 쓰기 유리할듯


#include <iostream>
#include <vector>




using namespace std;
using ll = long long;
ll dp[1000001] = { 0, };
ll N = 0;

int main()
{
	cin >> N;

	int number = 1;
	int counter = 0;

	// 넘버가 N이 될때까지 반복
	// 1을 N - 1 번 더하면 DP의 마지막에 도달
	// 최대 반복횟수는 N-1이다
	// 1 일땐 안더해도 되니 1이다
	// 2 일땐 1 + 1로 1이다
	// 3 일땐 1 * 3으로 1이다
	// 4일땐 1 * 2 * 2 로 1이다
	dp[0] = 0;
	dp[1] = 0;


	for (size_t i = 1; i < N; i++)
	{
		if (dp[i + 1] == 0)
			dp[i + 1] = dp[i] + 1;
		else if (dp[i + 1] > dp[i] + 1)
			dp[i + 1] = dp[i] + 1;

		if (i * 2 <= N)
		{
			if(dp[i*2] == 0)
				dp[i * 2] = dp[i] + 1;
			else if (dp[i * 2] > dp[i] + 1)
				dp[i * 2] = dp[i] + 1;
		}

		if (i * 3 <= N)
		{
			if(dp[i * 3] == 0)
				dp[i * 3] = dp[i] + 1;
			else if (dp[i * 3] > dp[i] + 1)
				dp[i * 3] = dp[i] + 1;
		}
	}


	cout << dp[N] << endl;

	return 0;
}