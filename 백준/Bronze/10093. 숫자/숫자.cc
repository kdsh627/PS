#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long int A, B;
	cin >> A >> B;
	if (A > B)
	{
		swap(A, B);
	}

	cout << max(B - A - 1, (long long int)0) << '\n';
	for (A = A + 1; A < B; ++A)
	{
		cout << A << ' ';
	}
}
