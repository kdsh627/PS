#include <iostream>

using namespace std;

int arr[7];

int main()
{
	for (int i = 0; i < 3; ++i)
	{
		int result = 0;
		for (int j = 0; j < 4; ++j)
		{
			int n;
			cin >> n;
			result = result + n;
		}

		result = (8 - result) % 5;
		cout << (char)(result + 65) << '\n';
	}
}
