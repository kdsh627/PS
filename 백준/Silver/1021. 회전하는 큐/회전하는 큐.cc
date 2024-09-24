#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v;
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        dq.push_back(i);
    }

    for (int i = 0; i < M; ++i)
    {
        int m;
        cin >> m;
        v.push_back(m);
    }
    
    int result = 0;
    for (int n : v)
    {
        for (int i = 0; i < N; ++i)
        {
            if (dq[i] == n)
            {
                if (i <= N - i - 1)
                {
                    while (dq.front() != n)
                    {
                        dq.push_back(dq.front());
                        dq.pop_front();
                        result++;
                    }
                    dq.pop_front();
                }
                else
                {
                    while (dq.front() != n)
                    {
                        dq.push_front(dq.back());
                        dq.pop_back();
                        result++;
                    }
                    dq.pop_front();
                }
                N -= 1;
                break;
            }
        }
    }

    cout << result;
}
