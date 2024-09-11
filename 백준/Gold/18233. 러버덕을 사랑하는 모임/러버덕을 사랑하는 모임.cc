#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Gift
{
    int x;
    int y;
};

unordered_map<int, Gift> um;
vector<int> ind;
vector<int> result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, P, E;
    cin >> N >> P >> E;

    ind.resize(N, 0);
    result.resize(N, 0);

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        um[i] = { x, y };
    }

    for (int i = 1; i <= min(P, N); ++i)
    {
        ind[N-i] = 1;
    }

    bool isPossible = false;

    do
    {
        if (P > N) break;
        int valueX = 0;
        int valueY = 0;
        for (int i = 0; i < ind.size(); i++)
        {
            if (ind[i] == 1)
            {
                valueX = valueX + um[i].x;
                valueY = valueY + um[i].y;
            }
        }

        if (valueX <= E && E <= valueY)
        {
            isPossible = true;
            int MaxValue = valueY;
            for (int i = 0; i < ind.size(); i++)
            {
                if (ind[i] == 1)
                {
                    result[i] = um[i].y;
                }
            }


            for (int i = 0; i < ind.size(); i++)
            {
                if (ind[i] == 1)
                {
                    //가장 y값을 하나 빼고 해당 범위의 하한선을 더함
                    MaxValue = MaxValue - um[i].y + um[i].x;
                    if (MaxValue > E)
                    {
                        //그럼에도 E보다 크다면
                        result[i] = um[i].x;
                    }
                    else
                    {
                        //그 값이 E보다 작다면 보정해준다
                        result[i] = um[i].x + E - MaxValue;
                        break;
                    }
                }
            }

            break;
        }
    } while (next_permutation(ind.begin(), ind.end()));

    if (!isPossible) cout << "-1";
    else
    {
        for (int i : result)
        {
            cout << i << ' ';
        }
    }
}
