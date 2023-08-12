#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
#define Y y + dy[i]
#define X x + dx[i]
vector<int> brute;
vector<string> vs;
vector<vector<int>> v;

int N, M; // N은 열, M은 행

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool bools = false;
vector<vector<int>> visit;
void dfs(int y, int x) { // y는 행, x는 열 좌표
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		if (Y >= 0 && X >= 0 && Y < M && X < N) {
			if (v[Y][X] == brute[0] || v[Y][X] == brute[1] || v[Y][X] == brute[2]) {
				if (!visit[Y][X]) {
					if (Y == M - 1) {
						bools = true;
						break;
					}
					dfs(Y, X);
				}
			}
		}
	}
	if (bools) {
		return;
	}
}

int main() {
	cin >> N >> M;
	v.resize(M, vector<int>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				for (int x = 0; x < N; x++) {
					if (v[0][x] != i) {
						continue;
					}
					brute.push_back(i);
					brute.push_back(j);
					brute.push_back(k);

					vector<vector<int>> visited;
					visited.resize(M, vector<int> (N, 0));
					visit = visited;
					bools = false;
					dfs(0, x);
					if (bools) {
						sort(brute.begin(), brute.end());
						printf("%d %d %d", brute[0], brute[1], brute[2]);
						return 0;
					}
					brute.clear();
				}
			}
		}
	}
	printf("-1 -1 -1");
}