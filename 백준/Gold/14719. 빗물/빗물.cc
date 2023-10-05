#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> wall;

int main() {
	int count = 0;
	int H, W; //H는 높이 W는 너비
	cin >> H >> W;
	wall.resize(W);
	for (int i = 0; i < W; i++) {
		cin >> wall[i];
	}

	for (int i = 0; i < H; i++) {
		int start = 0;
		int end = 0;
		for (int j = 0; j < W; j++) {
			if (wall[j] > i) {
				start = j;
				break;
			}
		}
		for (int j = W-1; j >= 0; j--) {
			if (wall[j] > i) {
				end = j;
				break;
			}
		}
		if (start == end) continue;
		for (int j = start; j <= end; j++) {
			if (wall[j] <= i) {
				count++;
			}
		}
	}
	cout << count;
}