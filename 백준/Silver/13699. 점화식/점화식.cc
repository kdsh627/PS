#include<iostream>
#include<vector>
using namespace std;

long long dp[36];
int main()
{
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 35; i++) {
		long long sigma = 0;
		for (int j = 0; j <= i; j++) {
			sigma += dp[j] * dp[i - j - 1];
		}
		dp[i] = sigma;
	}
	cout << dp[n];
}