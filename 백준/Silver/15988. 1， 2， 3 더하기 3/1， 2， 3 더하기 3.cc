#include<iostream>

using namespace std;
long long dp[1000001];


int main() {
	int n, T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> T;
		cout << dp[T] << '\n';
	}
	
}