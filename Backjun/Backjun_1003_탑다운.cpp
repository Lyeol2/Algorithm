#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int dpZero[41] = {};
int dpOne[41] = {};
vector<int> counts;

pair<int, int> fibonacci(int n) 
{
    if (n == 0) {
        dpZero[n] = 1;
        return pair<int,int>(dpZero[n], dpOne[n]);
    }
    else if (n == 1) {
        dpOne[n] = 1;
        return pair<int, int>(dpZero[n], dpOne[n]);
    }
    else {
        if (dpZero[n] == 0 || dpOne[n] == 0)
        {
            fibonacci(n - 1);
            fibonacci(n - 2);
            dpZero[n] = dpZero[n - 1] + dpZero[n - 2];
            dpOne[n] = dpOne[n - 1] + dpOne[n - 2];
        }
        return pair<int, int>(dpZero[n], dpOne[n]);

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 0;
    std::cin >> T;

    int N = 0;
    for (int i = 0; i < T; ++i)
    {
        std:cin >> N;
        counts.push_back(N);
    }

    for (size_t i = 0; i < T; i++)
    {
        auto value = fibonacci(counts[i]);
        cout << value.first << " " << value.second << endl;
    }
    



	return 0;
}