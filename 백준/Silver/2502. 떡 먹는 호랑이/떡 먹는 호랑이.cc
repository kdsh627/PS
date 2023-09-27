#include <iostream>
using namespace std;

int dp[31][2];

int main(void)
{
	int D, K; // Day, KkulDduck
	cin >> D >> K;

	dp[1][0] = 1;
	dp[1][1] = 0;

	dp[2][0] = 0;
	dp[2][1] = 1;

	for (int i = 3; i <= D; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	
	int A = 1;
	int B = (K - dp[D][0]) / dp[D][1];
	for (int i = B; i >= 1; i--) {
		if ((K - i * dp[D][1]) % dp[D][0] == 0) {
			A = (K - i * dp[D][1]) / dp[D][0];
			B = i;
			break;
		}
	}
	cout << A << '\n' << B;
}