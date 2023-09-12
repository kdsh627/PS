#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

vector<int> v;
int mins = 2000000000;
int mini[2];
void two_pointer() {
	int start = 0;
	int end = v.size() - 1;
	while (start < end) {
		int sum = v[start] + v[end];
		if (sum == 0) {
			cout << v[start] << " " << v[end];
			return;
		}
		else if(mins>=abs(sum)){
			mins = abs(sum);
			mini[0] = v[start];
			mini[1] = v[end];
		}
		
		if (sum > 0) {
			end--;
		}
		else {
			start++;
		}
	}
	cout << mini[0] << " " << mini[1];
	return;
}


int main() {
	int N;
	cin >> N;
	v.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	two_pointer();
}