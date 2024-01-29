#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long N, M;
vector<int> v;

long long budgetCalculate(int budget) {
	long long sum = 0;
	for (auto a : v) {
		sum = sum + ((a - budget) > 0 ? budget : a);
	}
	return sum;
}

int binarySearch(int start, int end) {
	int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (budgetCalculate(mid) == M) {
			return mid;
		}
		else if (budgetCalculate(mid) > M) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	if (budgetCalculate(mid) > M) {
		mid -= 1;
	}
	return mid;
}

int main() {
	cin >> N;
	v.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cin >> M;
	sort(v.begin(), v.end());

	cout << binarySearch(0, v.back());
}