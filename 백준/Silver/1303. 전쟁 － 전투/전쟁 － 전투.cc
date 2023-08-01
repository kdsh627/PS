#include<iostream>
#include<vector>
using namespace std;

vector<string> v;
int N, M; //N은 가로 길이, M은 세로 길이

int x[4] = { 0, 0, -1, 1 };
int y[4] = { 1, -1, 0, 0 };

bool visited[100][100];
char search = 'W';

int count=1;

void dfs(int a, int b) {
	visited[a][b] = true;

	for (int j = 0; j < 4; j++) {
		if (a + x[j] >= 0 && a + x[j] < M && b + y[j] >= 0 && b + y[j] < N) {
			if (!visited[a + x[j]][b + y[j]] && (v[a + x[j]][b + y[j]] == search)) {
				::count++;
				dfs(a + x[j], b + y[j]);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	string s;
	for (int i = 0; i < M; i++) {
		cin >> s;
		v.push_back(s);
	}

	int resultW = 0;
	int resultB = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				if (v[i][j] == 'W') {
					search = 'W';
					dfs(i, j);
					resultW += (::count * ::count);
				}
				else {
					search = 'B';
					dfs(i, j);
					resultB += (::count * ::count);
				}

			}
			::count = 1;
		}
	}

	printf("%d %d", resultW, resultB);
}