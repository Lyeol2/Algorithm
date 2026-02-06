#include <iostream>


// https://www.acmicpc.net/problem/11047
using namespace std;

int coin[10] = { 0, };
int main()
{
	int N, K = 0;
	cin >> N >> K;

	for (size_t i = 0; i < N; i++)
	{
		cin >> coin[i];
	}

	int sumMoney = 0;
	int result = 0;
	for (int i = N - 1; 0 <= i; --i)
	{
		while (true)
		{
			if (sumMoney + coin[i] > K)
			{
				break;
			}
			else
			{
				sumMoney += coin[i];
				result++;
			}
		}

	}
	cout << result << endl;

	return 0;
}