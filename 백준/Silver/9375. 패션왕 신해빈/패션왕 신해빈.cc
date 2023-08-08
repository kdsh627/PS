#include <iostream>
#include <map>

using namespace std;
map<string, int>arr;

int main()
{
    int T, n;
    string a,b;
    cin>>T;
    for(int i=0; i<T; i++){
        int result=1;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>a>>b;
            if(arr.find(b)!=arr.end()) arr[b]+=1;
            else arr.insert({b, 1});
        }
        for(auto iter=arr.begin(); iter!=arr.end(); iter++) result*=(iter->second)+1;
        cout<<result-1<<'\n';
        arr.clear();
    }

    return 0;
}