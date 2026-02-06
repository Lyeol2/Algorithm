#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using point = pair<long long, long long>;

point SubstractVector(point a, point b)
{
	return point(a.first - b.first, a.second - b.second);
}
int Cross(point a, point b)
{
	long long value = (a.first * b.second) - (a.second * b.first);
	if (value > 0)
		return 1;
	if (value < 0)
		return -1;
	if (value == 0)
		return 0;

	return 0;
}

int main()
{

	point a, b, c;

	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;

	cout << Cross(SubstractVector(b, a), SubstractVector(c, a)) << endl;

	return 0;
}