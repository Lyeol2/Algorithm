#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using point = pair<double, double>;


vector<int> selectPoints;
bool checkPoint[8] = { 0, };
vector<int> points;
const double EPS = 1e-9;
#define PI 3.14159265


point SubstractVector(point a, point b)
{
	return point(a.first - b.first, a.second - b.second);
}
int Cross(point a, point b)
{
	double value = (a.first * b.second) - (a.second * b.first);

	if (value > EPS) return 1;   // CCW
	if (value < -EPS) return -1; // CW
	return 0;      
}
int CCW(point a, point b, point c)
{
	return Cross(SubstractVector(b, a), SubstractVector(c, b));

}
void PrintPos(point value)
{
	cout << " 좌표 : " << value.first << ", " << value.second << endl;
}
point GetPolarCoordinate(int value, int angle)
{
	// 45* = 2/pi
	// cos 45* = 1 / 루트2
	double sheta = angle * PI / 180.0;

	auto p = point(value * cos(sheta), value * sin(sheta));
	return point(value * cos(sheta), value * sin(sheta));
}
int Result = 0;

void Solution()
{
	// 만약 모든점이 순회 됬다면 첫점과 끝점이 이어지는지 체크
	if (selectPoints.size() == points.size())
	{

		int a = selectPoints[selectPoints.size() - 2];
		int b = selectPoints[selectPoints.size() - 1];
		int c = selectPoints[0];

		point pA = GetPolarCoordinate(a, (selectPoints.size() - 2) * 45);
		point pB = GetPolarCoordinate(b, (selectPoints.size() - 1) * 45);
		point pC = GetPolarCoordinate(c, 0);



		if (CCW(pA, pB, pC) >= EPS)
		{
			Result++;
			return;
		}
		else
		{
			return;
		}
	}
	// 점을 아직 선택하지 않았다면
	for (size_t i = 0; i < points.size(); i++)
	{
		// 이미 사용된 점은 무시
		if (checkPoint[i]) continue;


		// 2개이상의 점이 이미 선택된상태라면 ccw사용하여 왼쪽 체크
		if (selectPoints.size() >= 2)
		{
			// 밑 = 빗변 cos0  = x좌표
			// 높이 = 빗변 sin0 = y좌표

			int a = selectPoints[selectPoints.size() - 2];
			int b = selectPoints[selectPoints.size() - 1];
			int c = points[i];

			
			point pA = GetPolarCoordinate(a, (selectPoints.size() - 2) * 45);
			point pB = GetPolarCoordinate(b, (selectPoints.size() - 1) * 45);
			point pC = GetPolarCoordinate(c, selectPoints.size() * 45);



			if (CCW(pA, pB, pC) >= EPS)
			{

				// 사용할 포인트
				checkPoint[i] = true;
				selectPoints.push_back(points[i]);

				Solution();

				// 다시 사용할 수 있게 풀어줌+
				checkPoint[i] = false;
				// 탐색해본점은 제거
				selectPoints.pop_back();
			}

		}
		else
		{

			// 사용할 포인트
			checkPoint[i] = true;
			selectPoints.push_back(points[i]);

			Solution();
			// 다시 사용할 수 있게 풀어줌+
			checkPoint[i] = false;
			// 탐색해본점은 제거
			selectPoints.pop_back();
		}

	}
}

int main()
{

	
	for (size_t i = 0; i < 8; i++)
	{
		int n = 0;
		cin >> n;
		points.push_back(n);
	}

	// 다음점이 왼쪽으로 꺾인다면 오목한 모양이 되므로 경우에서 제외
	// 세타가 0에서 시작하여 오른쪽으로 돌아간다고 생각

	// 8개중 8개를 골라 나열하는방볍
	// 8P8 = 8!
	// 재귀를 활용해도 괜찮을까? 나올수있는 최대 경우의 수는 40320
	// 일단 백트레킹으로 풀어보자
	
	// 8개의 점이 모두 들어가면 탈출

	// 시작지점을 선택후 8개의 점이 모두 들어가면 탈출

	Solution();
	cout << Result << endl;

	return 0;
}