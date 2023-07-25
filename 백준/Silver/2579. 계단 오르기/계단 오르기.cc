#include <iostream>

using namespace std;

int dp[301]={0};

int main()
{
    int N;
    cin>>N;
    int stairs[N+1];
    for(int i=1; i<=N; i++) cin>>stairs[i];
    dp[1]=stairs[1];
    for(int i=2; i<=N; i++) dp[i]=max(dp[i-2]+stairs[i], stairs[i-1]+stairs[i]+dp[i-3]);
    cout<<dp[N];
    return 0;
}