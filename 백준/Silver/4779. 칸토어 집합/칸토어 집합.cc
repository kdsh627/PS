#include<iostream>
#include<cmath>

using namespace std;

void Cantor(int ind) {
	if (ind == 1) {
		cout << '-';
		return;
	}
	Cantor(ind/3);
	for (int i = 0; i < ind/3; i++) {
		cout << ' ';
	}
	Cantor(ind/3);
}

int main() {
	int N;
	while (cin >> N) {
		Cantor(pow(3, N));
		cout << '\n';
	}
}