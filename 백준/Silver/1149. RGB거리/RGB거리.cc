#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>v;
int cost[3];

int main() {
    int N;
    cin >> N;
    v.resize(N+1, vector<int>(3));
    for (int i = 1; i <= N; i++) {
        cin >> cost[0] >> cost[1] >> cost[2];
        v[i][0] = min(v[i - 1][1], v[i - 1][2]) + cost[0];
        v[i][1] = min(v[i - 1][2], v[i - 1][0]) + cost[1];
        v[i][2] = min(v[i - 1][1], v[i - 1][0]) + cost[2];
    }

    int mins = 1000000;
    for (int i = 0; i < 3; i++) {
        mins = min(v[N][i], mins);
    }
    cout << mins;
    return 0;
}