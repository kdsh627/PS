#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = { 0, 0 ,-1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int graph[1000][1000];
int xy[2];
int n, m;

queue<pair<int, int>> q;
int visited[1000][1000];
void bfs() {
	vector<vector<int>> dist(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				dist[i][j] = 0;
			}
		}
	}
	q.push({xy[0], xy[1]});
	dist[xy[0]][xy[1]] = 0;
	visited[xy[0]][xy[1]] = 1;

	while (!q.empty()) {
		pair<int, int> visit = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (visit.first + dx[i] < n && visit.first + dx[i] >= 0 && visit.second + dy[i] < m && visit.second + dy[i] >= 0) {
				if (!visited[visit.first + dx[i]][visit.second + dy[i]]) {
					visited[visit.first + dx[i]][visit.second + dy[i]] = 1;
					if (graph[visit.first + dx[i]][visit.second + dy[i]] != 0) {
						dist[visit.first + dx[i]][visit.second + dy[i]] = dist[visit.first][visit.second] + 1;
						q.push({ visit.first + dx[i] , visit.second + dy[i] });
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) {
				xy[0] = i;
				xy[1] = j;
			}
		}
	}
	bfs();
}