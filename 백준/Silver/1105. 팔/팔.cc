#include<iostream>
#include<string>
using namespace std;


int main() {
	int L, R;
	bool tf = true;
	cin >> L >> R;
	string Ls = to_string(L);
	string Rs = to_string(R);

	int result = 0;
	if (Ls.size() != Rs.size()) cout << result;
	else {
		for (int i = 0; i < Ls.size(); i++) {
			if (Ls[i] == '8' && Rs[i] == '8' && tf) {
				result++;
			}
			else if (Ls[i] == Rs[i]) {
				continue;
			}
			else tf = false;
		}
		cout << result;
	}
}