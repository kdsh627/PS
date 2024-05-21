#include <iostream>
using namespace std;

int main() {
	int A, N, X;
	cin >> N >> X;
    
	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A < X) {
			cout << A<<" ";
		}
	}
}