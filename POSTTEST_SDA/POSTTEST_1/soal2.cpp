#include <iostream>
using namespace std;

int main() {
    int matriks[3][3];
    
    cout << "=== SOAL 2: Array 2D (NIM GENAP) ===" << endl;
    cout << "Masukkan elemen matriks 3x3:" << endl;
    
    // Input matriks
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Matriks[" << i << "][" << j << "]: ";
            cin >> matriks[i][j];
        }
    }
    
    cout << "\nMatriks yang dimasukkan:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
    
    int jumlahBarisGenap = 0;
    
    cout << "\nElemen pada baris genap (baris 0 dan 2):" << endl;
    for (int i = 0; i < 3; i += 2) {
        cout << "Baris " << i << ": ";
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
            jumlahBarisGenap += matriks[i][j];
        }
        cout << endl;
    }
    
    cout << "\nHasil perhitungan:" << endl;
    cout << "Jumlah elemen baris genap (baris 0 + baris 2): " << jumlahBarisGenap << endl;
    
    return 0;
}