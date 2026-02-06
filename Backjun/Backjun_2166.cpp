//https://www.acmicpc.net/problem/2166

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;



using point = pair<long long , long long >;
vector<point> points;

point AddVector(point a, point b)
{
	return point(a.first + b.first, a.second + b.second);
}
point SubstractVector(point a, point b)
{
	return point(a.first - b.first, a.second - b.second);
}
long double DotProduct(point a, point b)
{
	return (a.first * b.first) + (a.second * b.second);
}
long double Distance(point a, point b)
{
	return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}
long double GetCosWithTwoVector(point a, point b)
{
	long double dotValue = DotProduct(a, b)
		/ ((Distance(point(0, 0), a) * Distance(point(0, 0), b)));

	return dotValue;
}

int main()
{
	int N = 0;
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		long long  a, b = 0;
		cin >> a >> b;
		points.push_back(point(a, b));
	}

	point center = points[0];
	

	long double result = 0;

	for (size_t i = 1; i < N - 1; i++)
	{
		auto aVec = SubstractVector(points[i], center);
		auto bVec = SubstractVector(points[i + 1], center);
		long double sin = sqrt(1 - pow(GetCosWithTwoVector(aVec, bVec),2));

		result += Distance(aVec, point(0, 0))* Distance(bVec, point(0, 0)) * sin / 2.0;
		//cout << center.first << ", " << center.second << endl;
		//cout << aVec.first << ", " << aVec.second << endl;
		//cout << bVec.first << ", " << bVec.second << endl;
		//cout << sin << endl;
	}




	cout << fixed;
	cout.precision(1);
	cout << abs(result) << endl;

	return 0;
}