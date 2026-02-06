//https://www.acmicpc.net/problem/20149

#include <iostream>
#include <cmath>
using namespace std;

long long cross(long long ax, long long ay,
    long long bx, long long by)
{
    long long v = ax * by
        - bx * ay;

    return v;
}
int ccw(long long ax, long long ay,
    long long bx, long long by,
    long long cx, long long cy)
{
    long long v = (bx - ax) * (cy - ay)
        - (by - ay) * (cx - ax);
    if (v > 0) return 1;
    if (v < 0) return -1;
    return 0;
}
bool InRange(long long ax, long long ay,
    long long bx, long long by,
    long long px, long long py)
{

    // 2. 범위 판정
    if (min(ax, bx) < px && px < max(ax, bx) &&
        min(ay, by) < py && py < max(ay, by))
        return true;

    return false;
}
bool InRangeSame(long long ax, long long ay,
    long long bx, long long by,
    long long px, long long py)
{

    // 2. 범위 판정
    if (min(ax, bx) <= px && px <= max(ax, bx) &&
        min(ay, by) <= py && py <= max(ay, by))
        return true;

    return false;
}
int main() {

    cout.setf(ios::fixed); //정수도 소수점 아래 처리
    cout.precision(9); //cout의 소수점 범위를 9자리까지 늘린다. 4은 3.1415
    long long ax, ay, bx, by;
    long long cx, cy, dx, dy;

    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;

    long long vecAx = bx - ax;
    long long vecAy = by - ay;
    long long vecBx = dx - cx;
    long long vecBy = dy - cy;

    int ab_c = ccw(ax, ay, bx, by, cx, cy);
    int ab_d = ccw(ax, ay, bx, by, dx, dy);
    int cd_a = ccw(cx, cy, dx, dy, ax, ay);
    int cd_b = ccw(cx, cy, dx, dy, bx, by);

    bool checkPoint = false;
    long double  rx = 0, ry = 0;

    if(ab_c * ab_d <= 0 && cd_a * cd_b <= 0)
    {
        if (cross(vecAx, vecAy, vecBx, vecBy) == 0)
        {
            if (cross(cx - ax, cy - ay, vecAx, vecAy) == 0)
            {
                // vecA + vecB 

                bool connected =
                    (ax == cx && ay == cy) ||
                    (ax == dx && ay == dy) ||
                    (bx == cx && by == cy) ||
                    (bx == dx && by == dy);


                if (connected) 
                {
                    cout << "1\n";

                    if (max(ax, bx) == max(cx, dx) &&
                        max(ay, by) == max(cy, dy) &&
                        min(ax, bx) == min(cx, dx) &&
                        min(ay, by) == min(cy, dy))
                    {
                        return 0;
                    }

                    if (InRange(ax, ay, bx, by, cx, cy) ||
                        InRange(ax, ay, bx, by, dx, dy) ||
                        InRange(cx, cy, dx, dy, ax, ay) ||
                        InRange(cx, cy, dx, dy, bx, by))
                    {
                        return 0;
                    }
                    else
                    {
                        if ((ax == cx && ay == cy))
                        {
                            if ((bx - ax) * (dx - ax) <= 0 && (by - ay) * (dy - ay) <= 0)
                            {
                                cout << ax << " " << bx << endl;
                            }

                        }
                        else if ((bx == cx && by == cy))
                        {
                            if ((ax - bx) * (dx - bx) <= 0 && (ay - by) * (dy - by) <= 0)
                            {
                                cout << bx << " " << by << endl;
                            }



                            return 0;
                        }
                        else if ((bx == dx && by == dy))
                        {
                            if ((ax - bx) * (cx - bx) <= 0 && (ay - by) * (cy - by) <= 0)
                            {
                                cout << bx << " " << by << endl;
                            }


                            return 0;
                        }
                        else if ((ax == dx && ay == dy))
                        {
                            if ((cx - ax) * (bx - ax) <= 0 && (by - ay) * (cy - ay) <= 0)
                            {
                                cout << ax << " " << ay << endl;
                            }

                            return 0;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
                else
                {
                    if (InRangeSame(ax, ay, bx, by, cx, cy) ||
                        InRangeSame(ax, ay, bx, by, dx, dy) ||
                        InRangeSame(cx, cy, dx, dy, ax, ay) ||
                        InRangeSame(cx, cy, dx, dy, bx, by))
                    {
                        cout << "1\n";
                        return 0;
                    }
                    else
                    {
                        cout << "0\n";
                        return 0;
                    }
                }
            }
            else
            {
                cout << "0" << endl;
                return 0;
            }

        }
        else
        {


            cout << 1 << "\n";
            if (cross(vecBx, vecBy, vecAx, vecAy) == 0) return 0;
            long double u = cross(ax - cx, ay - cy, vecAx, vecAy) / (long double)cross(vecBx, vecBy, vecAx, vecAy);
            rx = cx + vecBx * u;
            ry = cy + vecBy * u;

            cout << rx << " " << ry << endl;

            return 0;
        }

        return 0;
    }
    else
    {
        cout << "0" << endl;
        return 0;
    }

    // 기울기가 같은경우는 출력 X

    // 한점에서 교차하지 않는 경우는 서로 기울기가 같은 경우이다.
    //if(checkPoint)
    //{ 
    //
    //    double slopeA = vecAx / vecAy;
    //    double slopeB = vecBx / vecBy;
    //    if (slopeA == slopeB)
    //    {
    //        // 기울기가 양수면
    //        if(slopeA > 0)
    //        // 기울기가 같은데 끝점에서 만나는 경우가 생길 수 있음
    //        if (max(ax, bx) == min(cx, dx) && max(ay, by) == min(cy, dy))
    //        {
    //            cout << max(ax, bx) << " " << max(ay, by) << endl;
    //            return 0;
    //        }
    //        else if (min(ax, bx) == max(cx, dx) && min(ay, by) == max(cy, dy))
    //        {
    //            cout << min(ax, bx) << " " << min(ay, by) << endl;
    //            return 0;
    //        }
    //    }
    //}
    // 평행한지
  


    // 기울기가 다른경우는 교점을 구함
    // 직선의 방정식 2개를 만듬 vecA vecB는 각각 a -> b c -> d임
    // a + t * vecA = c + u * vecB
    // a - c + t * vecA = u * vecB
    // 양변에 방향벡터 vecA로 외적하면 좌변의 값을 날릴 수 있게됨
    // (a-c + t * vecA) x vecA = (u * vecB) x vecA
    // (a - c) x vecA =  (u * vecB) x vecA
    // 스칼라는 빠져도 되므로
    // (a - c) x vecA = u(vecA x vecB)
    // 결론
    // u = (a - c) x vecA / (vecA x vecB)

    // u가 구해지면 직선의 방정식
    // c + u * vecB 로 교점의 벡터를 찾을 수 있음

}