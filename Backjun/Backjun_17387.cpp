#include <iostream>
using namespace std;

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

int main() {
    long long ax, ay, bx, by;
    long long cx, cy, dx, dy;

    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;

    int ab_c = ccw(ax, ay, bx, by, cx, cy);
    int ab_d = ccw(ax, ay, bx, by, dx, dy);
    int cd_a = ccw(cx, cy, dx, dy, ax, ay);
    int cd_b = ccw(cx, cy, dx, dy, bx, by);

    if (ab_c == 0)
    {

        if ((ax < bx && ax <= cx && cx <= bx) || (ax > bx && bx <= cx && cx <= ax) ||
            (ay < by && ay <= cy && cy <= by) || (ay > by && by <= cy && cy <= ay))
        {
            cout << 1 << "\n";
            return 0;
        }
    }
    if (ab_d == 0)
    {
        if ((ax < bx && ax <= dx && dx <= bx) || (ax > bx && bx <= dx && dx <= ax) ||
            (ay < by && ay <= dy && dy <= by) || (ay > by && by <= dy && dy <= ay))
        {
            cout << 1 << "\n";
            return 0;
        }
    }
    if (cd_a == 0)
    {
        if ((cx < dx && cx <= ax && ax <= dx) || (cx > dx && dx <= ax && ax <= cx) ||
            (cy < dy && cy <= ay && ay <= dy) || (cy > dy && dy <= ay && ay <= cy))
        {
            cout << 1 << "\n";
            return 0;
        }
    }
    if (cd_b == 0)
    {
        if ((cx < dx && cx <= bx && bx <= dx) || (cx > dx && dx <= bx && bx <= cx) ||
            (cy < dy && cy <= by && by <= dy) || (cy > dy && dy <= by && by <= cy))
        {
            cout << 1 << "\n";
            return 0;
        }
    }

    if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
        cout << 1 << "\n";
    else
    {
        cout << 0 << "\n";
    }
}