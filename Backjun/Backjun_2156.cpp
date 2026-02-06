// https://www.acmicpc.net/problem/2156
// 포도주 시식 - 실버 1
// 연속 3잔은 ㅁ마실수없고
// 마신후엔 모두 마셔야한다
// 661166

// 포도주 10000개
// 포도주의 양 1000 이하
// 나올수있는 가장큰 값은 10000000
// int 자료형정도면 충분할듯


#include <iostream> 
#include <cmath>
using namespace std;
int n = 0; int arr[10000]; int dp[2][10000] = { 0, }; int x = 0;
int main()
{
	std::cin >> n;

	for (int i = 0; i<n; i++)
		std::cin >> arr[i];

	// 첫번째잔
	for (int i = 0; i < n; i++)
	{
		dp[0][i] = arr[i];

	}
	for (int i= 0; i< n + 1; i++)
	{
		// 0, 1는  한칸 점프를 포함함점프를 할수있음

		// 2는 2칸점프부터 가능함
		for (int j = 1; j < n - i + 1; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (k == 1 && j == 1) continue;
		
				if (j == 1)
				{
					if (dp[k + 1][i + j] < dp[k][i] + arr[i + j])
						dp[k + 1][i + j] = dp[k][i] + arr[i + j];
				}
				else if (j > 1)
				{
					if (dp[0][i + j] < dp[k][i] + arr[i + j])
						dp[0][i + j] = dp[k][i] + arr[i + j];
				}
			}
		}
	}
	//for (size_t j = 0; j < n; j++)
	//{
	//	cout << dp[0][j] << " " << dp[1][j] << " " << dp[2][j] << endl;;
	//}

	for (int i=0; i<3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			x = max(x, dp[i][n - j - 1]);
		}

	}
	std::cout << x << endl;

}