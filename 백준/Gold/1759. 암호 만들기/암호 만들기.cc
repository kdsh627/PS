#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int L, C; // L은 구성하는 문장 길이, C는 구성하는 알파벳 종류
	cin >> L >> C;
	char c;
	vector<string> v;
	vector<char> ja; //자음
	vector<char> mo; //모음
	for (int i = 0; i < C; i++) {
		cin >> c;
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') mo.push_back(c);
		else ja.push_back(c);
	}
	int start = max(1, L - (int)ja.size()); //모음이 있어야 할 최소 개수
	int end = min((int)mo.size(), L - 2); //모음이 있어야 할 최대 개수

	for (int i = start; i <= end; i++) {
		vector<int> sub(mo.size(), 0);
		for (int j = 1; j <= i; j++) sub[sub.size() - j] = 1;
		do {
			string s = "";
			for (int k = 0; k < sub.size(); k++) {
				if (sub[k] == 1) {
					s += mo[k];
				}
			}
			vector<int> sub2(ja.size(), 0);
			for (int a = L - i; a > 0; a--) sub2[sub2.size() - a] = 1;
			do {
				string s2 = s;
				for (int b = 0; b < sub2.size(); b++) {
					if (sub2[b] == 1) {
						s2 += ja[b];
					}
				}
				sort(s2.begin(), s2.end());
				v.push_back(s2);
			} while (next_permutation(sub2.begin(), sub2.end()));
		} while (next_permutation(sub.begin(), sub.end()));
	}
	sort(v.begin(), v.end());
	for (auto a : v) {
		cout << a << "\n";
	}
}