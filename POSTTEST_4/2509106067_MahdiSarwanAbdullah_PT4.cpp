#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

#define max_hewan 100

struct hewan{
    int id_hewan;
    string nama;
    long long harga;
    string spek;
};

struct queue{
    int id_hewan;
    string nama;
    string keluhan;
};

struct stack{
    int id_hewan;
    string nama;
    string keluhan;
};

void cls() {
    #ifdef _WIN32
        system("cls");
    #else
        cout << "\033[2J\033[1;1H";
#endif
}

void tampilkan(string menu, int a, int b){
    cls();
    cout << menu;
    cout << "Pilih (" << a << "-" << b << "): "; 
};

void tampilkan(string kata){
    cout << kata << endl;
}

void swap(hewan* a, hewan* b){
    hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tampilHewan(hewan arr[], int panjang){
    cls();
    if (panjang == 0){
        cin.ignore();
        cout << "(List kosong, tidak ada data yang bisa dilihat)";
        cin.get();

    } else {
        cout << setfill('=') << setw(90) << "=" << endl;
        cout << setfill(' ');

        cout << "| " << left << setw(4)  << "NO" 
            << "| " << setw(10) << "ID"
            << "| " << setw(15) << "NAMA HEWAN" 
            << "| " << setw(15)  << "HARGA" 
            << "| " << setw(34) << "SPESIFIKASI" << " |" << endl;

        cout << setfill('-') << setw(90) << "-" << endl;
        cout << setfill(' '); 

        for (int i = 0; i < panjang; i++) {
            cout << "| " << left << setw(4) << (i + 1)
                << "| " << setw(10) << arr[i].id_hewan
                << "| " << setw(15) << arr[i].nama
                << "| Rp" << setw(13)  << arr[i].harga 
                << "| " << setw(34) << arr[i].spek << " |" << endl;
        }

        cout << setfill('=') << setw(90) << "=" << endl;
        cout << setfill(' ');
        cin.ignore();
        cout << "\n(Ketuk enter untuk kembali)";
        cin.get();
    }
}

void tambahHewan(hewan* arr, int* panjang){
    int jumlah_tambah;

    cls();
    if (*panjang == max_hewan){
        cin.ignore();
        cout << "(List penuh, tidak bisa tambah data hewan baru)";
        cin.get();

    } else{
        cout << "Mau tambah berapa hewan = ";
        cin >> jumlah_tambah;

        if (jumlah_tambah > 0){
            for (int i = 0; i < jumlah_tambah; i++){
                cin.ignore();
                cout << "\n== Masukkan hewan ke-" << i + 1 << " ==" << endl;
                cout <<  "Nama: ";
                getline(cin, (arr + *panjang)->nama);
                cout <<  "Harga: ";
                cin >> (arr + *panjang)->harga;
                cout << "Spesifikasi: ";
                cin >> (arr + *panjang)->spek;
                (arr + *panjang)->id_hewan = 7001 + *panjang;
                cout << "(Berhasil menambahkan hewan)" << endl;
                (*panjang)++;
            }
            cin.ignore();
            cout << "\n(Ketuk enter untuk kembali)";
            cin.get();
        
        } else {
            cin.ignore();
            cout << "(Maaf, input tidak valid)";
            cin.get();
        }
    }
}
                
void sortCustom(hewan arr[], int panjang){
    for (int i = 0; i < panjang - 1; i++){
        for (int j = 0; j < panjang - 1 - i; j++){
            if (arr[j].id_hewan > arr[j + 1].id_hewan){
                swap(arr+ j, arr + j + 1);
            }
        }
    }
}

void linearSearch(hewan* arr, int* panjang){
    string target;

    cls();
    cin.get();
    cout << "Masukkan nama hewan yang ingin dicari: ";
    getline(cin, target);

    for (int i = 0; i < *panjang; i++){
        cout << "\n== iterasi ke-" << i + 1 << " ==" << endl;

        if (target == (arr + i)->nama){
            cout << target  << " = " << (arr + i)->nama << endl;
            cout << "(" << target << " ditemukan pada indeks ke-" << i << ")";
            cin.get();
            return;
        } else {
            cout << target  << " != " << (arr + i)->nama << endl;
            cout << "(tidak ditemukan)" << endl;
        }
    }
    
    cout <<  "\n(" << target << " tidak ditemukan pada data petshop" << ")";
    cin.get();
}

void fibonacciSearch(hewan* arr, int* panjang){
    int fib = 1;
    int fib1 = 1;
    int fib2 = 0;
    int offset = -1;
    int index;
    int target;
    
    cls();
    sortCustom(arr, *panjang);
    cout << "Masukkan id hewan yang ingin dicari: ";
    cin >> target;

    while (true){
        if (fib >= *panjang){
            break;
        }
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int j = 1;
    while (fib > 1){
        cout << "\n== iterasi ke-" << j << " ==" << endl;
        index = min(offset + fib2, *panjang - 1);
        if ((arr + index)->id_hewan == target){
            cin.ignore();
            cout << (arr + index)->id_hewan << " = " << target << endl;
            cout << "("<< target << " ditemukan pada index ke-" << index << ")";
            cin.get();
            return;
        } else if ((arr + index)->id_hewan < target){
            cout << (arr + index)->id_hewan << " < " << target << endl;
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = index;
        } else {
            cout << (arr + index)->id_hewan << " > " << target << endl;
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }

        cout << "(tidak ditemukan)" << endl;
        j++;
    }

    cin.ignore();
    cout << "\n(" << target << " tidak ditemukan pada data hewan)"; 
    cin.get();
}

void bubleSort(hewan arr[], int panjang){
    cls();
    for (int i = 0; i < panjang - 1; i++){
        for (int j = 0; j < panjang - 1 - i; j++){
            if (arr[j].nama > arr[j + 1].nama){
                swap(arr + j, arr + j + 1);
            }
        }
    }

    cin.ignore();
    cout << "(Sorting by nama hewan berhasil, silahkan lihat pada menu read)";
    cin.get();
}

int min(hewan arr[], int batas_bawah, int panjang){
    int index_min = batas_bawah;
    for (int i = batas_bawah; i < panjang; i++){
        if (arr[i].harga < arr[index_min].harga){
            index_min = i;
        }
    }

    return index_min;
}

void selectionSort(hewan arr[], int panjang){
    int index_min;

    cls();
    for (int i = 0; i < panjang - 1; i++){
        index_min = min(arr, i, panjang);
        swap(arr + i, arr + index_min);
    }
    
    cin.ignore();
    cout << "(Sorting by harga berhasil, silahkan lihat pada menu read)";
    cin.get();
}

bool isAntrianfull(int front, int rear){
    return rear == max_hewan - 1;
}

bool isAntrianempty(int front, int rear){
    return front > rear || front == rear == -1;
}

bool isRiwayatfull(int top){
    return top == max_hewan - 1;
}

bool isRiwayatempty(int top){
    return top == -1;
}

void tampilAntrian(queue* arr, int front, int rear){
    if (isAntrianempty(front, rear)){
        cin.ignore();
        cout << "(List kosong, tidak ada data yang bisa dilihat)";
        cin.get();
    
    } else {
        cout << setfill('=') << setw(116) << "=" << endl;
        cout << setfill(' ');
    
        cout << "| " << left << setw(4)  << "NO" 
            << "| " << setw(10) << "ID"
            << "| " << setw(15) << "NAMA HEWAN"  
            << "| " << setw(77) << "KELUHAN" << " |" << endl;
    
        cout << setfill('-') << setw(116) << "-" << endl;
        cout << setfill(' '); 
        
        int j = 1;
        for (int i = front; i <= rear; i++) {
            cout << "| " << left << setw(4) << j
                << "| " << setw(10) << (arr + i)->id_hewan
                << "| " << setw(15) << (arr + i)->nama
                << "| " << setw(77) << (arr + i)->keluhan << " |" << endl;
            j++;
        }
        
        cout << setfill('=') << setw(116) << "=" << endl;
        cout << setfill(' ');
    }
}

void tampilRiwayat(stack* arr, int top){
    cls();
    if (isRiwayatempty(top)){
        cin.ignore();
        cout << "(List kosong, tidak ada data yang bisa dilihat)";
        cin.get();
    
    } else {
        cout << setfill('=') << setw(116) << "=" << endl;
        cout << setfill(' ');
    
        cout << "| " << left << setw(4)  << "NO" 
            << "| " << setw(10) << "ID"
            << "| " << setw(15) << "NAMA HEWAN"  
            << "| " << setw(77) << "KELUHAN" << " |" << endl;
    
        cout << setfill('-') << setw(116) << "-" << endl;
        cout << setfill(' '); 
        
        for (int i = top; i >= 0; i--) {
            cout << "| " << left << setw(4) << (top - i + 1)
                << "| " << setw(10) << (arr + i)->id_hewan
                << "| " << setw(15) << (arr + i)->nama
                << "| " << setw(77) << (arr + i)->keluhan << " |" << endl;
        }
        
        cout << setfill('=') << setw(116) << "=" << endl;
        cout << setfill(' ');
        cin.ignore();
        cout << "\n(Ketuk enter untuk kembali)";
        cin.get();
    }
}

void push(stack arr[], int& top, queue pasien){
    if (isRiwayatfull(top)){
        cin.ignore();
        cout << "(Riwayat penuh, tidak bisa menambah data riwayat baru)";
        cin.get();
    
    } else {
        top++;
        arr[top].id_hewan = pasien.id_hewan;
        arr[top].nama = pasien.nama;
        arr[top].keluhan = pasien.keluhan;
    }
}

void pop(stack arr[], int& top, int& front){
    cls();
    if (isRiwayatempty(top)){
        cin.ignore();
        cout << "(Riwayat kosong, tidak ada data yang bisa dihapus)";
        cin.get();
    
    } else {
        top--;
        front--;
        cin.ignore();
        cout << "(Tindakan terakhir berhasil dibatalkan)";
        cin.get();
    }
}

void peek(stack arr[], queue terdepan, int top, int front, int rear){
    cls();
    if (isRiwayatempty(top)){
        cout << "(Riwayat kosong, tidak ada data yang bisa dilihat)" << endl;
    } else {
        cout << "Tindakan terakhir: " << arr[top].nama << " (" << arr[top].id_hewan << ")" << endl;
    }

    if (isAntrianempty(front, rear)){
        cout << "(Antrian kosong, tidak ada data yang bisa dilihat)";
    } else {
        cout << "Pasien terdepan: " << terdepan.nama << " (" << terdepan.id_hewan << ")" << endl;
    }

    cin.ignore();
    cout << "\n(Ketuk enter untuk kembali)";
    cin.get();
}

void enqueue(queue arr[], int& front, int& rear){
    cls();
    if (isAntrianfull(front, rear)){
        cin.ignore();
        cout << "(Antrian penuh, tidak bisa menambah pasien baru)";
        cin.get();
    
    } else{
        rear++;
        cin.ignore();
        cout << "Nama pasien: ";
        getline(cin, arr[rear].nama);
        cout << "Keluhan: ";
        getline(cin, arr[rear].keluhan);
        arr[rear].id_hewan = 7001 + rear;
        tampilAntrian(arr, front, rear);
        cout << "\n(Ketuk enter untuk kembali)";
        cin.get();
    }
}

void dequeue(queue arr1[], stack arr2[], int& front, int& rear, int& top){
    cls();
    if (isAntrianempty(front, rear)){
        cin.ignore();
        cout << "(Antrian kosong, tidak ada pasien yang bisa dipanggil)";
        cin.get();
    
    } else {
        cout << "Pasien yang dipanggil: " << arr1[front].nama << " (" << arr1[front].id_hewan << ")" << endl;
        push(arr2, top, arr1[front]);
        front++;
        cin.ignore();
        cout << "\n(Ketuk enter untuk kembali)";
        cin.get();
    }
}

int main(){
    hewan petshop[max_hewan] = {
        {7001, "gajah", 850000000,  "Boros pakan, butuh lahan raksasa"},
        {7015, "jerapah", 600000000,  "Jantung kerja keras, susah minum"},
        {7014, "harimau", 350000000,  "Anti sosial, sangat teritorial"},
        {7008, "panda", 120000000, "Malas, hanya mau makan bambu"},
        {7013, "pinguin", 50000000,   "Sangat kaku & lambat di daratan"},
        {7009, "axolotl", 1500000,    "Air kotor sedikit langsung mati"},
        {7005, "platipus", 250000000,  "Taji kaki beracun & menyengat"},
        {7007, "koala", 400000000,  "Tidur terus, otak cenderung kecil"},
        {7010, "sloth", 75000000,   "Bergerak sangat lamban & lemah"},
        {7004, "bunglon", 2000000,    "Gampang stres & sensitif suhu"},
        {7006, "ubur-ubur", 1000000,    "Lemah, hancur dimakan predator"},
        {7011, "kuda nil", 1000000000, "Sangat agresif & suka menyerang"},
        {7003, "zebra", 90000000,   "Liar, mustahil bisa dijinakkan"},
        {7002, "narwhal", 700000000,  "Gading rapuh, mudah patah/retak"},
        {7012, "shoebill", 120000000,  "Antisosial & sangat pendiam"},
    };

    queue antrian[max_hewan] = {
        {7001, "Gajah", "Makannya sangat boros dan membutuhkan lahan yang sangat luas."},
        {7002, "Narwhal", "Gadingnya sangat rapuh dan sangat mudah patah atau retak."},
        {7003, "Zebra", "Memiliki sifat liar yang membuatnya mustahil untuk dijinakkan."},
        {7004, "Bunglon", "Sangat mudah stres dan sangat sensitif terhadap perubahan suhu."},
        {7005, "Platipus", "Memiliki taji di bagian kaki yang beracun dan menyengat."},
        {7006, "Ubur-ubur", "Struktur tubuh lemah, sangat mudah hancur saat dimangsa predator."},
        {7007, "Koala", "Terlalu banyak tidur dan memiliki ukuran otak yang cenderung kecil."},
        {7008, "Panda", "Sangat malas dan memiliki diet yang kaku karena hanya mau makan bambu."},
        {7009, "Axolotl", "Kondisi fisik sangat rentan; air kotor sedikit bisa menyebabkan kematian."},
        {7010, "Sloth", "Gerakannya sangat lamban dan memiliki pertahanan fisik yang lemah."},
        {7011, "Kuda Nil", "Sangat agresif dan memiliki kecenderungan tinggi untuk menyerang."},
        {7012, "Shoebill", "Memiliki sifat antisosial dan cenderung sangat pendiam atau pasif."},
        {7013, "Pinguin", "Memiliki gerakan yang sangat kaku dan lambat saat berada di daratan."},
        {7014, "Harimau", "Sangat antisosial dan memiliki sifat teritorial yang ekstrem."},
        {7015, "Jerapah", "Jantung harus bekerja ekstra keras, serta kesulitan saat posisi minum."},
    };

    stack riwayat[max_hewan];

    string menu_utama = R"(=============================================================
|                      MAU NGAPAIN CUY?                     |
=============================================================
| 1) Read                                                   |
| 2) Create                                                 |
| 3) Cari by nama hewan (Linear Search)                     |
| 4) Cari by ID hewan (Fibonacci Search)                    |
| 5) Urut by nama hewan (Buble Sort)                        |
| 6) Urut by harga (Selection Sort)                         |
| 7) Antrian pemeriksaan (Enqueue)                          |
| 8) Panggil pasien (Dequeue)                               |
| 9) Riwayat tindakan (Stack)                               |
| 10) Batalkan tindakan terakhir (pop)                      |
| 11) Tampilkan pasien terdepan & tindakan terakhir (peek)  |
| 0) Keluar                                                 |
=============================================================
)";

string akhir_program = R"(===================================================
 ____   _   _   _____   _____   _   _   _____   _ 
 / ___| | | | || ____||_   _|| | | || ____|| |     
 \\___ \\ | | | ||  _|    | |  | |_| ||  _|  | |   
  ___) || |_| || |___   | |  |  _  || |___ |_|     
 |____/  \\___/ |_____|  |_|  |_| |_||_____|(_)    
                                                   
            PROGRAM BERHASIL DISELESAIKAN          
===================================================)";

    int panjang_hewan = 15;
    bool token_login = true;
    int pilihan_1;
    int front = 0, rear = 14;
    int top = -1;
    
    while (token_login) {
        tampilkan(menu_utama, 0, 11);
        cin >> pilihan_1;

        switch (pilihan_1){
            case 0:
                token_login = false;
                break;
            case 1:
                tampilHewan(petshop, panjang_hewan);
                break;
            case 2:
                tambahHewan(petshop, &panjang_hewan);
                break;
            case 3:
                linearSearch(petshop, &panjang_hewan);
                break;
            case 4:
                fibonacciSearch(petshop, &panjang_hewan);
                break;
            case 5:
                bubleSort(petshop, panjang_hewan);
                break;
            case 6:
                selectionSort(petshop, panjang_hewan);
                break;
            case 7:
                enqueue(antrian, front, rear);
                break;
            case 8:
                dequeue(antrian, riwayat, front, rear, top);
                break;
            case 9:
                tampilRiwayat(riwayat, top);
                break;
            case 10:
                pop(riwayat, top, front);
                break;
            case 11:
                peek(riwayat, antrian[front], top, front, rear);
                break;
        }
    }
    
    cls();
    tampilkan(akhir_program);
    return 0;
}