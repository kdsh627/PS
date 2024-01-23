#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, H;

int dz[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, 1, -1 };

vector<vector<vector<int>>> v;
queue<pair<int, pair<int, pair<int, int>>>> q; //현재 깊이와 좌표로 구성

int depth = 0;

void bfs() {

	while(!q.empty()){;
		depth = q.front().first;
		int z = q.front().second.first;
		int y = q.front().second.second.first;
		int x = q.front().second.second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && nz >= 0 && nz < H) {
				if (v[nz][ny][nx] == 0) {
					v[nz][ny][nx] = 1;
					q.push(make_pair(depth+1, make_pair(nz, make_pair(ny, nx))));
				}
			}
		}
	}
}

int main() {
	cin >> M >> N >> H;
	v.resize(H);
	for (int i = 0; i < H; i++) {
		v[i].resize(N, vector<int>(M, 0));
	}
	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> v[z][y][x];
				if (v[z][y][x] == 1) {
					q.push(make_pair(0, make_pair(z, make_pair(y, x))));
				}
			}
		}
	}
	bfs();

	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (v[z][y][x] == 0) depth = -1;
			}
		}
	}
	cout << depth;
}