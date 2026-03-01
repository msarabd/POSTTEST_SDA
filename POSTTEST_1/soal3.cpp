#include <iostream>
using namespace std;

void reverseArray(int *arr, int n){
    int tampung;
    
    for (int i = 0; i < n / 2; i++){
        tampung = *(arr + i);
        *(arr + i) =  *(arr + n - (i + 1));
        *(arr + n - (i + 1)) = tampung;   
    }
}

int main(){
    int data[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = sizeof(data) / sizeof(int);
    int *ptr = data;

    cout << "===============================================" << endl;
    cout << "                 SOAL NOMOR 3              " << endl;
    cout << "===============================================\n" << endl;
    cout << "Array sebelum reverse: [";
    for (int i = 0; i < n; i++){
        if (i < n - 1){
            cout << *(ptr + i) << ", ";

        } else if (i == n - 1){
            cout << *(ptr + i) << "]" << endl;

        }
    }
    
    for (int i = 0; i < n; i++){
        cout << "Alamat data[" << i << "]: " << (ptr + i) << endl;
    }
    
    reverseArray(data, n);
    
    cout << "\nArray setelah reverse: [";
    for (int i = 0; i < n; i++){
        if (i < n - 1){
            cout << *(ptr + i) << ", ";
            
        } else if (i == n - 1){
            cout << *(ptr + i) << "]" << endl;
            
        }
    }

    for (int i = 0; i < n; i++){
        cout << "Alamat data[" << i << "]: " << (ptr + i) << endl;
    }

    return 0;
}