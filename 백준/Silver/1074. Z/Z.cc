#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int arr[15][15];
int r, c, count1=0;
void dfs(int x, int y, int N){
    if(r<x || c<y || r>x+N || c>y+N) {
        count1+=(N*N);
        return;
    }
    else if(N!=2){
        for(int i=0; i<N; i+=N/2){
            for(int j=0; j<N; j+=N/2){
                dfs(x+i, y+j, N/2);
            }
        }
    }
    else{
        for(int i=x; i<x+2; i++){
            for(int j=y; j<y+2; j++){
                if(i==r && j==c) {
                    cout<<count1;
                    exit(0);
                }
                count1++;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N>>r>>c;
    dfs(0, 0, (int)pow(2, N));
    return 0;
}