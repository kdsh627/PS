#include <iostream>
#include <queue>
using namespace std;

deque<int> dq;

int main()
{
    int N, K, M;

    cin >> N >> K >> M;

    for (int i = 1; i <= N; ++i)
    {
        dq.push_back(i);
    }

    int count = 0;
    bool isReverse = false;
    while (!dq.empty())
    {
        if (count == M)
        {
            isReverse = !isReverse;
            count = 0;
        }

        if (!isReverse) //정배열
        {
            for (int i = 0; i < K - 1; ++i)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout << dq.front() << '\n';
            dq.pop_front();
        }
        else //역배열
        {
            for (int i = 0; i < K - 1; ++i)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout << dq.back() << '\n';
            dq.pop_back();
        }

        count++;
    }
}
