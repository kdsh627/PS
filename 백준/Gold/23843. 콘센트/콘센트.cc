#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> result; //작은게 맨앞
priority_queue<int> pq; //큰게 맨앞

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int t;
        cin >> t;
        pq.emplace(t);
    }

    int maxValue = 0;
    for (int i = 0; i < N; ++i)
    {
        int cur = pq.top();
        int first;
        if (result.size() < M)
        {
            result.emplace(cur);
            first = cur;
        }
        else
        {
            first = result.top() + cur;
            result.pop();
            result.emplace(first);
        }

        if (maxValue < first)
        {
            maxValue = first;
        }

        pq.pop();
    }

    cout << maxValue;
}
