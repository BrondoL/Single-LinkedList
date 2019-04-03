#include <iostream>

using namespace std;

struct TNode{
    int data;
    TNode *next;
};TNode *head, *tail,*depan,*belakang;
void init(){
    head=NULL;
    tail=NULL;
    depan=NULL;
    belakang=NULL;
}

int isEmpty(){
    if(tail==NULL){
    return 1;
    }else{
        return 0;
    }
}
void insertDepan(int databaru)
{
    TNode *baru;
    baru =new TNode;
    baru->data=databaru;
    baru->next=NULL;
    if(isEmpty()==1)
    {
        head=tail=baru;
        tail->next=NULL;
    }else{
        baru->next=head;
        head=baru;
    }
    cout<<"Input berhasil";
}

void insertBelakang(int databaru){
    TNode *baru;
    baru=new TNode;
    baru->data=databaru;
    baru->next=NULL;
    if(isEmpty()==1){
        head=baru;
        tail=baru;
        tail->next=NULL;
    }else
    {
        tail->next=baru;
        tail=baru;
    }
    cout<<"\n Input berhasil"<<endl;
}


int main()
{
	

	cin.get();
	return 0;
}
