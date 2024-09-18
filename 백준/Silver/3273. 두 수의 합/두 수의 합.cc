#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }

    int tmp;
    cin >> tmp;

    sort(arr.begin(), arr.end());

    int result = 0;
    int start = 0;
    int end = n-1;

    while (start < end)
    {
        int x = arr[start] + arr[end];
        if (x < tmp)
        {
            start++;
        }
        else if(x > tmp)
        {
            end--;
        }
        else
        {
            start++;
            result++;
        }
    }


    cout << result;
}
