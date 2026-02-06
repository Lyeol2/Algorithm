//https://www.acmicpc.net/problem/1149
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>>

using namespace std;
using ll = long long;

// x, y
ll dp[501][501] = {0,};
vector<vector<ll>> vec;
// 점화식을 구하자

ll N = 0;


int main()
{
	cin >> N;


	for (size_t i = 0; i < N; i++)
	{
		vec.push_back(vector<ll>());
		for (size_t j = 0; j < i + 1; j++)
		{
			int input;
			cin >> input;

			vec[i].push_back(input);
		}
	}


	// 첫번째 줄의 첫번째 값은
	dp[0][0] = vec[0][0];
	for (size_t i = 1; i < N; i++)
	{
		for (size_t j = 0; j < i + 1; j++)
		{
			// 가장 오른쪽 값인 경우 그대로 내려와야함 , 왼쪽값인 경우도
			if (j == 0)
			{
				dp[i][j] = vec[i][j] + dp[i - 1][0];
				continue;
			}
			if (j == i)
			{

				dp[i][j] = vec[i][j] + dp[i - 1][j - 1];
				continue;
			}

			dp[i][j] = vec[i][j] + ((dp[i - 1][j] > dp[i - 1][j - 1]) ? dp[i - 1][j] : dp[i - 1][j - 1]);
		}

	}
	
	ll result = 0;
	for (size_t i = 0; i < N; i++)
	{
		result = max(result, dp[N - 1][i]);
	}
	cout << result << endl;

	return 0;
}