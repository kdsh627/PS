#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sad;
vector<int> fun;
vector<int> ind;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    sad.resize(N, 0);
    fun.resize(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> sad[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> fun[i];
    }

    //100내에서 0이 되지않게 체력을 잃음으로 받는 최대기쁨을 구하자
    int maxFun = 0;
    for (int i = 0; i <= N; ++i)
    {
        ind.resize(N-i, 0);
        for (int index = 0; index < i; ++index)
        {
            ind.push_back(1);
        }

        do
        {
            int totalSad = 0;
            int totalFun = 0;
            for (int j = 0; j < ind.size(); j++) {
                if (ind[j] == 1) {
                    totalSad += sad[j];

                    if (totalSad >= 100) break;

                    totalFun += fun[j];
                }
            }
            maxFun = max(maxFun, totalFun);
        } while (next_permutation(ind.begin(), ind.end()));
    }

    cout << maxFun;
}
