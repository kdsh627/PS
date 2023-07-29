#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long money;
long long num2;// 갱신이 진행될 변수
int N, C, W;
long long count;
long long max;
vector<int> v;
void search(int start, int end) {
	for (int i = start; i <= end; i++) {
		money = 0;
		num2 = 0;
		for (int a : v) {
			int div = a / i;
			num2 = div * W * i;
			if (a % i == 0) {
				::count = (div - 1) * C;
			}
			else {
				::count = div * C;
			}
			num2 -= ::count;
			if (num2 > 0) {
				money += num2;
			}
			::max = ::max > money ? ::max : money;
		}
	}
}

int main() {
	cin >> N >> C >> W;
	int wood;
	for (int i = 0; i < N; i++) {
		cin >> wood;
		v.push_back(wood);
	}
	sort(v.begin(), v.end());
	search(1, v.back());
	cout << ::max;
	return 0;
}