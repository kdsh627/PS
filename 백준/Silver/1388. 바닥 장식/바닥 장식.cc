#include<iostream>
#include<vector>
using namespace std;
vector<string> graph;
int main() {
	int N, M; // N은 세로, M은 가로
	string s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		graph.push_back(s);
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		// |는 124, -는 77
		if(graph[i][0] == '-') count++;
		for (int j = 1; j < M; j++) {
			if ((int)graph[i][j] < (int)graph[i][j-1]) count++; // "|-" 패턴의 개수를 센것
		}
	}
	for (int i = 0; i < M; i++) {
		if (graph[0][i] == '|') count++;
		for (int j = 1; j < N; j++) {
			if ((int)graph[j][i] > (int)graph[j-1][i]) count++;
		}
	}
	cout << count;
}