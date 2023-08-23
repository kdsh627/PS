#include<iostream>
#include<queue>
using namespace std;
int F, S, G, U, D; //F는 최고층, S는 현재 층, G는 가야하는 곳

vector<bool> visited;
queue<pair<int, int>> q;

void bfs(int s, int deep) {

	q.push({S, deep});

	while(!q.empty()) {
		pair<int, int> visit = q.front();
		q.pop();

		if (visit.first <= 0 || visit.first > F) {
			continue;
		}
		else if (visit.first == G) {
			cout << visit.second;
			return;
		}
		else {
			if (visited[visit.first]) {
				continue;
			}
			visited[visit.first] = 1;
			q.push({ visit.first + U, visit.second + 1 });
			q.push({ visit.first - D, visit.second + 1 });
		}
	}
	cout << "use the stairs";
}

int main() {
	cin >> F >> S >> G >> U >> D;
	visited.resize(F + 1, 0);
	bfs(S, 0);
	return 0;
}