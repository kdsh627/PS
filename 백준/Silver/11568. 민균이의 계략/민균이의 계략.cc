#include<iostream>
#include<vector>
using namespace std;

int dp[1001];
vector<int> v;

int main() {
	int N;
	cin >> N;
	v.resize(N+1, 0);
	int maxs = dp[0];
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		int max1 = 0;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				max1 = max1 > dp[j] ? max1 : dp[j];
			}
		}
		dp[i] = max1 + 1;
		maxs = max(maxs, dp[i]);
	}
	cout << maxs;
}