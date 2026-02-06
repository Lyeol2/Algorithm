#include <iostream>

// https://www.acmicpc.net/problem/1904


using namespace std;
using ll = long long;
ll dp[10000000] = { 0, };
// 점화식을 구하자

ll N = 0;

int main()
{
	cin >> N;

	dp[0] = 1;
	dp[1] = 1;

	for (size_t i = 2; i < N + 1; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << (dp[N]) << endl;
	return 0;
}