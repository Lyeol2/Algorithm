#include <iostream>
#include <vector>
#include <algorithm>
//https://www.acmicpc.net/problem/1931
using namespace std;

using Time = pair<unsigned int, unsigned int>;
vector<Time> timeTable;
vector<Time> usableTable;

bool cmp(Time a, Time b)
{
	// 빨리끝나는 순 우선
	if (a.first < b.first)
	{
		return true;
	}
	else if (a.first == b.first)
	{
		return (a.second - a.first) < (b.second - b.first);
	}
	else
	{
		return false;
	}
	return false;
	// 시간 길이가 그다음
}
int main()
{
	int N = 0;
	cin >> N ;

	for (size_t i = 0; i < N; i++)
	{
		int a, b = 0;
		cin >> a >> b;
		timeTable.push_back(Time(a, b));
	}
	
	sort(timeTable.begin(), timeTable.end(), cmp);

	//for (size_t i = 0; i < N; i++)
	//{
	//	cout << timeTable[i].first<< "," << timeTable[i].second <<  "\n";
	//
	//}

	// 가장먼저 시작할 회의
	auto firstTable = timeTable[0];
	usableTable.push_back(timeTable[0]);
	for (size_t i = 1; i < N; i++)
	{

		if (firstTable.second > timeTable[i].second)
		{
			usableTable.pop_back();
			firstTable = timeTable[i];
			usableTable.push_back(firstTable);
			continue;
		}
		else if(firstTable.second <= timeTable[i].first)
		{
			firstTable = timeTable[i];
			usableTable.push_back(firstTable);
			continue;
		}
		else
		{

		}
	}
	cout << usableTable.size() << "\n";

	return 0;
}