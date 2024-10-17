#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

list<char> listA;
list<char> listB;

int main()
{
	string A, B;
	cin >> A >> B;

	if (A.size() < B.size())
	{
		swap(A, B);
	}

	for(int i = A.size() - 1; i >= 0; --i)
	{
		listA.push_back(A[i]);
	}

	string result = "";
	int up = 0;

	int index = B.size() - 1;
	for (list<char>::iterator iter = listA.begin(); iter != listA.end(); ++iter)
	{
		int a = (int)*iter - '0';
		int b;
		if (index < 0) b = 0;
		else b = B[index--] - '0';

		int sum = a + b + up;
		if (sum >= 10)
		{
			up = sum / 10;
			sum -= up * 10;
		}
		else
		{
			up = 0;
		}

		result += to_string(sum);
	}
	if (up != 0)
	{
		result += to_string(up);
	}

	reverse(result.begin(), result.end());
	cout << result;
}