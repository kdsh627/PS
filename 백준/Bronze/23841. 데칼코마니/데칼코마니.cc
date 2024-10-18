#include <iostream>
#include <vector>
using namespace std;

vector<string> result;

int main()
{
	int N, M;//세로 가로
	cin >> N >> M;

	string s;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != '.')
			{
				s[s.size() - i - 1] = s[i];
			}
		}
		result.push_back(s);
	}

	for (string str : result)
	{
		cout << str << '\n';
	}
}
