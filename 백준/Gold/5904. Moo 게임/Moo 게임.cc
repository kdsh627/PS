#include<iostream>
#include<vector>
using namespace std;

char result = 'o';
int N;

void moo_div(int start, int end, int count) {
	long long tmp = ((end - start - (count + 3)) / 2);
	long long mid = start + tmp;
	long long end2 = end - tmp;
	if ((N - 1) == start || (N - 1) == mid || (N - 1) == end2) {
		result = 'm';
	}
	else {
		if (tmp > 3) {
			if (N < mid) moo_div(start, mid, count-1);
			else moo_div(end2, end, count-1);
		}
	}
}

void moo(int pre, int count) {
	if (pre < N) {
		int cur = count + 4;
		pre = pre + cur + pre;
		count++;
		moo(pre, count);
	}
	else {
		moo_div(0, pre, count);
	}
}
int main() {
	cin >> N;
	moo(3, 0);
	cout << result;
}