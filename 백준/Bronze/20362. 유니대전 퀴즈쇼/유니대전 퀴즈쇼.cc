#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;

	string answer;
	multimap<string, string> m;
	for (int i = 0; i < N; ++i)
	{
		string name, chat;
		cin >> name >> chat;

		m.emplace(chat, name);

		if (name == S) answer = chat;
	}

	int count = 0;
	for (multimap<string, string>::iterator iter = m.lower_bound(answer); iter != m.upper_bound(answer); iter++)
	{
		if (iter->second == S)
		{
			break;
		}
		count++;
	}

	cout << count;
}
