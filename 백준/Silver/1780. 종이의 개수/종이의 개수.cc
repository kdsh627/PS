#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr[(int)pow(3,7)];
int dt[3]={0,0,0};
void division(int x, int y, int N){
    int tmp=arr[x][y];
    bool discri=true;
    for(int i=x; i<x+N; i++){
        for(int j=y; j<y+N; j++){
            if(tmp!=arr[i][j]) {
                discri=false;
                break;
            }
            tmp=arr[i][j];
        }
        if(!discri) break;
    }
    if(discri) dt[tmp+1]++;
    else for(int i=0; i<N; i+=N/3) for(int j=0; j<N; j+=N/3) division(x+i, y+j, N/3);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int N, a;
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++){
            cin>>a;
            arr[i].push_back(a);
        }
    }
    division(0, 0, N);
    for(int i : dt) cout<<i<<'\n';
    return 0;
}