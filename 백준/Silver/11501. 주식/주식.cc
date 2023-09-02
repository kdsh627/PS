#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		vector<pair<long long, long long>> v1;
		v1.resize(M, {0, 0});
		for (int j = 0; j < M; j++) {
			v1[j].second = j;
			cin >> v1[j].first;
		}
		vector<pair<long long, long long>> v2 = v1;
		sort(v2.begin(), v2.end(), greater<>());
		long long result = 0;
		for (int x = 0; x < M; x++) {
			if (v1[x].first >= v2[0].first) continue;
			for (int y = 0; y < M; y++) {
				if (v1[x].second < v2[y].second && v1[x].first < v2[y].first) {
					result += v2[y].first - v1[x].first;
					break;
				}
			}
		}
		cout << result << "\n";
	}
}
