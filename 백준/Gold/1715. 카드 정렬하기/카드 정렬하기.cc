#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() 
{
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	int c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		pq.push(c);
	}
	
	int card = pq.top();
	pq.pop();

	int sum = 0;

	while (!pq.empty())
	{
		int nextCard = pq.top();
		pq.pop();

		sum += card + nextCard;
		pq.push(card + nextCard);
		card = pq.top();
		pq.pop();
	}


	cout << sum;
}