#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
    float ipk;
};

int main(){
    Mahasiswa mhs[5];
    int index_max = 0;

    cout << "================================" << endl;
    cout << "         SOAL NOMOR 2           " << endl;
    cout << "================================\n" << endl;

    for (int i = 0; i < 5; i++){
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Masukkan nama: ";
        getline(cin, mhs[i].nama);
        cout << "Masukkan NIM: ";
        getline(cin, mhs[i].nim);
        cout << "Masukkan IPK: ";
        cin >> mhs[i].ipk;

        cin.ignore();
        cout << endl;
    }

    for (int i = 1; i < 5; i++){
        if (mhs[i].ipk > mhs[index_max].ipk){
            index_max = i;
        }
    }

    cout << "Mahasiswa dengan ipk tertinggi: " << mhs[index_max].nama << " (" << mhs[index_max].ipk << ")" << endl;
    return 0;
}