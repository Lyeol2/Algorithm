#include <iostream>
#include <vector>
// https://www.acmicpc.net/problem/1904

// a1 = 1
// a2 = 1 + 0
// a3 = 1 + 0
// a4 = 2
// a5 = 2
// a6 = a5 + a1
// a7 = a6 + a2
// a8 = a7 + a3
// a9 = a8 + a4
// a10 = a9 + a5

using namespace std;
using ll = long long;
ll dp[100] = { 0, };
// 점화식을 구하자

ll T = 0;
vector<ll> N ;

int main()
{
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		int value;
		cin >> value;
		N.push_back(value);
	}

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (size_t i = 0; i < N.size(); i++)
	{
		// dp
		for (size_t j = 6; j < N[i] + 1; j++)
		{
			dp[j] = dp[j - 1] + dp[j - 5];
		}

		cout << dp[N[i]] << endl;
	}
	return 0;
}