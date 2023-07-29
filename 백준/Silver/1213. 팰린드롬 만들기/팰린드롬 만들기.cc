#include<iostream>
using namespace std;

int check[26];
int main() {
	string s;
	string result;
	cin >> s;
	for (auto a : s) {
		check[a - 'A']++;
	}
	int odd = -1;
	for (int i = 0; i < 26; i++) {
		if (check[i] % 2 == 1) odd = i;
		for (int j = 0; j < check[i]/2; j++) {
			result.push_back((char)(i + 65));
		}
	}
	if (odd != -1) {
		result.push_back((char)(odd + 65));
		check[odd]--;
	}
	for (int i = 25; i >= 0; i--) {
		if (check[i] % 2 == 1) {
			cout << "I'm Sorry Hansoo";
			return 0;
		}
		for (int j = 0; j < check[i] / 2; j++) {
			result.push_back((char)(i + 65));
		}
	}

	cout << result;
	return 0;
}