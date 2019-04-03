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
void tambahDepan(int file )
{
    TNode *baru;
    baru =new TNode;
    baru->data=file;
    baru->next=NULL;
    if(isEmpty()==1)
    {
        head=tail=baru;
        tail->next=NULL;
    }else{
        baru->next=head;
        head=baru;
    }
    cout<<"Input berhasil \n";
}

void tambahBelakang(int file){
    TNode *baru;
    baru=new TNode;
    baru->data=file;
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
    cout<<" Input berhasil \n";
}

void hapusDepan(){
	TNode *hapus;
	if (isEmpty()==0){
		int h;
		hapus = head;
		h = head->data;
		if(head != tail){
			hapus = head;
			head = head->next;
			tail->next = head;
			delete hapus;
		}else{
			head=NULL;
			tail=NULL;
		}
		cout<<"Terhapus\n";
	} else cout<<"Kosong\n";
}

void hapusBelakang(){
	TNode *hapus,*help;
	if (isEmpty()==0){
		int h;
		if(head == tail){
			h = tail->data;
			head = NULL;
			tail = NULL;
		}else{
			help = head;
			while(help->next != tail){
				help = help->next;
			}
			hapus = tail;
			tail = help;
			h = hapus->data;
			tail->next = head;
			delete hapus;
		}
		cout<<"Terhapus\n";
	} else cout<<"Kosong\n";
}


int main()
{
	

	cin.get();
	return 0;
}
