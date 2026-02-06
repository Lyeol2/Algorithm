#include <iostream>
#include <vector>
#include <math.h>

using namespace std;



// 볼록 껍질 (플레티넘 5)
// 예상 모든 점을 순회하고 순회한 점마다 한번더 순회하기때문에
// O(N^2) 의 시간이 나올것이라고 예측중

// https://www.acmicpc.net/problem/1708

using point = pair<long long, long long>;

vector<point> points;
vector<bool> selectPoint;

point AddVector(point a, point b)
{
	return point(a.first + b.first, a.second + b.second);
}
point SubstractVector(point a, point b)
{
	return point(a.first - b.first, a.second - b.second);
}
float DotProduct(point a, point b)
{
	return (a.first * b.first) + (a.second * b.second);
}

long long Distance(point a, point b)
{
	return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}
float GetCosWithTwoVector(point a, point b)
{
	float dotValue = DotProduct(a, b)
		/ ((Distance(point(0, 0), a) * Distance(point(0, 0), b)));
}
bool CrossToIsRight(point a, point b)
{
	return (a.first * b.second) - (a.second * b.first) >= 0;
}
bool Compare(point a, point b)
{
	return a.first == b.first && a.second == b.second;
}

// 시작점, 그 다음점이 정의되어있어야 3번째 점을 구할 수 있습니다
// 다시 돌아왔을 때의 점도 체크해야함
int Calculate(int count, int comparePointIdx, point startPoint, point endPoint)
{
	//cout << "P1 : " << startPoint.first << "," << startPoint.second << " /  P2 : " << endPoint.first << "," << endPoint.second << endl;

	// 현재 그리고 있는 선 시작위치 벡터
	auto current = SubstractVector(endPoint, startPoint);
	auto currentInverse = SubstractVector(startPoint, endPoint);

	// 가장 큰 인덱스
	int maxIdx = -1;
	// 내적 가장 큰값
	float maxDotValue = -99999999;

	for (int i = 0; i < points.size(); i++)
	{
		// 이미 탐색된 점도 제외
		if (selectPoint[i]) continue;
		// 자기자신은 제외
		if (Compare(points[i], endPoint)) continue;


		// 다음 그릴 선분의 임시 벡터
		auto another = SubstractVector(points[i], endPoint);

		// 일단 오른쪽이 아니라면 제외
		if (!CrossToIsRight(current, another))
		{
			//cout << "왼쪽 점 제외 : " << remainPoints[i].first << "," << remainPoints[i].second << endl;

			//cout << "탐색된 점 :" << remainPoints[i].first << "," << remainPoints[i].second << " : 왼쪽 점 제외" << endl;
			continue;
		}
		//cout << "P1 " << current.first << ", " << current.second << "에서" << " P2 " << another.first << ", " << another.second << endl;

		// 가장 둔각인 값을 골라야함으로 음수화
		float dotValue = -DotProduct(currentInverse, another)
			/ ((Distance(point(0, 0), currentInverse) * Distance(point(0, 0), another)));

		//cout << "dot Value" << dotValue << endl;
		//cout << "dot distance" << Distance(point(0, 0), currentInverse) * Distance(point(0, 0), another) << endl;

		// 만약 교체 건덕지가 있다면
		if (maxDotValue <= dotValue)
		{
			if (maxIdx == -1)
			{

				maxDotValue = dotValue;
				//cout << "탐색된 점 :" << remainPoints[i].first << "," << remainPoints[i].second << " : 신규 초기값" << endl;
				maxIdx = i;
				continue;
			}

			if (maxDotValue == dotValue)
			{
				// 더 작은값 남겨두기
				if (Distance(points[maxIdx], endPoint) > Distance(point(0, 0), another))
					continue;
				else
				{
					maxDotValue = dotValue;
					// 안쓸 인덱스는 남기기

					// 중복되는 값은 안쓸꺼임
					selectPoint[maxIdx] = true;
					//cout << "탐색된 점 :" << remainPoints[maxIdx].first << "," << remainPoints[maxIdx].second << " : 방향이 같지만 최고값 경신으로 인한" << endl;

					maxIdx = i;
				}
			}
			else
			{

				//cout << "탐색된 점 :" << remainPoints[maxIdx].first << "," << remainPoints[maxIdx].second << " : 최고값 경신으로 인한" << endl;
				maxDotValue = dotValue;
				// 안쓸 인덱스는 남기기
				maxIdx = i;

			}
		}
		else
		{

		}
	}
	// 인덱스를 못찾았으면
	if (maxIdx == -1 || points.size() <= 0)
	{
		//cout << "뭔가 버그있음" << endl;
		return count;
	}

	// 전체순회가 끝낫으면 마지막점에 찾아왔는지 체크
	if (Compare(points[maxIdx], points[comparePointIdx]))
	{
		count++;
		return count;
	}
	else
	{
		//cout << "찾은 점 :" << remainPoints[maxIdx].first << "," << remainPoints[maxIdx].second << endl;
		// 다음점 돌고 리턴
		selectPoint[maxIdx] = true;
		count++;
		//cout << "남은 점  : " << newRemainPoints.size() << endl;
		return Calculate(count, comparePointIdx, endPoint, points[maxIdx]);
	}
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
		selectPoint.push_back(false);
		points.push_back(point(X, Y));
	}

	// 점이 3개인 경우는 어떻게 만들어도 볼록껍질이다
	if (points.size() == 3)
	{
		cout << result;
		return 0;
	}

	float maxDist = 0;
	float firstIdx = 0;
	// 가장 처음 시작할 점을 선택한다.
	// 가장 처음 시작할 점은 무게중심으로부터 가장 먼 점이다.
	// 

	point sumPoint;
	for (int i = 0; i < points.size(); i++)
	{
		sumPoint = AddVector(sumPoint, points[i]);
	}

	point centerPoint = point(sumPoint.first / points.size(), sumPoint.second / points.size());

	for (int i = 0; i < points.size(); i++)
	{
		float dist = Distance(centerPoint, points[i]);
		if (dist > maxDist)
		{
			maxDist = dist;
			firstIdx = i;
		}
	}
	//cout << "무게중심 좌표 : " << centerPoint.first << "," << centerPoint.second << endl;
	//cout << "시작 좌표 : " << points[firstIdx].first << "," << points[firstIdx].second << endl;
	// 
	// 가장 먼점과 무게중심을 기준으로 오른쪽으로 회전하면서 다각형을 그려나간다
	// 외적을 이용해 왼쪽에 있는 점은 제외
	// 왼쪽 점을 제외한 나머지 점들중 이전선분과의 각 크기가 가장 큰 각을 선택한다
	// 첫 무게중심으로부터 나온 벡터의 끝점은 가장 멀리있는 점 이므로 무조건 예각이 나온다


	// 시계방향으로 점을따라 자취를 남길때
	// 두 점으로 이루어진 벡터 왼쪽에 점이 존재한다면 최대로 볼록한 점이 아니다

	cout << Calculate(0, firstIdx, centerPoint, points[firstIdx]) << endl;



	return 0;
}