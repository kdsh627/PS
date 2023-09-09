#include <iostream>

using namespace std;

int main()
{
    int T, N;
    long long dp[101]={0,1,1,1};
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=4; i<=N; i++){
            dp[i]=dp[i-2]+dp[i-3];
        }
        cout<<dp[N]<<'\n';
    }

    return 0;
}