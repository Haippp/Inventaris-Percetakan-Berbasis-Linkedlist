# Deskripsi
Ini merupakan sebuah repository untuk memenuhi tugas yang diberikan oleh Pak Ade dalam mata kuliah basis data, Dalam hal ini kami membuat sebuah sistem inventaris yang berbasis linked list singly. Kami beranggotakan:
1. [Hipni](https://github.com/Haippp) (C030324071)
2. [Dzaki Ahmad Andreaz](https://github.com/Yellowdudee) (C030324115)
3. [Rizky Satrio Wicaksono](https://github.com/orennn12) (C030324107)

## Studi Kasus
Ada sebuah permintaan yang di ajukan oleh klien untuk membuat sebuah sistem inventaris untuk usaha cetaknya. Dalam inventaris tersebut harus berisi nama barang, Spesifikasi barang, dan Stok. Juga sistem tersebut harus memenuhi standar CRUD(Create Read Update Delete).

# Dokumentasi Program
Di bawah ini merupakan sebuah dokummentasi penjelasan satu per satu prosedur yang telah di buat agar, bisa di pahami bagaimana cara kerja dari prosedur yang ada.

## Tambah Item
Prosedur tambah item menggunakan operator `new` yang berfungi untuk mengalokasikan memori secara dinamis(di heap) dan mengembalikan pointer ke memori tersebut.
```cpp
    if(head == nullptr) {
        head = itemBaru;
        return;
    } 
```
Pada prosedur ini juga dilengkapi gerbang logika dimana jika pointer head kosong maka akan otomatis diisi dengan pointer head dari item baru. Akan tetapi jika pointer head nya tidak kosong maka otomatis mencari pointer selanjutnya yang kosong yaitu pointer yang terakhir.
```cpp
    printing_item* temp = head;
    while(temp->selanjutnya != nullptr) {
        temp = temp->selanjutnya;
    }

    temp->selanjutnya = itemBaru;
```

## Sisipkan item
Fungsi sisipkan_item adalah menempatkan node baru di awal linked list.
```cpp
    printing_item* hanyar = new printing_item{nm, desk, stok, head};
    head = hanyar;
```
Node baru akan menunjuk ke node sebelumnya (head). Lalu head diperbarui ke node baru.

## Update item
Fungsi ini digunakan untuk mengubah data dari sebuah item dalam linked list berdasarkan nama item yang dimasukkan pengguna. Data yang dapat diubah meliputi nama, deskripsi dan stok.
```cpp
    void update_item(printing_item* head, string nm)
```
head: pointer ke node pertama dari linked list.
nm  : nama item yang ingin dicari dan diperbarui.

Secara keseluruhan fungsi ini akan mengubah data dari item yang sudah ada dengan menampilkan tampilan menu berisikan opsi bagian item yang ingin diubah oleh user.

## Hapus Item
Prosedur ini berfungsi untuk menghapus item menggunakan operator `delete`, operator `delete` operator di C++ yang digunakan untuk menghapus (meng-dealokasi) memori yang sebelumnya dialokasikan dengan `new`. Dan tahapan dari prosedur ini sebagai berikut:
1. Mengecek apakah head linked list terisi atau tidak. Jika terisi maka lanjutkan proses, jika tidak hapus proses. 
```cpp
    if (head == nullptr) {
        cout << "Daftar Kosong." << endl;
        return;
    }
```
2. Mengecek nama item yang di ingin dihapus apakah sesuai dengan item yang sudah ada, jika ada maka langsung hapus.
```cpp
    printing_item* temp = head;
    if (temp->nama == nm){
        head = temp->selanjutnya;
        delete temp;
        cout << "Item Dihapus" << endl;
        return;
    }
``` 
3. Kalau nama paling awal tidak sesuai dengan nama yang ingin di hapus, maka akan melakukan sebuah perulangan untuk mengecek nilai dari node node selanjutnya. Jika cocok, hapus node.
```cpp
while (temp != nullptr){ // 3. Jika tidak, lanjutkan iterasi
        if (temp->nama == nm){ // 1. Cek Nama
            sebelum->selanjutnya = temp->selanjutnya;
            delete temp; // 2. Jika cocok, hapus node
            cout << "\n[!] Item Dihapus\n" << endl;
            return;
        }
        sebelum = temp;
        temp = temp->selanjutnya;
}
```
4. Jika tidak, lanjutkan iterasi sampai menemukan hasil yang sesuai. Akan tetapi jika sama sekali tidak ada yang seusai maka akan tampil output : `Item Tidak Ada`
```cpp
    cout << "Item Tidak Ada" << endl;
```

## Tampilkan Item
Prosedur tampilkan item berfungsi untuk menampilkan item yang telah di tambahkan sebelumnya, Cara kerja dari item ini pertama dia melakukan pengecekan apakah head berisi alamat atau tidak.
```cpp
    if(head == nullptr) {
        cout << "Tidak ada item dalam inventaris." << endl;
        return;
    }
```
Jika alamat kosong maka akan menampilkan output : `Tidak ada item dalam inventaris` dan prosedur otomatis terhenti. Akan tetapi jika ada alamat maka program akan terus berjalan sampai alamat terakhir itu `nullptr` atau tidak ada pointer atau alamat.