#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//무게가 중간이 될 수 없는 구슬 개수를 구하라
int visited[100];

vector<vector<vector<int>>> heavy;
int middle; // 중간값을 나타냄
int bfs(int spot, int mod) {
	int visited[100] = { 0, };
	queue<int> q;
	int num = 0;
	q.push(spot);
	visited[spot] = 1;

	while (!q.empty()) {
		int visit = q.front();
		q.pop();
		for (int i = 0; i < heavy[visit][mod].size(); i++) {
			if (!visited[heavy[visit][mod][i]]) {
				num++;
				if (num >= middle) {
					return 1;
				}
				q.push(heavy[visit][mod][i]);
				visited[heavy[visit][mod][i]] = 1;
			}
		}
	}
	return 0;
}

int main() {
	int N, M; //N은 몇번째 구슬까지, M은 질문 개수, N은 무조건 홀수
	cin >> N >> M; 
	middle = (N + 1) / 2;
	heavy.resize(N+1, vector<vector<int>>(2));
	int x, y;
	int count = 0;
	for (int i = 0; i < M; i++) {
		cin >> x >> y; //x는 y보다 무겁다
		heavy[x][0].push_back(y);
		heavy[y][1].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		if (bfs(i, 0)) count++;
		else if (bfs(i, 1)) count++;
	}
	cout << count;
}