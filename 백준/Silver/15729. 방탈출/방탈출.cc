#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int main() {
	int N;
	int count = 0;
	cin >> N;
	v.resize(N+2, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < N; i++) {
		if (v[i]) {
			count++;
			if (v[i + 1]) v[i + 1] = 0;
			else v[i + 1] = 1;
			if (v[i + 2]) v[i + 2] = 0;
			else v[i + 2] = 1;
		}
	}
	cout << count;
}