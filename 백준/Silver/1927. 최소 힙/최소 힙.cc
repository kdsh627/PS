#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> arr;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int N, a;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a;
        if(a==0){
            if(arr.empty()) cout<<"0\n";
            else{
                cout<<arr.top()<<'\n';
                arr.pop();
            }
        }
        else arr.push(a);
    }

    return 0;
}