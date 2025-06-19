#include <iostream>
using namespace std;

struct printing_item
{
    string nama;
    string deskripsi;
    int stok;
    printing_item *selanjutnya;
};

// Di kerjakan oleh Hipni
void tambah_item(printing_item* head, string nm, string desk, int stok){
}

// Di kerjakan oleh Dzaki
void sisipkan_item(printing_item* head, string nm, string desk, int stok){
printing_item* hanyar = new printing_item{nm, desk, stok, head};
head = hanyar;
}

// Di kerjakan oleh Dzaki
void update_item(printing_item* head, string nm){
}

// Dikerjakan oleh Rio
void hapus_item(printing_item* head, string nm){
    if (head == nullptr) {
        cout << "Daftar Kosong." << endl;
        return;
    }

    printing_item* temp = head;
    if (temp->nama == nm){
        head = temp->selanjutnya;
        delete temp;
        cout << "Item Dihapus" << endl;
        return;
    }

    printing_item* sebelum = temp;
    temp = temp->selanjutnya;

    while (temp != nullptr){
        if (temp->nama == nm){
            sebelum->selanjutnya = temp->selanjutnya;
            delete temp;
            cout << "Item Dihapus" << endl;
            return;
        }
        sebelum = temp;
        temp = temp->selanjutnya;
    }

    cout << "Item Tidak Ada" << endl;
    
}

// Di kerjakan oleh Hipni
void tampilkan_item(printing_item* head){
}

int main(){
    

    return 0;
}