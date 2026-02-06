#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;



// 볼록 껍질 (플레티넘 5)
// 예상 모든 점을 순회하고 순회한 점마다 한번더 순회하기때문에
// O(N^2) 의 시간이 나올것이라고 예측중

// https://www.acmicpc.net/problem/1708

using point = pair<long long, long long>;

vector<point> points;

// 정렬
bool cmp(const point& a, const point& b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}
long long Distance(point a, point b)
{
	return (pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}
point SubstractVector(point a, point b)
{
	return point(a.first - b.first, a.second - b.second);
}
long long Cross(point a, point b)
{
	long long value = (a.first * b.second) - (a.second * b.first);
	if(value > 0)
		return 1;
	if (value < 0)
		return -1;
	if (value == 0)
		return 0;

	return 0;
}



int main()
{
	// Exception
	// 모든 점이 일직선상에 존재하는 경우는 없음
	// 모든 점은 서로 겹치지 않는다



	// 일직선상에 존재하지 않으므로 무조건 결과는 3이상
	int result = 3;

	int N;
	cin >> N;


	int X, Y;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		points.push_back(point(X, Y));
	}

	// 점이 3개인 경우는 어떻게 만들어도 볼록껍질이다
	if (points.size() == 3)
	{
		cout << result << endl;
		return 0;
	}

	sort(points.begin(), points.end(), cmp);

	vector<point> convexHull;
	vector<point> convexHull2;

	for (int i = 0; i < points.size(); i++)
	{
		point c =  points[i];

		while (convexHull.size() >= 2)
		{
			// c가 오른쪽으로 꺾인다면 b를 제거해야함
			point a = convexHull[convexHull.size() - 2];
			point b = convexHull[convexHull.size() - 1];

			// vec기준으로 오른쪽인지 왼쪽인지 판별
			point vec1 = SubstractVector(b, a);
			point vec2 = SubstractVector(c, a);
			point vec3 = SubstractVector(c, a); 

			int value = Cross(vec1, vec2);
			// 오른쪽으로 꺾였으면~
			if (value > 0)
			{
				// b는 튕구고
				convexHull.pop_back();
			}
			else if(value == 0)
			{
				// 같은방향이면
				if (Distance(point(0, 0), vec1) < Distance(point(0, 0), vec3))
				{
					convexHull.pop_back();
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		// c를 넣습니다 
		convexHull.push_back(points[i]);

	}


	for (int i = points.size() - 1; i >= 0 ; i--)
	{
		point c = points[i];

		while (convexHull2.size() >= 2)
		{
			// c가 오른쪽으로 꺾인다면 b를 제거해야함
			point a = convexHull2[convexHull2.size() - 2];
			point b = convexHull2[convexHull2.size() - 1];

			// vec기준으로 오른쪽인지 왼쪽인지 판별
			point vec1 = SubstractVector(b, a);
			point vec2 = SubstractVector(c, a);
			point vec3 = SubstractVector(c, a);

			int value = Cross(vec1, vec2);
			// 오른쪽으로 꺾였으면~
			if (value > 0)
			{
				// b는 튕구고
				convexHull2.pop_back();
			}
			else if (value == 0)
			{
				// 같은방향이면
				if (Distance(point(0, 0), vec1) < Distance(point(0, 0), vec3))
				{
					convexHull2.pop_back();
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		// c를 넣습니다 
		convexHull2.push_back(points[i]);

	}



	cout << convexHull.size() + convexHull2.size() - 2 << endl;


	return 0;
}