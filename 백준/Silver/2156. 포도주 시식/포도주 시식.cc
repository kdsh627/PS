#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
vector<int> s;
int main() {
	int n;
	int maxs = 0;
	cin >> n;
	s.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	dp.resize( n + 1 );

	dp[0] = s[0];
	dp[1] = s[1];
	if (n == 1) {
		cout << dp[1];
	}
	else if (n == 2) {
		dp[2] = s[1] + s[2];
		cout << dp[2];
	}
	else {
		dp[2] = s[1] + s[2];
		for (int i = 3; i <= n; i++) {
			dp[i] = max(dp[i - 3] + s[i - 1] + s[i], max(dp[i - 2] + s[i], dp[i - 1]));
			maxs = maxs > dp[i] ? maxs : dp[i];
		}
		cout << maxs;
	}
}