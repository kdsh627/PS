#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int N, a;
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>a;
        arr.push_back(a);
    }
    vector<int> arr2(arr);
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for(const auto a : arr2) {
        cout<<lower_bound(arr.begin(), arr.end(), a)-arr.begin()<<' ';
    }
    return 0;
}