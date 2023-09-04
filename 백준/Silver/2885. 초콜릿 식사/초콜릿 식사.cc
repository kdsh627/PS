#include<iostream>
#include<vector>
using namespace std;
int main() {
	int K;
	cin >> K;
	int mins = 1;
	int div = K;
	int count = 0;
	int cut = 0;
	bool tf = true;
	while (div / 2 != 0) {
		mins *= 2;
		count++;
		if (div % 2 == 1 && tf) {
			cut = count - 1;
			tf = false;
		}
		div /= 2;
	}
	if (mins < K) {
		mins *= 2;
		count++;
		cout << mins << " " << count - cut;
	}
	else {
		cout << mins << " 0";
	}
}