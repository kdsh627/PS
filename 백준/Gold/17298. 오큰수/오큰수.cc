#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct INFO
{
    int index;
    int num;
    INFO(int i, int n) : index(i), num(n) {}
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

    result.resize(N, -1);
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

        //pre가 cur의 오큰수면
        if (cur.num < pre.num)
        {
            result[cur.index] = pre.num;
            //다른 수의 오큰수도 될 수 있으니 스택에 저장
            st2.push(pre);
        }
        //해당되지 않으면
        else
        {
            //기존 오큰수 스택에서 비교
            while (!st2.empty())
            {
                INFO pre2 = st2.top();
                //pre2가 cur의 오큰수면
                if (cur.num < pre2.num)
                {
                    result[cur.index] = pre2.num;
                    break;
                }
                st2.pop();
            }
        }

        pre = cur;
    }

    for (int n : result)
    {
        cout << n << ' ';
    }
}
