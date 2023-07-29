#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{	
	int N;
	int num;
	cin >> N;
	priority_queue<int,vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		pq.push(num);
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			pq.push(num);
			pq.pop();
		}
	}
	cout << pq.top();
}