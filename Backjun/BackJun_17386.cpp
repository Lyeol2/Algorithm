//https://www.acmicpc.net/problem/17386
#include <iostream>
using namespace std;
int main()
{
	// 두선분이 교차하려면

	// 선분 AB에 대하여
	// 점 C는 AB의 왼쪽
	// 점 D는 AB의 오른쪽에 있어야한다

	// 또는 그 반대가 성립해야한다

	// 삼각형 ABC 가 둔각이면 삼각형 ABD는 예각이여야한다
	// 또는 그 반대여야한다


	long long ax, ay = 0;
	long long bx, by = 0;
	cin >> ax >> ay >> bx >> by;
	long long cx, cy = 0;
	long long dx, dy = 0;
	cin >> cx >> cy >> dx >> dy;

	// 기준선분
	long long vecX, vecY = 0;

	vecX = bx - ax;
	vecY = by - ay;

	long long vec2X = cx - ax;
	long long vec2Y = cy - ay;
	long long vec3X = dx - ax;
	long long vec3Y = dy - ay;

	// 기준 선분을 기준으로 C가 오른쪽인지 판단
	long long right = (vecX * vec2Y) - (vecY * vec2X);
	// 일직선인 경우는 없으니
	long long left = (vecX *vec3Y) - (vecY * vec3X);

	// 일직선이

	if (right > 0 && left < 0)
	{
		// 선분 ABC , ABD 의 둔각 예각 판단
		// BA BC 가 둔각이면 BA BD 가 예각
		// 직각되어 수직인경우는 없다 3점이 한직선에 없기떄문에

		// BA
		long long BAx = ax - bx;
		long long BAy = ay - by;

		// BC
		long long BCx = cx - bx;
		long long BCy = cy - by;
		//cout << "BC : " << BCx << "," << BCy << endl;
		// BD
		long long BDx = dx - bx;
		long long BDy = dy - by;

		long long dotA = BAx* BCx + BAy * BCy;
		long long dotB = BAx* BDx + BAy * BDy;


		//cout << "dot : " << dotA << "," << dotB << endl;

		if (dotA < 0 && dotB < 0)
		{
			cout << 0 << endl;
			return 0;
		}
		else
		{
			cout << 1 << endl;
			return 0;
		}

		// |A * B| >= 0 여야 둔각
		// |A * B| <= 0 여야 예각
		// 90도인경우는 그냥 다통과시켜
	}
	else if(right < 0 && left > 0)
	{
		// 선분 ABC , ABD 의 둔각 예각 판단
		// BA BC 가 둔각이면 BA BD 가 예각
		// 직각되어 수직인경우는 없다 3점이 한직선에 없기떄문에

		// BA
		long long BAx = ax - bx;
		long long BAy = ay - by;

		// BC
		long long BCx = cx - bx;
		long long BCy = cy - by;

		// BD
		long long BDx = dx - bx;
		long long BDy = dy - by;

		long long dotA = BAx * BCx + BAy * BCy;
		long long dotB = BAx * BDx + BAy * BDy;


		if (dotA < 0 && dotB < 0)
		{
			cout << 0 << endl;
			return 0;
		}
		else
		{
			cout << 1<< endl;
			return 0;
		}
	}
	else
	{
		cout << 0 << endl;
		return 0;
	}
	return 0;
	// 기준 선분을 기준으로 CX가 오른쪽인지 판단
}