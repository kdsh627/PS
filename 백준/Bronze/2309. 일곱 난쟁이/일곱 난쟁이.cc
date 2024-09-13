#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int ind[9] = {0,0,1,1,1,1,1,1,1};
int main()
{
	for (int i = 0; i < 9; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + 9);

	do
	{
		int result = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (ind[i] == 1)
			{
				result = result + arr[i];
			}
		}

		if (result == 100)
		{
			for (int i = 0; i < 9; ++i)
			{
				if (ind[i] == 1)
				{
					cout << arr[i] << '\n';
				}
			}
			break;
		}
	} while (next_permutation(ind, ind+9));
}
