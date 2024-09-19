#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct INFO
{
    int index;
    int num;
    INFO(int _i, int _n) : index(_i), num(_n) {}
};
stack<INFO> st1;
stack<INFO> st2;
vector<int> result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    result.resize(N, 0);
    for (int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        st1.emplace(i, n);
    }

    INFO pre = st1.top();
    st1.pop();

    while (!st1.empty())
    {
        INFO cur = st1.top();
        st1.pop();

        //수신 가능하면
        if (pre.num <= cur.num)
        {
            while (!st2.empty())
            {
                INFO cur2 = st2.top();

                //스택 내에 존재하는 수신 가능한 수들을 다 표시
                if (cur2.num <= cur.num)
                {
                    result[cur2.index] = cur.index+1;
                }
                else
                {
                    break;
                }

                st2.pop();
            }

            result[pre.index] = cur.index+1;
        }
        //수신 불가능
        else
        {
            //다른 스택에 넣어준다.
            st2.emplace(pre);
        }
        
        pre = cur;
    }

    while (!st2.empty())
    {
        INFO cur = st2.top();
        st2.pop();
        if (cur.num <= pre.num)
        {
            result[cur.index] = pre.index+1;
        }
        else
        {
            result[cur.index] = 0;
        }
    }

    for (int n : result)
    {
        cout << n << ' ';
    }
}
