#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, M;

vector<int> v;
vector<vector<int>> dp;


int main() {
    cin >> N >> S >> M;
    v.resize(N+1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    //dp테이블 초기화
    dp.resize(N + 1, vector<int>(M + 1, -1));

    dp[0][S] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[i - 1][j] == 1) {

                if (j + v[i] <= M) {
                    dp[i][j + v[i]] = 1;
                }

                if (j - v[i] >= 0) {
                    dp[i][j - v[i]] = 1;
                }
            }
        }
    }

    int maxs = -1;
    for (int j = 0; j <= M; j++) {
        if (dp[N][j] == 1) {
            maxs = max(maxs, j);
        }
    }

    cout << maxs;

    return 0;
}