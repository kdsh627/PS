#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> v;

void quad_tree(int x, int y, int N) {
	bool quad = 0;
	int first = v[y][x];
	for (int i = y; i < y + N; i++) {
		for (int j = x; j < x + N; j++) {
			if (first != v[i][j]) {
				quad = 1;
				break;
			}
		}
		if (quad) break;
	}

	if (quad) {
		cout << "(";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				quad_tree( x + j * N / 2, y + i * N / 2, N / 2); // x, y
			}
		}
		cout << ")";
	}
	else {
		cout << first;
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> v2(N, 0);
		for (int j = 0; j < N; j++) scanf("%1d", &v2[j]);
		v.push_back(v2);
	}
	quad_tree(0, 0, N); // x, y
}