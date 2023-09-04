#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define INF 1e9

using namespace std;

int arr[101][101];

int main()
{
    int N, M, a, b;
    cin >> N >> M;
    vector<pair<int, int>> result;
    for (int i = 1; i <=N; i++) {
        fill(arr[i], arr[i] + 100, INF);
        arr[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for (int k = 1; k <=N; k++) {
        for (int i = 1; i <=N; i++) {
            for (int j = 1; j <=N; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    for (int i = 1; i <=N; i++) {
        result.push_back({ accumulate(arr[i]+1, arr[i] + N + 1, 0), i });
    }
    sort(result.begin(), result.end());
    cout << result[0].second;
}