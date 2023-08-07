#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int dp[1000];

int main() {
	int N;
	int maxs;
	scanf("%d", &N);
	v.resize(N, 0);
	for (int i = 0; i < N; i++) scanf("%d", &v[i]);
	dp[0] = v[0];
	maxs = dp[0];

	for (int i = 1; i < N; i++) {
		dp[i] = v[i];
		int max_dp = 0;
		for (int j = i-1; j >= 0; j--) {
			if (v[j] < v[i]) max_dp = max_dp > dp[j] ? max_dp : dp[j];
		}
		dp[i] += max_dp;
		maxs = maxs > dp[i] ? maxs : dp[i];
	}
	cout << maxs;
}