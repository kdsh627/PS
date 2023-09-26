#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string S;
	string T;
	cin >> S >> T;
	while (S.size() != T.size()) {
		if (T[T.size() - 1] == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
	cout << (S == T);
}

