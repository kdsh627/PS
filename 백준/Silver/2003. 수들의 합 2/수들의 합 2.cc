#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int intervalSum = 0;
	int end = 0;
	int count = 0;

	for (int start = 0; start < N; start++) {

		while (intervalSum < M && end < N) {
			intervalSum += v[end];
			end += 1;
		}

		if (intervalSum == M) {
			count += 1;
		}
		intervalSum -= v[start];
	}

	cout << count;
}