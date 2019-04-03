#include <iostream>

using namespace std;

struct TNode{
    int data;
    TNode *next;
};

TNode *head, *tail;

void init(){
    head=NULL;
    tail=NULL;
}

int isEmpty(){
    if(tail==NULL){
		return 1;
    }else{
        return 0;
    }
}
// =====================================Task 1
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
// =====================================Task 2
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
    cout<<"Input berhasil \n";
}
// =====================================Task 3
void hapusDepan(){
	TNode *hapus;
	if (isEmpty()==0){
		hapus = head;
		head->data;
		if(head != tail){
			hapus = head;
			head = head->next;
			tail->next = head;
			delete hapus;
		}else{
			head=NULL;
			tail=NULL;
		}
		cout<<"\nTerhapus\n";
	} else cout<<"\nNode Masih Kosong\n";
}
// =====================================Task 4
void hapusBelakang(){
	TNode *hapus,*help;
	if (isEmpty()==0){
		if(head == tail){
			tail->data;
			head = NULL;
			tail = NULL;
		}else{
			help = head;
			while(help->next != tail){
				help = help->next;
			}
			hapus = tail;
			tail = help;
			hapus->data;
			tail->next = head;
			delete hapus;
		}
		cout<<"\nTerhapus\n";
	} else cout<<"\nNode Masih Kosong\n";
}
// =====================================Task 5
void tambah_pos(int pos, int input){
	if(isEmpty()==0){
		TNode *cur = new TNode;
		TNode *tmp = new TNode;
		TNode *baru = new TNode;
		cur = head;
		for(int i=1;i<pos;i++){
			tmp = cur;
			cur = cur->next;
		}
		baru->data = input;
		tmp->next = baru;
		baru->next = cur;
		
		cout<<"Input berhasil \n";
	}else
		cout << "Kosong" ;
}

// =====================================Task 6
void delete_position(int pos)
  {
	if(isEmpty()==0){
	    TNode *cur=new TNode;
   		TNode *previous=new TNode;
   		cur=head;
  		 for(int i=1;i<pos;i++)
  		 {
    	previous=cur;
   		cur=cur->next;
   		}
   		previous->next=cur->next;
  		cout<<" berhasil dihapus \n";}

	else
		cout << "gagal" ;
	
}

int nama_menu();

int main()
{	
	int menu,val,pos;
	char lagi = 'y';
	do{
		menu = nama_menu();
		cin.ignore();
		switch(menu){
			case 1:
					cout << "Masukan Angka : ";cin>>val;
					tambahDepan(val);
					break;
			case 2:
					cout << "Masukan Angka : ";cin>>val;
					tambahBelakang(val);
					break;
			case 3:
					cout << "Ingin Menambah Node di posisi berapa : ";cin>>pos;
					cout << "Masukan Angka : ";cin>>val;
					tambah_pos(pos,val);
					break;
			case 4:
					cout << "Akan Menghapus Node Paling Depan";
					hapusDepan();
					break;
			case 5:
					cout << "Akan Menghapus Node Paling Belakang";
					hapusBelakang();
					break;
			case 6:
					cout << "Ingin Menghapus Node di posisi berapa : ";cin>>pos;
					//hapus_pos(pos);
					break;
			case 7:
					//show();
					break;
			default:
					cout <<"\t\nPilihan tidak ada";
					cin.get();
					system("cls");
					break;
		}cout << endl << "Kembali Ke Menu ?(y/n) ";cin>>lagi;
		system("cls");
	}while(lagi=='y');
		cin.get();
		return 0;
}

int nama_menu(){
	cout<<"https://github.com/BrondoL/Single-LinkedList"<<endl;
	cout<<"==========================================================="<<endl;
	cout<<"DAFTAR ANGGOTA KELOMPOK : "<<endl;
	cout<<"Nama : 1. Aulia Ahmad Nabil\t (1817051074)"<<endl;
	cout<<"       2. Arbi Hidayatullah\t (1817051045)"<<endl;
	cout<<"       3. Asbiq Al Alawi\t (1817051026)"<<endl;
	cout<<"       4. Pandi Barep Arianza\t (1817051002)"<<endl;
	cout<<"==========================================================="<<endl<<endl;
	cout<<"\t\t    SINGLE LINKED LIST"<<endl;
	int menu;
	cout << "MENU : "<<endl<<endl;
	cout << "1. Tambah Node di paling depan"<<endl;
	cout << "2. Tambah Node di paling belakang"<<endl;
	cout << "3. Tambah Node di posisi tertentu"<<endl;
	cout << "4. Hapus Node di paling depan"<<endl;
	cout << "5. Hapus Node di paling belakang"<<endl;
	cout << "6. Hapus Node di posisi tertentu"<<endl;
	cout << "7. Tampilkan Semua isi Node"<<endl<<endl;
	cout << "Pilihan : "; cin >> menu;
	cout << menu;
	system("cls");
	return menu;
}
