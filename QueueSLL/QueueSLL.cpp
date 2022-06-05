#include <iostream>
#include <string.h>
using namespace std;

struct Node {
	char nama[30];
	Node *next;
};

Node *head = NULL, *tail = NULL;
int count = 0, maxqueue = 4;

void enqueue() {
	if(count == maxqueue)
		cout<<"gagal enqueue, queue penuh\n";
	else {
		char namaorang[30];
		cout<<"Nama Orang : "; cin>>namaorang;
		Node *baru = new Node;
		strcpy(baru->nama, namaorang);
		
		if(head == NULL) {
			baru->next = NULL;
			head = baru;
			tail = baru;
		} else {
			baru->next = NULL;
			tail->next = baru;
			tail = baru;
		} 
		cout<<"berhasil enqueue "<<namaorang<<endl;
		++(count);
	}
}

void dequeue() {
	if(head == NULL)
		cout<<"gagal dequeue, queue kosong\n";
	else {
		cout<<"berhasil dequeue "<<head->nama<<endl;
		if(head == tail) {
			delete head;
			head = NULL;
			tail = NULL;
		} else {
			Node *bantu = head->next;
			delete head;
			head = bantu;
		} --(count);
	}
}

void print() {
	Node *bantu = head;
	while(bantu!=NULL) {
		cout<<bantu->nama<<endl;
		bantu = bantu->next;
	}
}

int main() {
	int pilih;
	do {
		cout<<"Operasi - operasi Queue :\n";
		cout<<"1. Enqueue\n";
		cout<<"2. Dequeue\n";
		cout<<"3. Keluar\n";
		cout<<"4. Print\n";
		cout<<"Pilih operasi : "; cin>>pilih;
		
		if(pilih==1) enqueue();
		if(pilih==2) dequeue();
		if(pilih==4) print();
		
	} while(pilih!=3);
	
	return 0;
}
