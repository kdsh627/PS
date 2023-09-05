#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int A, B;
void bfs() {
	queue<pair<int, string>> q;
	q.push({ A, ""});
	vector<int> visited(10000, 0);
	visited[A] = 1;
	while (!q.empty()) {
		pair<int, string> cur = q.front();
		q.pop();
		if (cur.first == B) {
			cout << cur.second;
			return;
		}
		int D = (cur.first * 2) % 10000;
		int S = (cur.first - 1) >= 0 ? cur.first - 1 : 9999;
		int L = (cur.first * 10 + (cur.first * 10) / 10000) % 10000;
		int R = (cur.first / 10) + (cur.first % 10) * 1000;
		if (!visited[D]) {
			visited[D] = 1;
			q.push({ D, cur.second + "D" });
		}
		if (!visited[S]) {
			visited[S] = 1;
			q.push({ S, cur.second + "S" });
		}
		if (!visited[L]) {
			visited[L] = 1;
			q.push({ L, cur.second + "L" });
		}
		if (!visited[R]) {
			visited[R] = 1;
			q.push({ R, cur.second + "R" });
		}
	}

}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		bfs();
		cout << "\n";
	}
}