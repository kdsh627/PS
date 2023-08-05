#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> point; //좌표를 나타낸다
typedef pair<int, point> tp; // 시간, 좌표를 나타낸다

int N, K, S, X, Y;
int x[4] = { 1,0,-1,0 };
int y[4] = { 0,1,0,-1 };
int m[1001][1001];

//우선순위 큐는 원래도 오름차순 출력이지만 다르게 비교할 경우가 있어서 추가
struct cmp { //우선 순위 큐에서의 정렬 방식
    bool operator()(tp a, tp b) { //우선 순위를 갖는것이 true, 일반적인 cmp와 반대
        if (a.first != b.first)
            return a.first > b.first; //true면 b.first가 우선순위가 됨
        else
            return m[a.second.first][a.second.second] > m[b.second.first][b.second.second];//시간이 똑같을시 바이러스 번호가 작은게 우선순위
    }
};

priority_queue <tp, vector<tp>, cmp> pq;

void bfs() {
    while (!pq.empty()) {
        int curx = pq.top().second.first;
        int cury = pq.top().second.second;
        int curt = pq.top().first;
        pq.pop();
        if (curt == S + 1) //시간 종료
            break;
        for (int k = 0; k < 4; k++) {
            if (curx + x[k] >= 1 && curx + x[k] <= N && cury + y[k] >= 1 && cury + y[k] <= N) {
                if (!m[curx + x[k]][cury + y[k]]) { //0인 곳에만 진출 가능
                    m[curx + x[k]][cury + y[k]] = m[curx][cury];
                    pq.push(make_pair(curt + 1, make_pair(curx + x[k], cury + y[k])));
                }
            }
        }
    }
}

int main() {
    cin >> N >> K; //N개의 줄 K이하의 자연수
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> m[i][j];
            if (m[i][j]) { //입력된 자연수가 0이 아닐경우?
                pq.push(make_pair(1, make_pair(i, j))); //현재 시간, 바이러스의 좌표 순으로 저장
            }
        }
    }
    cin >> S >> X >> Y;
    bfs();
    cout << m[X][Y];
}
