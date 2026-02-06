// https://www.acmicpc.net/problem/1912
#include <vector>
#include <iostream>
#include <algorithm>>

using namespace std;
using ll = long long;
ll dp[1000000] = {0,};
ll startIdx[1000000] = {0,};
// 점화식을 구하자

ll N = 0;
std::vector<ll> numbers;

int main()
{
	cin >> N;

	int temp;
	for (size_t i = 0; i < N ; i++)
	{
		cin >> temp;
		numbers.push_back(temp);
	}

	int result = numbers[numbers.size() - 1];
	for(int i = numbers.size() - 1; i >= 0 ; --i)
	{
		dp[i] = numbers[i];

		if (i >= numbers.size()) continue; 

		// i~N까지의 연속된 수의 합의 최댓값
		if (dp[i] < numbers[i] + dp[i + 1])
		{
			dp[i] = numbers[i] + dp[i + 1];
		}

		if (result < dp[i])
		{
			result = dp[i];
		}
	}

	cout << result << endl;

	return 0;
}