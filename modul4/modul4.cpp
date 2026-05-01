#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;
int pil, menu;
string dataBaru;

void initH();
void initHT();
int isEmpty();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main() {
    bool run = true;
    while(run) {
        cout<<"\nDouble Linked List Non Circular (DLLNC)\n";
        cout<<"=======================================\n";
        cout<<"Silahkan pilih program DLLNC yang ingin dijalankan!\n";
        cout<<"1. DLLNC dengan Head\n";
        cout<<"2. DLLNC dengan Head dan Tail\n";
        cout<<"3. Quit\n";
        cout<<"Pilihan : ";
        cin>>menu;
        cout<<"---------------------------------------\n";

        if(menu == 1) {
            do {
                cout<<"\nDouble Linked List Non Circular (DLLNC) (Head)\n";
                cout<<"=======================================\n";
                cout<<"1. Tambah Depan\n";
                cout<<"2. Tambah Belakang\n";
                cout<<"3. Tampilkan Data\n";
                cout<<"4. Hapus Depan\n";
                cout<<"5. Hapus Belakang\n";
                cout<<"6. Reset\n";
                cout<<"7. Kembali ke Menu Utama\n";
                cout<<"Pilihan : ";
                cin>>pil;
                cout<<"---------------------------------------\n";
                
                switch(pil) {
                    case 1: tambahDepanH(); break;
                    case 2: tambahBelakangH(); break;
                    case 3: tampilkanH(); break;
                    case 4: hapusDepanH(); break;
                    case 5: hapusBelakangH(); break;
                    case 6: clearH(); break;
                    case 7: break;
                    default: cout<<"Pilihan tidak valid!\n";
                }
            } while (pil != 7);
        } 
        else if(menu == 2) {
            do {
                cout<<"\nDouble Linked List Non Circular (DLLNC) (Head dan Tail)\n";
                cout<<"=======================================\n";
                cout<<"1. Tambah Depan\n";
                cout<<"2. Tambah Belakang\n";
                cout<<"3. Tampilkan Data\n";
                cout<<"4. Hapus Depan\n";
                cout<<"5. Hapus Belakang\n";
                cout<<"6. Reset\n";
                cout<<"7. Kembali ke Menu Utama\n";
                cout<<"Pilihan : ";
                cin>>pil;
                cout<<"---------------------------------------\n";
                
                switch(pil) {
                    case 1: tambahDepanHT(); break;
                    case 2: tambahBelakangHT(); break;
                    case 3: tampilkanHT(); break;
                    case 4: hapusDepanHT(); break;
                    case 5: hapusBelakangHT(); break;
                    case 6: clearHT(); break;
                    case 7: break;
                    default: cout<<"Pilihan tidak valid!\n";
                }
            } while (pil != 7);
        } 
        else if(menu == 3) {
            cout<<"\nTERIMA KASIH\n";
            cout<<"Program was made by Radina Yasmin (2510817220001)\n";
            run = false;
        } 
        else {
            cout<<"Pilihan tidak valid!\n";
        }
    }
    return 0;
}

void initH() {
    head = NULL;
}

void initHT() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if(head == NULL) return 1;
    else return 0;
}

int isEmptyHT() {
    if(tail == NULL) return 1;
    else return 0;
}

void tambahDepanH() {
    cout<<"Masukkan data: ";
    cin>>dataBaru;
    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;

    if(isEmpty() == 1) {
        head = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout<<"Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian depan.\n";
}

void tambahDepanHT() {
    cout<<"Masukkan data: ";
    cin>>dataBaru;
    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;

    if(isEmptyHT() == 1) {
        head = baru;
        tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout<<"Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian depan.\n";
}

void tambahBelakangH() {
    cout<<"Masukkan data: ";
    cin>>dataBaru;
    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;

    if(isEmpty() == 1) {
        head = baru;
    } else {
        TNode *bantu = head;
        while(bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->prev = bantu;
    }
    cout<<"Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian belakang.\n";
}

void tambahBelakangHT() {
    cout<<"Masukkan data: ";
    cin>>dataBaru;
    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;

    if(isEmptyHT() == 1) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout<<"Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian belakang.\n";
}

void tampilkanH() {
    TNode *bantu = head;
    if(isEmpty() == 0) {
        while(bantu != NULL) {
            cout<<bantu->data<<" ";
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List\n";
}

void tampilkanHT() {
    TNode *bantu = head;
    if(isEmptyHT() == 0) {
        while(bantu != NULL) {
            cout<<bantu->data<<" ";
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List\n";
}

void hapusDepanH() {
    if(isEmpty() == 0) {
        TNode *hapus = head;
        string data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.\n";
    } else cout<<"Tidak terdapat data pada Linked List\n";
}

void hapusDepanHT() {
    if(isEmptyHT() == 0) {
        TNode *hapus = head;
        string data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.\n";
    } else cout<<"Tidak terdapat data pada Linked List\n";
}

void hapusBelakangH() {
    if(isEmpty() == 0) {
        TNode *hapus = head;
        while(hapus->next != NULL) {
            hapus = hapus->next;
        }
        string data = hapus->data;
        if(head->next != NULL) {
            hapus->prev->next = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di belakang telah berhasil dihapus.\n";
    } else cout<<"Tidak terdapat data pada Linked List\n";
}

void hapusBelakangHT() {
    if(isEmptyHT() == 0) {
        TNode *hapus = tail;
        string data = hapus->data;
        if(head->next != NULL) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di belakang telah berhasil dihapus.\n";
    } else cout<<"Tidak terdapat data pada Linked List\n";
}

void clearH() {
    TNode *bantu = head, *hapus;
    while(bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    initH();
    cout<<"Seluruh data pada Linked List telah dibersihkan.\n";
}

void clearHT() {
    TNode *bantu = head, *hapus;
    while(bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    initHT();
    cout<<"Seluruh data pada Linked List telah dibersihkan.\n";
}