#include <iostream>
#include <stack>

using namespace std;

struct INFO
{
    int checkTop;
    int height;
    INFO(int c, int h) : checkTop(c), height(h) {}
};
stack<INFO> st1;
stack<INFO> st2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        st1.emplace(0, n);
    }

    long long int count = 0;
    INFO pre = st1.top();
    st1.pop();
    while (!st1.empty())
    {
        INFO cur = st1.top();
        st1.pop();

        //관측가능
        if (pre.height < cur.height)
        {
            while (!st2.empty())
            {
                INFO pre2 = st2.top();

                //관측 가능
                if (pre2.height < cur.height)
                {
                    cur.checkTop += (pre2.checkTop + 1);
                }
                else
                {
                    break;
                }

                st2.pop();
            }
            cur.checkTop += (pre.checkTop + 1);
            count += cur.checkTop;
        }
        //관측 불가능
        else
        {
            st2.emplace(pre);
        }

        pre = cur;
    }

    while (!st2.empty())
    {
        INFO cur = st2.top();
        if (cur.height < pre.height)
        {
            count += cur.checkTop;
        }
        else
        {
            break;
        }
        st2.pop();
    }

    cout << count;
}
