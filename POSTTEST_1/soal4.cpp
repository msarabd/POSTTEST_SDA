#include <iostream>
using namespace std;

void tukar(int *aPtr, int *bPtr){
    int tampung = *aPtr;

    *aPtr = *bPtr;
    *bPtr = tampung;
}

int main(){
    int nilai_1;
    int nilai_2;

    cout << "===============================================" << endl;
    cout << "                 SOAL NOMOR 4              " << endl;
    cout << "===============================================\n" << endl;
    cout << "Masukkan nilai pertama: ";
    cin >> nilai_1;
    cout << "Masukkan nilai kedua: ";
    cin >> nilai_2;
    
    cout << "\n==============" << endl;
    cout << "   SEBELUM    " << endl;
    cout << "==============" << endl;
    cout << "Nilai 1: " << nilai_1 << endl;
    cout << "Nilai 2: " << nilai_2 << endl;
    
    tukar(&nilai_1, &nilai_2);
    
    cout << "\n==============" << endl;
    cout << "   SESUDAH    " << endl;
    cout << "==============" << endl;
    cout << "Nilai 1: " << nilai_1 << endl;
    cout << "Nilai 2: " << nilai_2 << endl;

    return 0;
}