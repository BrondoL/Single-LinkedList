#include <iostream>

using namespace std;

struct TNode{
    int data;
    TNode *next;
};

TNode *head, *tail;
class list{
private:
	TNode *head=NULL, *tail=NULL;
public:
	int isEmpty(){
		if(tail==NULL){
			return 1;
		}else{
			return 0;
		}
	}
// =====================================Task 1
	void tambahDepan(int file)
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
		TNode *tmp = new TNode;
		tmp->data = file;
		if (head == NULL){
			head = tmp;
		}else{
			tail = head;
			while(tail->next != NULL){
				tail = tail->next;
			}
		tail->next = tmp;
		}
		cout<<"Input berhasil \n";
	}
// =====================================Task 3
	void hapusDepan(){
		if (isEmpty()==0){
			TNode *tmp = new TNode;
			tmp = head;
			head = head->next;
			delete tmp;
			cout<<"\nTerhapus\n";
		}else
		cout<<"\nNode Masih Kosong\n";
	}
// =====================================Task 4
	void hapusBelakang(){
		TNode *hapus,*help;
		if (isEmpty()==0){
			TNode *skrg = new TNode;
			TNode *sblm = new TNode;
			skrg = head;
			while(skrg->next != NULL){
				sblm = skrg;
				skrg = skrg->next;
			}
			tail =sblm;
			sblm->next = NULL;
			delete skrg;
			cout<<"\nTerhapus\n";
		}else
		cout<<"\nNode Masih Kosong\n";
	}
// =====================================Task 5
	void tambah_pos(int pos, int input){
		if(isEmpty()==0){
			TNode *cur = new TNode;
			TNode *tmp = new TNode;
			TNode *baru = new TNode;
			if(pos == 1){
				baru->data=input;
				baru->next=NULL;
				if(isEmpty()==1)
				{
					head=tail=baru;
					tail->next=NULL;
				}else{
					baru->next=head;
					head=baru;
				}
			}else{
				cur = head;
				for(int i=1;i<pos;i++){
					tmp = cur;
					cur = cur->next;
				}
				baru->data = input;
				tmp->next = baru;
				baru->next = cur;
			}
			cout<<"Input berhasil \n";
		}else
		cout << "Kosong" ;
	}
// =====================================Task 6
	void delete_position(int posisi)
	{
		if(isEmpty()==0){
			TNode *cur=new TNode;
			TNode *previous=new TNode;
			if(posisi == 1){
				cur = head;
				head = head->next;
				delete cur;
			}else{
				cur=head;
				for(int i=1;i<posisi;i++)
				{
					previous=cur;
					cur=cur->next;
				}
				previous->next=cur->next;
			}
			cout<<"Deleted \n";
		}
		else
			cout << "Kosong";
	}
	void show()
	{
		TNode *temp=new TNode;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"  ";
			temp=temp->next;
		}
	}
};
int nama_menu();

int main()
{
	list obj;
	int menu,val,pos;
	char lagi = 'y';
	do{
		menu = nama_menu();
		switch(menu){
			case 1:
					cout << "Masukan Angka : ";cin>>val;
					obj.tambahDepan(val);
					break;
			case 2:
					cout << "Masukan Angka : ";cin>>val;
					obj.tambahBelakang(val);
					break;
			case 3:
					cout << "Ingin Menambah Node di posisi berapa : ";cin>>pos;
					cout << "Masukan Angka : ";cin>>val;
					obj.tambah_pos(pos,val);
					break;
			case 4:
					cout << "Menghapus Node Paling Depan";
					obj.hapusDepan();
					break;
			case 5:
					cout << "Menghapus Node Paling Belakang";
					obj.hapusBelakang();
					break;
			case 6:
					cout << "Ingin Menghapus Node di posisi berapa : ";cin>>pos;
					obj.delete_position(pos);
					break;
			case 7:
					cout<<"Tampilan seluruh node : ";
					obj.show();
					break;
			case 8:
					exit(0);
			default:
					cout <<"\t\nPilihan tidak ada";
					cin.get();
					break;
		}cout << endl << "Kembali Ke Menu ? (y/n) ";cin>>lagi;
		system("clear");
	}while(lagi=='y');
		cin.get();
		return 0;
}

int nama_menu(){
	cout<<"https://github.com/BrondoL/Single-LinkedList"<<endl;
	cout<<"====================================================="<<endl;
	cout<<"DAFTAR ANGGOTA KELOMPOK : "<<endl;
	cout<<"Nama : 1. Aulia Ahmad Nabil\t (1817051074)"<<endl;
	cout<<"       2. Arbi Hidayatullah\t (1817051045)"<<endl;
	cout<<"       3. Asbiq Al Alawi\t (1817051026)"<<endl;
	cout<<"       4. Pandi Barep Arianza\t (1817051002)"<<endl;
	cout<<"====================================================="<<endl<<endl;
	cout<<"\t\t    SINGLE LINKED LIST"<<endl;
	int menu;
	cout << "MENU : "<<endl<<endl;
	cout << "1. Tambah Node di paling depan"<<endl;
	cout << "2. Tambah Node di paling belakang"<<endl;
	cout << "3. Tambah Node di posisi tertentu"<<endl;
	cout << "4. Hapus Node di paling depan"<<endl;
	cout << "5. Hapus Node di paling belakang"<<endl;
	cout << "6. Hapus Node di posisi tertentu"<<endl;
	cout << "7. Tampilkan Semua isi Node"<<endl;
	cout << "8. Exit..."<<endl<<endl;
	cout << "Pilihan : "; cin >> menu;
	system("clear");
	return menu;
}
