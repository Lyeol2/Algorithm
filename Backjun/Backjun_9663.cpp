// https://www.acmicpc.net/problem/9663



// 퀸은 모든 방향으로 공격할 수 있다
// 퀸 이 하나 배치되면 그 한줄은 무조건 사용할 수 없게 된다
// 어느 줄을 먼저 채우든 놓는 방법의 수는 똑같으므로 아래서부터 채운다

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
vector<int> placeQueen;
int PlaceQueen()
{

    // 처음 입장했으면
    // 만약 모든 퀸이 배치되었다면
    if (placeQueen.size() == N)
    {
        return 1;
    }
    // 퀸개수
    // 마지막 배치된 퀸은 자기 자리에서 위 세칸을 못쓰게 만든다


    int result = 0;

    for (size_t i = 0; i < N; i++)
    {
        bool check = true;
        for (size_t j = 0; j < placeQueen.size(); j++)
        {

            if (i != placeQueen[j] - (placeQueen.size() - j) &&
                i != placeQueen[j] &&
                i != placeQueen[j] + (placeQueen.size() - j))
            {
                continue;
            }
            else
            {
                check = false;
            }
        }
        if (!check) continue;

        placeQueen.push_back(i);
        result += PlaceQueen();
        placeQueen.pop_back();
    }

    return result;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    std::cin >> N;

    cout << PlaceQueen() << "\n";

}