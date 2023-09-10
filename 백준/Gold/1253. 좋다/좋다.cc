#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int two_porinter(int M, int index) {
	int start = 0;
	int end = v.size()-1;
	while (start < end)
	{
		long long sum = v[start] + v[end];
		if (sum > M || end == index) end--;
		else if (sum < M || start == index) start++;
		else if(sum == M) return 1;
	}
	return 0;
}

int main() {
	int N;
	int index = 0;
	int count = 0;
	cin >> N;
	v.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (auto a : v) {
		count += two_porinter(a, index++);
	}
	cout << count;
}