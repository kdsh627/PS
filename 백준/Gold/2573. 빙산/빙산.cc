#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int N, M;

vector<vector<int>> graph;
vector<vector<int>> graph2;

int result = 0;
bool tf = true;

void dfs(int x, int y) {
	graph2[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M) {
			if (graph2[x + dx[i]][y + dy[i]] > 0) {
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}
}
void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] != 0) {
				int count = 0;
				for (int k = 0; k < 4; k++) {
					if (i + dx[k] >= 0 && i + dx[k] < N && j + dy[k] >= 0 && j + dy[k] < M) {
						if (graph[i + dx[k]][j + dy[k]] == 0) count++;
					}
				}
				if (count >= graph[i][j]) graph[i][j] = -1;
				else graph[i][j] -= count;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] < 0) graph[i][j] = 0;
		}
	}
}
void date() {
	result++;
	melt();
	graph2 = graph;
	bool tf2 = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph2[i][j] > 0) {
				if (!tf2) tf = false; //2개의 덩이가 나왔을 경우
				dfs(i, j);
				tf2 = false;
			}
		}
	}
	if ( tf==true && tf2==true) result = 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	graph.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	while (true) {
		date();
		if ( !tf || result == 0) {
			cout << result;
			break;
		}
	}
}