#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

vector<vector<int>> v;
queue<pair<int, pair<int, int>>> q; //현재 깊이와 좌표로 구성

int depth = 0;

void bfs() {

	while(!q.empty()){;
		depth = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (v[ny][nx] == 0) {
					v[ny][nx] = 1;
					q.push(make_pair(depth+1, make_pair(ny, nx)));
				}
			}
		}
	}
}

int main() {
	cin >> M >> N;
	v.resize(N, vector<int>(M, 0));
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> v[y][x];
			if (v[y][x] == 1) {
				q.push(make_pair(0, make_pair(y, x)));
			}
		}
	}

	bfs();

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (v[y][x] == 0) depth = -1;
		}
	}

	cout << depth;
}