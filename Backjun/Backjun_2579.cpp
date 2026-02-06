//https://www.acmicpc.net/problem/2579

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll dp[301];
vector<ll> stair;
ll N = 0;

int Up(int idx,int score, int step)
{
	if (idx != -1)
	{
		score += stair[idx];

		
	}

	if (step < 2)
	{
		Up(idx + 2, score, 0);
	}
	else
	{
		step += 1;
		Up(idx + 1, score, step);
		Up(idx + 2, score, step);
	}
	return 0;
}

int main()
{
	cin >> N;


	for (size_t i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		stair.push_back(input);
	}

	Up(-1, 0, 0);
	ll result = dp[N];
	cout << result << endl;

	return 0;
}