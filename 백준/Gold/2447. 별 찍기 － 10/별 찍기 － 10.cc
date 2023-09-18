#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<char>> v;

void star(int x, int y, int N) {
	int count = 0;
	if (N != 3) {
		for (int i = x; i < x+N; i+=(N/3)) {
			for (int j = y; j < y+N; j+=(N/3)) {
				if (count != 4) star(i, j, N / 3);
				count++;
			}
		}
	}
	else {
		for (int i = x; i < x+3; i ++) {
			for (int j = y; j < y+3; j ++) {
				if (count != 4) v[i][j] = '*';
				count++;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	v.resize(N, vector<char>(N, ' '));
	star(0, 0, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << v[i][j];
		}
		cout << "\n";
	}
}