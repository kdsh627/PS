#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> v;

queue<pair<int, int>> q;

vector<pair<int, int>> result;

vector<int> visited;

void bfs(int k) {

	visited[k] = true;

	q.push({ 0,k });
	result.push_back({ 0,k });

	while (!q.empty()) {
		pair<int, int> visit = q.front();
		q.pop();

		for (int i = 0; i < v[visit.second].size(); i++) {
			int cur = v[visit.second][i];
			if (!visited[cur]) {
				q.push({ visit.first + 1, cur });
				if (result.back().first != visit.first + 1) {
					result.clear();
				}
				result.push_back({ visit.first + 1, cur });
				visited[cur] = true;
			}
		}
	}
}

int main() {
	int N, M, x, y;
	int count = 0;
	cin >> N >> M;
	v.resize(N+1);
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	visited.resize(N+1, 0);
	bfs(1);
	sort(result.begin(), result.end());
	printf("%d %d %d", result[0].second, result[0].first, result.size());
}