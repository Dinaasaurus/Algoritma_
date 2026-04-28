#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;
int pil;
string dataBaru, dataHapus;

void init();
int isEmpty();
void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main() {
    init();
    
    do {
        cout<<"\nSingle Linked List Circular (SLLC)"<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan Data"<<endl;
        cout<<"6. Hapus Semua Elemen"<<endl;
        cout<<"7. Cari Data"<<endl;
        cout<<"8. Hapus Setiap Data Tertentu"<<endl;
        cout<<"9. Sisipkan Node/Data Baru Sebelum Data Tertentu"<<endl;
        cout<<"10. Sisipkan Node/Data Baru Setelah Data Tertentu"<<endl;
        cout<<"11. Quit"<<endl;
        cout<<"Pilihan : ";
        cin>>pil;

        cout<<"----------------------------------"<<endl;

        switch(pil) {
            case 1: tambahDepan(); break;
            case 2: tambahBelakang(); break;
            case 3: 
                hapusDepan(); 
                if(dataHapus != "") cout<<"Data \""<<dataHapus<<"\" yang berada di depan telah berhasil dihapus.\n";
                break;
            case 4: 
                hapusBelakang(); 
                if(dataHapus != "") cout<<"Data \""<<dataHapus<<"\" yang berada di belakang telah berhasil dihapus.\n";
                break;
            case 5: tampilkan(); break;
            case 6: reset(); break;
            case 7: cariData(); break;
            case 8: hapusData(); break;
            case 9: sisipkanSebelum(); break;
            case 10: sisipkanSetelah(); break;
            default:
                cout<<"TERIMA KASIH\n";
                cout<<"Program was made by Radina Yasmin (2510817220001)\n";
                break;
        }
        cout<<"==================================\n";
    } while (pil < 11);

    return 0;
}

    void init() {
        head = NULL;
        tail = NULL;    
    }

    int isEmpty() {
        if (head == NULL) return 1;
        else return 0;
    }

    void tambahDepan() {
        cout<<"Masukkan data: ";
        TNode *baru = new TNode;
        cin>>dataBaru;
        baru->data = dataBaru;
        baru->next = baru;

        if (isEmpty() == 1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
        cout<<"Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian depan.\n";
    }

    void tambahBelakang() {
        cout<<"Masukkan data: ";
        TNode *baru = new TNode;
        cin>>dataBaru;
        baru->data = dataBaru;
        baru->next = baru;

        if (isEmpty() == 1) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
            tail->next = head;
        }
        cout<<"Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian belakang.\n";
    }

    void hapusDepan() {
        dataHapus = "";
        if (isEmpty() == 0) {
            TNode *hapus = head;
            dataHapus = hapus->data;

        if (head != tail) {
            head = head->next;
            tail->next = head;
        } else {
            init();
        }
        delete hapus;
        } else cout<<"Tidak terdapat data pada Linked List.\n";
    }
        
    void hapusBelakang() {
        dataHapus = "";
        if (isEmpty() == 0) {
            TNode *hapus = tail;
            dataHapus = hapus->data;

        if (head != tail) {
            TNode *newTail = head;
            while (newTail->next != tail) {
                newTail = newTail->next;
            }
            tail = newTail;
            tail->next = head;
        } else {
            init();
        }
        delete hapus;
        } else cout<<"Tidak terdapat data pada Linked List.\n";
    }

    void tampilkan() {
        if (isEmpty() == 0) {
            TNode *bantu = head;
            cout<<"Data saat ini: ";
        do {
            cout<<bantu->data<<" ";
            bantu = bantu->next;
        } while (bantu != head);
            cout<<endl;
        } else cout<<"Tidak terdapat data pada Linked List.\n";
    }

    void reset() {
        if (isEmpty() == 0) {
            TNode *bantu = head, *hapus;
        do {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        } while (bantu != head);
            init();
            cout<<"Seluruh elemen pada Linked List telah dibersihkan.\n";
        } else cout<<"Tidak terdapat data pada Linked List.\n";
    }

    void cariData() {
        if (isEmpty() == 0) {
            string cari;
            cout<<"Masukkan data yang ingin dicari: ";
            cin>>cari;

            TNode *bantu = head;
            bool apaDitemukan = false;

        do {
            if (cari == bantu->data) {
                apaDitemukan = true;
                break; 
            }
            bantu = bantu->next;
        } while (bantu != head);

        if (apaDitemukan) {
            cout<<"Setiap data yang berada di dalam tanda kurung siku ([...]) merupakan data yang anda cari\n";
            cout<<"Linked List: ";
            TNode *bantuTampilkan = head;
            do {
                if (cari == bantuTampilkan->data) cout<<"["<<bantuTampilkan->data<<"] ";
                else cout<<bantuTampilkan->data<<" ";
                bantuTampilkan = bantuTampilkan->next;
            } while (bantuTampilkan != head);
            cout<<endl;
        } else cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List.\n";
    } else cout<<"Tidak terdapat data pada Linked List.\n";
}

void hapusData() {
    if (isEmpty() == 0) {
        string cari;
        cout<<"Masukkan data yang ingin dihapus: ";
        cin>>cari;

        int count = 0;
        TNode *bantu = head;
        
        do {
            if (bantu->data == cari) count++;
            bantu = bantu->next;
        } while (bantu != head);

        if (count > 0) {
            for (int i = 0; i < count; i++) {
                bantu = head;
                TNode *sebelum = tail;
                do {
                    if (bantu->data == cari) {
                        if (bantu == head) hapusDepan();
                        else if (bantu == tail) hapusBelakang();
                        else {
                            sebelum->next = bantu->next;
                            delete bantu;
                        }
                        break; 
                    }
                    sebelum = bantu;
                    bantu = bantu->next;
                } while (bantu != head);
            }
            cout<<"Setiap data \""<<cari<<"\" yang terdapat pada Linked List telah dihapus.\n";
        } else cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List.\n";
    } else cout<<"Tidak terdapat data pada Linked List.\n";
}

void sisipkanSebelum() {
    if (isEmpty() == 0) {
        string nextData;
        cout<<"Sisipkan data baru sebelum data : ";
        cin>>nextData;

        TNode *bantu = head, *sebelum = tail;
        bool apaAda = false;

        do {
            if (nextData == bantu->data) {
                apaAda = true;
                break;
            }
            sebelum = bantu;
            bantu = bantu->next;
        } while (bantu != head);

        if (apaAda) {
            cout<<"Masukkan data yang ingin ditambahkan: ";
            cin>>dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;
            sebelum->next = baru;

            if (bantu == head) head = baru;
            
            cout<<"Data \""<<dataBaru<<"\" berhasil disisipkan sebelum data \""<<nextData<<"\".\n";
        } else cout<<"Tidak terdapat data \""<<nextData<<"\" pada Linked List.\n";
    } else cout<<"Tidak terdapat data pada Linked List.\n";
}

void sisipkanSetelah() {
    if (isEmpty() == 0) {
        string prevData;
        cout<<"Sisipkan data baru setelah data: ";
        cin>>prevData;

        TNode *bantu = head;
        bool apaAda = false;

        do {
            if (prevData == bantu->data) {
                apaAda = true;
                break;
            }
            bantu = bantu->next;
        } while (bantu != head);

        if (apaAda) {
            cout<<"Masukkan data yang ingin ditambahkan: ";
            cin>>dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;

            if (bantu == tail) tail = baru;

            cout<<"Data \""<<dataBaru<<"\" berhasil disisipkan setelah data \""<<prevData<<"\".\n";
        } else cout<<"Tidak terdapat data \""<<prevData<<"\" pada Linked List.\n";
    } else cout<<"Tidak terdapat data pada Linked List.\n";
}