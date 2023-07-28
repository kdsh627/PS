#include<iostream>
#include<vector>
using namespace std;

int check[1001];
int divs;
int cmp2; //이진탐색에서 찾아야할 변수

void binary_search(int start, int end) {
	if (start > end) {
		return;
	}
	int mid = (start + end) / 2;
	int cmp1 = mid * 1000 / divs; //갱신이 진행되는 변수

	if (cmp1 == cmp2) {
		check[divs]++;
		return;
	}
	else if (cmp1 > cmp2) { //더 큰 수를 찾았다면
		binary_search(start, mid - 1);
	}
	else { //더 작은 수를 찾았다면
		binary_search(mid + 1, end);
	}
}

int main() {
	int N;
	string s;
	int n = 0;
	vector<int> A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int count = 1000;
		cin >> s;
		for (char k : s) {
			if (k != '.') {
				n += (k - '0') * count;
				count/=10;
			}
		}
		A.push_back(n);
		n = 0;
	}
	for (int j : A) {
		for (int i = 1; i <= 1000; i++) { //인원 수
			int bottom = j / 1000;
			divs = i;
			cmp2 = j;
			binary_search(bottom * i, (bottom + 1) * i);
		}
	}

	for (int i = 1; i <= 1000; i++) {
		if (check[i] == N) {
			cout << i;
			break;
		}
	}
	return 0;
}