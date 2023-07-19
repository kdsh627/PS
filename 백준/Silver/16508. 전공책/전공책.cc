#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string t;
int n;
int tChar[26];
int selectedChar[26];
pair<int, string> book[16];
int result = 10000000;

bool check() {
	for (int i = 0; i < 26; i++) {
		if (tChar[i] > selectedChar[i]) {
			return false;
		}
	}
	return true;
}

void combination(int cnt, int priceSum) {

	if (cnt == n) {
		if (check()) {
			result = min(result, priceSum);
		}
		return;
	}
	for (int i = 0; i < book[cnt].second.length(); i++) {
		selectedChar[book[cnt].second[i] - 'A']++;
	}
	combination(cnt + 1, priceSum + book[cnt].first);
	for (int i = 0; i < book[cnt].second.length(); i++) {
		selectedChar[book[cnt].second[i] - 'A']--;
	}
	combination(cnt + 1, priceSum);
}

int main() {

	cin >> t >> n;
	for (int i = 0; i < t.length(); i++) {
		tChar[t[i] - 'A']++;
	}
	for (int i = 0; i < n; i++) {
		cin >> book[i].first >> book[i].second;
	}

	combination(0, 0);
	if (result == 10000000) {
		cout << -1;
	}
	else {
		cout << result;
	}
	return 0;
}