#include <iostream>
#include <algorithm>
using namespace std;

int arr[20];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 20; ++i)
	{
		arr[i] = i + 1;
	}

	for (int i = 0; i < 10; ++i)
	{
		int a, b;
		cin >> a >> b;
		reverse(arr + a -1 , arr + b );
	}

	for (int i = 0; i < 20; ++i)
	{
		cout << arr[i] << ' ';
	}
}

