#include<iostream>
#include<vector>

using namespace std;

int n, m; //n은 세로, m은 가로
int area_count = 0;
int area = 0;
int max_area = 0;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int visited[500][500];
vector<vector<int>> v(500, vector<int>(500, 0));

void dfs(int y, int x) {
	area += 1;
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if (!visited[ny][nx] && v[ny][nx] == 1) dfs(ny, nx);
		}
	}
}

int main() {
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 1 && !visited[i][j]) {
				dfs(i, j);
				max_area = max(max_area, area);
				area = 0;
				area_count += 1;
			}
		}
	}

	cout << area_count << '\n' << max_area;
}