#include <iostream>

using namespace std;

class Point{
    public:
        int x;
        int y;
        void Init() {
            cin>>x>>y;
        }
        void Show(){
            cout<<x<<' '<<y<<'\n';
        }
};
Point *tmp=new Point[100000];

void merge(Point point[], int left, int right, int mid);

void mergesort(Point point[], int left, int right){
    if(left==right) return;
    int mid=(left+right)/2;
    mergesort(point, left, mid);
    mergesort(point, mid+1, right);
    merge(point, left, right, mid);
}

void merge(Point point[], int left, int right, int mid){
    int L, K, M;
    L=left;
    K=left;
    M=mid+1;
    while(L<=mid && M<=right){
        tmp[K++]=point[L].y == point[M].y ? (point[L].x <= point[M].x ? point[L++] : point[M++]) : (point[L].y < point[M].y ? point[L++] : point[M++]);
    }
    if(L>mid){
        while(M<=right) tmp[K++]=point[M++];
    }
    else{
        while(L<=mid) tmp[K++]=point[L++];
    }
    for(int i=left; i<=right; i++){
        point[i]=tmp[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int N;
    cin>>N;
    Point point[N];
    for(int i=0; i<N; i++){
        point[i].Init();
    }
    mergesort(point, 0, N-1);
    for(int i=0; i<N; i++){
        point[i].Show();
    }
    delete[] tmp;
    return 0;
}