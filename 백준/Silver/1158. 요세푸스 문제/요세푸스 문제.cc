#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		dq.emplace_back(i);
	}

	int index = 0;

	cout << '<';
	while (dq.size() != 1)
	{
		index = (index + K) % N;
		for (int i = 0; i < K-1; ++i)
		{
			dq.emplace_back(dq.front());
			dq.pop_front();
		}
		cout << dq.front() << ", ";
		dq.pop_front();
	}

	cout << dq.front() << '>';
}

