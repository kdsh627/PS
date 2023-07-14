#include <iostream>

using namespace std;

class Namelist{
    public:
        int age;
        string name;
        void Show(){
            cout<<age<<' '<<name<<'\n'; 
        }
};

Namelist *tmp=new Namelist[100000];

void merge(Namelist arr[], int left, int right, int mid){
    int k, L, M;
    k=left;
    L=left;
    M=mid+1;
    while(L<=mid && M<=right){
        tmp[k++] = arr[L].age <= arr[M].age ? arr[L++] : arr[M++];
    }
    if(L>mid){
        while(M<=right) tmp[k++] = arr[M++];
    }
    else{
        while(L<=mid) tmp[k++] = arr[L++];
    }
    for(int i=left; i<=right; i++){
        arr[i]=tmp[i];
    }
}

void mergesort(Namelist arr[], int left, int right){
    if(left==right) return;
    int mid=(left+right)/2;
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    merge(arr, left, right, mid);
}

int main()
{   
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin>>N;
    Namelist arr[N];
    for(int i=0; i<N; i++){
        cin>>arr[i].age>>arr[i].name;
    }
    mergesort(arr, 0, N-1);
    for(int i=0; i<N; i++){
        arr[i].Show();
    }
    delete[] tmp;
    return 0;
}