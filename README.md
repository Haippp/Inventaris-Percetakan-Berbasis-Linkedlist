# Deskripsi
Ini merupakan sebuah repository untuk memenuhi tugas yang diberikan oleh Pak Ade dalam mata kuliah basis data, Dalam hal ini kami membuat sebuah sistem inventaris yang berbasis linked list singly. Kami beranggotakan:
1. Hipni (C030324071)
2. Dzaki Ahmad Andreaz (C030324115)
3. Rizky Satrio Wicaksono (C030324107)

## Studi Kasus
Ada sebuah permintaan yang di ajukan oleh klien untuk membuat sebuah sistem inventaris untuk usaha cetaknya. Dalam inventaris tersebut harus berisi nama barang, Spesifikasi barang, dan Stok. Juga sistem tersebut harus memenuhi standar CRUD(Create Read Update Delete).

# Dokumentasi Program

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

## Tampilkan Item
Prosedur tampilkan item berfungsi untuk menampilkan item yang telah di tambahkan sebelumnya, Cara kerja dari item ini pertama dia melakukan pengecekan apakah head berisi alamat atau tidak.
```cpp
    if(head == nullptr) {
        cout << "Tidak ada item dalam inventaris." << endl;
        return;
    }
```
Jika alamat kosong maka akan menampilkan output : `Tidak ada item dalam inventaris` dan prosedur otomatis terhenti. Akan tetapi jika ada alamat maka program akan terus berjalan sampai alamat terakhir itu `nullptr` atau tidak ada pointer atau alamat.