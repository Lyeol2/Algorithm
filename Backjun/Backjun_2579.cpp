//https://www.acmicpc.net/problem/2579
// 난이도 실버3
// 체감난이도 실버1~골드3



#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

ll dp[3][301] = { 0, };

vector<ll> stair;
ll N = 0;

int main()
{
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		stair.push_back(input);
	}


	dp[0][0] = stair[0];
	dp[1][1] = stair[0] + stair[1];
	dp[0][1] = stair[1];
	
	if (N == 1)
	{
		cout << stair[0] << endl;
		return 0;
	}

	for (size_t i = 0; i < N; i++)
	{
		// 1칸 또는 두칸 뛰는 경우 경우
		for (size_t j = 0; j < 1; j++)
		{
			if (i + 1 > N - 1) continue;
			// 1칸 뜀
			if (dp[j][i] + stair[i + 1] > dp[j + 1][i + 1])
			{
				dp[j + 1][i + 1] = dp[j][i] + stair[i + 1];
			}

			if (i + 2 > N - 1) continue;
			// 2칸 뜀
			if (dp[j][i] + stair[i + 2] > dp[0][i + 2])
			{
				dp[0][i + 2] = dp[j][i] + stair[i + 2];
			}
		}	

		if (i + 2 > N - 1) continue;
		// 무조건 두칸 뛰는 경우
		if (dp[1][i] + stair[i + 2] > dp[0][i + 2])
		{
			dp[0][i + 2] = dp[1][i] + stair[i + 2];
		}
	}

	//for (size_t i = 0; i < N; i++)
	//{
	//	cout << dp[0][i] << ", " << dp[1][i] << ", " << dp[2][i] << endl;
	//}


	ll result = max(max(dp[0][N - 1], dp[1][N - 1]), dp[2][N - 1]);
	cout << result << endl;

	return 0;
}