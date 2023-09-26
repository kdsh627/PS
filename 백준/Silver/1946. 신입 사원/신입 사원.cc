#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int T;
	int maxs;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		vector<pair<int, int>> v;
		cin >> N;
		for (int j = 0; j < N; j++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x, y });
		}
		sort(v.begin(), v.end());
		int maxs = v[0].second;
		int length = 1;
		for (int j = 1; j < N; j++) {
			if (maxs > v[j].second) {
				length++;
				maxs = v[j].second;
			}
		}
		cout << length << "\n";
	}
}