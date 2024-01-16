#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> v(101);
int count1 = 0;
int visited[101];

void dfs(int w) {
	visited[w] = 1;

	for (int i = 0; i < v[w].size(); i++) {
		int current = v[w][i];
		if (!visited[current]) {
			count1++;
			dfs(current);
		}
	}
}

int main() {
	int N, M; //개수, 쌍
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int y, x;
		cin >> y >> x;
		v[y].push_back(x);
		v[x].push_back(y);
	}
	
	dfs(1);

	cout << count1;
}