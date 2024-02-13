#include <iostream>
#include <algorithm>
using namespace std;

int train[100001];

int main() {
    int N, M, ans = 1;
    int order, trainNum, index;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> order >> trainNum;
        if (order < 3) {
            cin >> index;
            int idx = 1;
            for (int j = 1; j < index; j++) idx <<= 1;
            if (order == 1) train[trainNum] |= idx;
            else train[trainNum] &= ~(idx);
        }
        else if (order == 3) {
            train[trainNum] &= ~(1 << 19);
            train[trainNum] <<= 1;
        }
        else if (order == 4) {
            train[trainNum] &= ~(1);
            train[trainNum] >>= 1;
        }
    }

    sort(train + 1, train + 1 + N);
    int tmp = train[1];
    for (int i = 2; i <= N; i++) {
        if (tmp != train[i]) ans++;
        tmp = train[i];
    }
    cout << ans;
}