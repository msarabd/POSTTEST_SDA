#include <iostream>
using namespace std;

int FindMin(int arr[], int n){
    int min = arr[0];

    for (int i = 0; i < n; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

int main(){
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int min;
    int index_min;

    cout << "==========================" << endl; 
    cout << "       SOAL NOMOR 1       " << endl; 
    cout << "==========================\n" << endl; 

    min = FindMin(A, 8);
    for (int i = 0; i < 8; i++){
        if (A[i] == min){
            index_min = i;
            break;
        }   
    }

    cout << "Nilai minimumnya: " << min << " (index ke-" << index_min << ")" << endl;
    return 0;
}

/* Tmin (best case)
Tmin = C1 + C2 + C3n + C4(n-1) + 0 + C6(n-1) + C7n + C8 + C9
= C1 + C2 + C8 + C9 + C3n + C7n + C4n - C4 + C6n - C6
= 1 + 1 + 1 + 1 + n + n + n - 1 + n - 1
= 4n + 2
Big-O => O(n)
*/ 

/* Tmax (worst case)
Tmax = C1 + C2 + C3n + C4(n-1) + C5(n-1) + C6(n-1) + C7n + C8 + C9
= C1 + C2 + C8 + C9 + C3n + C7n + C4n - C4 + C5n - C5 + C6n - C6
= 1 + 1 + 1 + 1 + n + n + n - 1 + n - 1 + n - 1
= 5n + 1
Big-O => O(n)
*/ 