#include <iostream>

using namespace std;

struct node{
    int data;
    node* nextnode;
};

class CircleList{
    private:
        node* head;
    public:
        CircleList(){
            head=NULL;
        }
        void addfrontnode(int n){
            node* tmp=new node;
            tmp->data=n;
            
            if(head==NULL){
                head=tmp;
                tmp->nextnode=head;
            }
            else{
                tmp->nextnode=head->nextnode;
                head->nextnode=tmp;
            }
        }
        void addnode(int n){
            node* tmp=new node;
            tmp->data=n;
            
            if(head==NULL){
                head=tmp;
                tmp->nextnode=head;
            }
            else{
                tmp->nextnode=head->nextnode;
                head->nextnode=tmp;
                head=tmp;
            }
        }
        node* deletenode(node* prevnode){
            if(prevnode->nextnode==prevnode) {
                delete prevnode;
                return NULL;
            }
            else{
                node* tmp=new node;
                tmp=prevnode->nextnode;
                prevnode->nextnode=tmp->nextnode;
            
                delete tmp;
                return prevnode->nextnode;
            }
        }
        void show(node* temp, int n){
            if(temp==NULL){
                cout<<'>';
            }
            else{
                cout<<getnode(temp, n)->data;
                temp=deletenode(getnode(temp,n-1));
                if(temp!=NULL) cout<<", ";
                show(temp, n);
            }
        }
        node* gethead(){
            return head;
        }
        node* getnode(node* node1, int n){
            node* tmp=new node;
            tmp=node1;
            if(n<=0) return head;
            else{
                for(int i=0; i<n-1; i++){
                    tmp=tmp->nextnode;
                }
                return tmp;
            }
        }
};

int main()
{
    CircleList a;
    int N, K;
    cin>>N>>K;
    for(int i=1; i<=N; i++) a.addnode(i);
    cout<<'<';
    a.show(a.gethead()->nextnode, K);

    return 0;
}