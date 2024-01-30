#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int R, C;
int dy[4] = {0, 0 ,1, -1};
int dx[4] = {1, -1, 0, 0};

vector<vector<int>> v;
queue<pair<int, pair<int, int>>> q; 
queue<pair<int, int>> q2;
int min_depth = -1;

//벽 = 9, 지훈 = 1, 불 = 2

void bfs() {
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int y = q.front().second.first;
			int x = q.front().second.second;
			int depth = q.front().first;
			q.pop();

			if (v[y][x] == 1) {
				if (y == (R - 1) || x == (C - 1) || y == 0 || x == 0) {
					min_depth = depth + 1;
					return;
				}
			}
			else continue;

			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
					if (v[ny][nx] == 0) {
						v[ny][nx] = 1;
						q.push(make_pair(depth + 1, make_pair(ny, nx)));
					}
				}
			}
		}

		size = q2.size();
		for (int i = 0; i < size; i++) {
			int y = q2.front().first;
			int x = q2.front().second;
			q2.pop();

			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
					if (v[ny][nx] != 9 && v[ny][nx] != 2) {
						v[ny][nx] = 2;
						q2.push(make_pair(ny, nx));
					}
				}
			}
		}
	}
}

int main() {
	cin >> R >> C;
	v.resize(R, vector<int>(C, 0));
	for (int y = 0; y < R; y++) {
		string s;
		cin >> s;
		for (int x = 0; x < C; x++) {
			if (s[x] == '#') v[y][x] = 9;
			else if (s[x] == 'J') {
				v[y][x] = 1;
				q.push(make_pair(0, make_pair(y, x)));
			}
			else if (s[x] == 'F') {
				v[y][x] = 2;
				q2.push(make_pair(y, x));
			}
		}
	}
	bfs();

	if (min_depth == -1) cout << "IMPOSSIBLE";
	else cout << min_depth;
}