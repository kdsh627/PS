#include <iostream>

using namespace std;

int *tmp=new int[100001];

void merge(int arr[], int left, int right, int mid){
    int K, M, L;
    K=left;
    M=mid+1;
    L=left;
    
    while(L<=mid && M<=right) tmp[K++]=arr[L] < arr[M] ? arr[L++] : arr[M++];
    if(L>mid) while(M<=right) tmp[K++] = arr[M++];
    else if(M>right) while(L<=mid) tmp[K++] = arr[L++];
    for(int i=left; i<=right; i++) arr[i]=tmp[i];
}

void mergesort(int arr[], int left, int right){
    if(left==right) return;
    int mid=(left+right)/2;
    
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    merge(arr, left, right, mid);
}
void binaryserch(int arr[],int n, int left, int right){
    if(left==right) return;
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(arr[mid]==n) {
            cout<<"1\n";
            return;
        }
        else if(arr[mid]>n) right=mid-1;
        else left=mid+1;
    }
    cout<<"0\n";
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N, M, a;
    cin>>N;
    int *A=new int[N];
    for(int i=0; i<N; i++){
        cin>>a;
        A[i]=a;
    }
    mergesort(A, 0, N-1);
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>a;
        binaryserch(A, a, 0, N-1);
    }
    return 0;
}