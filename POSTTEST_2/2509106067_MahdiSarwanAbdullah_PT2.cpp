#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

#define max_hewan 200

struct hewan{
    int id_hewan;
    string nama;
    long long harga;
    string spek;
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
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    cout << "(Sorting by id berhasil)" << endl;
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
            fib2 = fib2 - fib1;
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
                swap(&arr[j], &arr[j + 1]);
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
        swap(arr[i], arr[index_min]);
    }
    
    cin.ignore();
    cout << "(Sorting by harga berhasil, silahkan lihat pada menu read)";
    cin.get();
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

    string menu_utama = R"(=============================================
|              MAU NGAPAIN CUY?             |
=============================================
| 1) Read                                   |
| 2) Create                                 |
| 3) Cari by nama hewan (Linear Search)     |
| 4) Cari by ID hewan (Fibonacci Search)    |
| 5) Urut by nama hewan (Buble Search)      |
| 6) Urut by harga (Selection Sort)         |
| 0) Keluar                                 |
=============================================
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
    
    while (token_login) {
        tampilkan(menu_utama, 0, 6);
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
        }

    }
    
    cls();
    tampilkan(akhir_program);
    return 0;
}