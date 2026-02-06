//https://www.acmicpc.net/problem/1149
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>>

using namespace std;
using ll = long long;

ll dpR[1001] = { 0, };
ll dpG[1001] = { 0, };
ll dpB[1001] = { 0, };
ll dp[1001] = { 0, };

// 점화식을 구하자

ll N = 0;
std::vector<ll> R;
std::vector<ll> G;
std::vector<ll> B;

int main()
{
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		int inputA, inputB, inputC;
		cin >> inputA >> inputB >> inputC;
		R.push_back(inputA);
		G.push_back(inputB);
		B.push_back(inputC);
	}

	// 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
	// N번 집의 색은 N - 1번 집의 색과 같지 않아야 한다.
	// i(2 ≤ i ≤ N - 1)번 집의 색은 i - 1번, i + 1번 집의 색과 같지 않아야 한다.


	// 1번집과 2번집은 색이 다름
	// N번집은 N - 1 번집과 색이 다름
	// 2번집보다 크고 마지막집보다 작은집은 i - 1번 i+번집과 색이 같지 않아야함
	// -> 연속된 색상의 집은 없음.
	dpR[0] = R[0];
	dpG[0] = G[0];
	dpB[0] = B[0];

	for (size_t i = 1; i < N; i++)
	{
		// dpN은 마지막 색깔이 N으로 끝나는 최소값
		
		// dpR[i] 는 이전 색깔이 dpB[i - 1] dpG[i - 1] 의 삼항 연산으로 만들어진다
		dpR[i] = R[i] + ((dpB[i - 1] < dpG[i - 1]) ? dpB[i - 1] : dpG[i - 1]);
		dpG[i] = G[i] + ((dpR[i - 1] < dpB[i - 1]) ? dpR[i - 1] : dpB[i - 1]);
		dpB[i] = B[i] + ((dpR[i - 1] < dpG[i - 1]) ? dpR[i - 1] : dpG[i - 1]);
	}
	
	ll result = min(dpR[N - 1], dpG[N - 1]);
	result = min(result, dpB[N - 1]);
	cout << result << endl;

	return 0;
}