#include <iostream>
using namespace std;

// Fungsi untuk mengecek bilangan prima
bool isPrima(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Fungsi untuk membalik array menggunakan pointer
void balikArray(int* arr, int ukuran) {
    int* awal = arr;
    int* akhir = arr + ukuran - 1;
    
    while (awal < akhir) {
        // Tukar nilai menggunakan pointer
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        
        awal++;
        akhir--;
    }
}

// Fungsi untuk menampilkan array menggunakan pointer
void tampilkanArray(int* arr, int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int arr[7];
    int bilPrima = 2;
    int count = 0;
    
    cout << "=== SOAL 1: Array + Pointer (NIM GENAP) ===" << endl;
    cout << "Mengisi array dengan 7 bilangan prima pertama:" << endl;
    
    // Isi array dengan bilangan prima (untuk NIM genap)
    while (count < 7) {
        if (isPrima(bilPrima)) {
            arr[count] = bilPrima;
            count++;
        }
        bilPrima++;
    }
    
    cout << "Array sebelum dibalik: ";
    tampilkanArray(arr, 7);
    
    balikArray(arr, 7);
    
    cout << "Array sesudah dibalik: ";
    tampilkanArray(arr, 7);
    
    return 0;
}