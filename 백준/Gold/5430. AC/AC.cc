#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

bool isReverse = false;

int main()
{
    int T;//테스트 케이스
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        deque<int> dq;
        queue<int> result;

        string p; //명령
        cin >> p;

        int n; //배열 크기
        cin >> n;

        char x[300000];
        cin >> x;

        char* token = strtok(x, ",[]");

        while (token)
        {
            dq.push_back(stoi(token));
            token = strtok(NULL, ",[]");
        }

        bool isReverse = false;
        bool isError = false;
        for (char order : p)
        {

            if (order == 'R') //뒤집기
            {
                isReverse = !isReverse;
            }
            else if(order == 'D')
            {
                if (dq.empty())
                {
                    isError = true;
                }
                else
                {
                    if (isReverse)//뒤집는다면
                    {
                        dq.pop_back();
                    }
                    else//아니라면
                    {
                        dq.pop_front();
                    }
                }
            }
        }
        
        if (isError)
        {
            cout << "error\n";
        }
        else
        {
            cout << '[';
            if (isReverse)
            {
                for (int i = dq.size()-1; i >= 0; --i)
                {
                    if (i == 0) cout << dq[i];
                    else cout << dq[i] << ',';

                }
                cout << "]\n";
            }
            else
            {
                for (int i = 0; i < dq.size(); ++i)
                {
                    if (i == dq.size() - 1) cout << dq[i];
                    else cout << dq[i] << ',';
                }
                cout << "]\n";
            }
        }

    }

}
