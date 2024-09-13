#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	list<char> result;
	string s;
	cin >> s;

	for (char c : s)
	{
		result.push_back(c);
	}

	list<char>::iterator cursor = result.end();

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char c;
		cin >> c;
		if (c == 'L')
		{
			//커서가 처음이 아니면
			if (cursor != result.begin())
			{
				cursor--;
			}
		}
		else if (c == 'D')
		{
			//커서가 마지막이 아니면
			if (cursor != result.end())
			{
				cursor++;
			}
		}
		else if (c == 'B')
		{
			if (cursor != result.begin())
			{
				cursor = result.erase(--cursor);
			}
		}
		else
		{
			char alphabet;
			cin >> alphabet;
			result.insert(cursor, alphabet);
		}
	}

	for (char c : result)
	{
		cout << c;
	}
	cout << '\n';
}

