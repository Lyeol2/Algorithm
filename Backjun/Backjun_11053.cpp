//https://www.acmicpc.net/problem/11053
// 가장 긴 증가하는 부분 수열
#include <iostream>
using namespace std;

int N = 0;
int arr[1000] = { 0, };

// 시작 수열의 인덱스 / 길이
// 
int dpCount[1000];
int dpChained[1000];
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dpCount[0] = 1;
	// 시작수열보다 무조건 뒷수열이 길이가 길다
	for (int i = 0; i < N; i++)
	{

		// 뒷수열 이 더 큰 숫자라면
		if(arr[i] < arr[i + 1])
		{
			dpChained[i + 1] = dpChained[i];
			dpCount[i + 1] = dpCount[i] + 1;
		}
		else
		{
			dpCount[i + 1] = 1;
		}
	}


	return 0;
}