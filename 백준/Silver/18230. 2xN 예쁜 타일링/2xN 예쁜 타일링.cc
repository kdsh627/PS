#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> oneArr;
vector<int> twoArr;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;//2*1이 A개 2*2가 B개로 2*N을 표현

    //예쁨 입력
    for (int i = 0; i < A; ++i)
    {
        int a;
        cin >> a;
        oneArr.emplace_back(a);
    }
    for (int i = 0; i < B; ++i)
    {
        int b;
        cin >> b;
        twoArr.emplace_back(b);
    }

    sort(oneArr.begin(), oneArr.end(), greater<int>());
    sort(twoArr.begin(), twoArr.end(), greater<int>());

    long long int result = 0;
    int one = 0;
    int two = 0;
    int oneInd = 0;
    int twoInd = 0;

    if (N % 2 == 1) result += oneArr[oneInd++];

    for (int i = 1; i <= N; ++i)
    {
        if (oneInd  < oneArr.size())
        {
            one = oneArr[oneInd];
        }
        else
        {
            one = 0;
        }

        if (i % 2 == 0)
        {
            if (oneInd + 1 < oneArr.size())
            {
                one += oneArr[oneInd + 1];
            }
            else
            {
                one = 0;
            }

            if (twoInd < twoArr.size())
            {
                two = twoArr[twoInd];
            }
            else
            {
                two = 0;
            }

            if (one > two)
            {
                result += one;
                oneInd += 2;
            }
            else
            {
                result += two;
                twoInd++;
            }
        }
    }

    cout << result;
}
