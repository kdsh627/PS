#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	int count = 0;
	int max_div = 0;
	cin >> N;
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		int div = 0;
		while (v[i] != 0) {
			if (v[i] % 2 == 1) {
				v[i] -= 1;
				count++;
			}
			else {
				v[i] /= 2;
				div++;
			}
		}
		max_div = max(max_div, div);
		div = 0;
	}
	cout << max_div + count;
}