#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        sum += x[i] * y[j] - x[j] * y[i];
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(sum) / 2.0 << endl;
}