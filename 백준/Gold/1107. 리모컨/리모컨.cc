#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

string N;
int M;
vector<int> error;
int main() {
	cin >> N;
	cin >> M;
	error.resize(M, 0);
	for (int i = 0; i < M; i++) {
		cin >> error[i];
	}

	if (N == "100") cout << 0;
	else {
		int minimum = 999999;
		int ch = stoi(N);

		for (int i = 0; i < 1000000; i++) {
			int pass = 0;
			string cur_ch = to_string(i);

			for (int er_num : error) {
				if (!(cur_ch.find(to_string(er_num)) == string::npos)) {
					pass = 1;
					break;
				}
			}

			if (!pass) {
				int diff = (abs(ch - i) < abs(i - ch) ? abs(ch - i) : abs(i - ch)) + cur_ch.size();
				minimum = min(minimum, diff);
			}
		}

		minimum = min(minimum, abs(100 - ch) < abs(ch - 100) ? abs(100 - ch) : abs(ch - 100));
		cout << minimum;
	}
}