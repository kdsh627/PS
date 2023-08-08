#include <iostream>
#define maxsize 500001

using namespace std;

class daque{
    private:
        int data[maxsize];
        int front;
        int rear;
    public:
        daque(){
            front=maxsize-1;
            rear=maxsize-1;
        }
        void push_front(int n){
            data[front]=n;
            front=(maxsize+front-1)%maxsize;
        }
        int getfront(){
            return data[rear];
        }
        void pop_rear(){
            if(front==rear) return;
            else rear=(maxsize+rear-1)%maxsize;
        }
        void move_rear(){
            if(front==rear) return;
            else {
                push_front(data[rear]);
                pop_rear();
            }
        }
        int size(){
            return rear-front;
        }
};

int main()
{
    daque a;
    int N;
    cin>>N;
    for(int i=1; i<=N; i++) a.push_front(i);
    while(a.size()!=1){
        a.pop_rear();
        a.move_rear();
    }
    cout<<a.getfront();
    return 0;
}