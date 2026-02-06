#include <iostream>
#include <vector>
using namespace std;

int dp[21][21][21] = { 0, };

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (a < b && b < c)
    {
        if (dp[a][b][c - 1] == 0)
            dp[a][b][c - 1] = w(a, b, c - 1);
        if (dp[a][b - 1][c - 1] == 0)
            dp[a][b - 1][c - 1] = w(a, b - 1, c - 1);
        if (dp[a][b - 1][c] == 0)
            dp[a][b - 1][c] = w(a, b - 1, c);

        return dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
    }

    if (dp[a - 1][b][c] == 0)
        dp[a - 1][b][c] = w(a - 1, b, c);
    if (dp[a - 1][b - 1][c] == 0)
        dp[a - 1][b - 1][c] = w(a - 1, b - 1, c);
    if (dp[a - 1][b][c - 1] == 0)
        dp[a - 1][b][c - 1] = w(a - 1, b, c - 1);
    if (dp[a - 1][b - 1][c - 1] == 0)
        dp[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);

    return dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
}
vector<int> av;
vector<int> bv;
vector<int> cv;
int main()
{
    int a, b, c;
    while (true)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) break;

        av.push_back(a);
        bv.push_back(b);
        cv.push_back(c);


    }

    for (size_t i = 0; i < av.size(); i++)
    {
        a = av[i];
        b = bv[i];
        c = cv[i];
        cout << "w(" << a << ", " << b << ", " << c << ")" << " = " << w(a, b, c) << endl;

    }

    return 0;
}