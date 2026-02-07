//https://www.acmicpc.net/problem/11053
// 가장 긴 증가하는 부분 수열

// 일단 백트레킹을 하자 헷갈린다

#include <iostream>
using namespace std;

int N = 0;
int arr[1000] = { 0, };

// 시작 수열의 인덱스 / 길이

int dp[1000] = { 0, };


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		int max = 1;
		for (int j = i; j >= 0; --j)
		{
			if (arr[j] < arr[i])
			{
				if (max < dp[j] + 1)
				{
					max = dp[j] + 1;
				}
			}
		}
		dp[i] = max;
	}

	int result = 0;

	for (size_t i = 0; i < N; i++)
	{
		result = max(dp[i], result);
	}

	cout << result << endl;

	return 0;
}