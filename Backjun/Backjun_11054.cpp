//https://www.acmicpc.net/problem/11054
// 가장 긴 바이토닉 부분 수열
// 증가하는 수열도 중요하지만 하강하는 수열도 중요함.
// 증가하는 수열과 하강하는 수열을 각자구해서 합치는건 어떨까?
// 어차피 바이토닉 부분수열은 "중앙" 이 존재할수밖에 없다.


#include <iostream>
using namespace std;

int N = 0;
int arr[1000] = { 0, };
int upDp[1000] = { 0, };
int downDp[1000] = { 0, };


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
				if (max < upDp[j] + 1)
				{
					max = upDp[j] + 1;
				}
			}
		}
		upDp[i] = max;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		int max = 1;
		for (int j = i; j < N; j++)
		{
			if (arr[j] < arr[i])
			{
				if (max < downDp[j] + 1)
				{
					max = downDp[j] + 1;
				}
			}
		}
		downDp[i] = max;
	}


	int result = 1;

	for (size_t i = 0; i < N - 1; i++)
	{

		result = max(upDp[i] + downDp[i] - 1, result);

		if (arr[i] != arr[i + 1])
		{

			result = max(upDp[i] + downDp[i + 1], result);
		}
	}

	cout << result << endl;

	return 0;
}