#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int dpZero[41] = {};
int dpOne[41] = {};
vector<int> counts;

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
        if (dpZero[counts[i]] == 0 || dpOne[counts[i]] == 0)
        {
            for (size_t j = 0; j < counts[i] + 1; j++)
            {
                if (j == 0)
                {
                    dpZero[j] = 1;
                }
                else if (j == 1)
                {
                    dpOne[j] = 1;
                }
                else
                {
                    dpOne[j] = dpOne[j - 1] + dpOne[j - 2];
                    dpZero[j] = dpZero[j - 1] + dpZero[j - 2];
                }
            }
        }

        cout << dpZero[counts[i]] << " " << dpOne[counts[i]] << "\n";
    }

    



    return 0;
}