#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int N;
vector<string> v;
vector<string> v1;
queue<pair<int, int>> q;

int bfs(int x, int y, char c, vector<string> &graph) {
	q.push({ x, y });
	vector<vector<int>> visited(N, vector<int>(N, 0));
	visited[x][y] = 1;

	while (!q.empty()) {
		pair<int, int> visit = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (visit.first + dx[i] >= 0 && visit.first + dx[i] < N && visit.second + dy[i] >= 0 && visit.second + dy[i] < N) {
				if (!visited[visit.first + dx[i]][visit.second + dy[i]]) {
					if (graph[visit.first + dx[i]][visit.second + dy[i]] == c) {
						graph[visit.first + dx[i]][visit.second + dy[i]] = 'X';
						q.push({ visit.first + dx[i], visit.second + dy[i] });
					}
				}
			}
		}
	}
	return 1;
}
int main() {
	int count1 = 0;
	int count2 = 0;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	v1 = v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v1[i][j] == 'G') v1[i][j] = 'R';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] != 'X') {
				count1 += bfs(i, j, v[i][j], v);
			} if (v1[i][j] != 'X') {
				count2 += bfs(i, j, v1[i][j], v1);
			}
		}
	}
	cout << count1 << " " << count2;
}