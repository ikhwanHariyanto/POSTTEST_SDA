#include <iostream>
#include <string>
using namespace std;

// Struct Mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

// Fungsi untuk mengurutkan mahasiswa berdasarkan IPK ascending
void urutkanIPK(Mahasiswa* mahasiswa, int jumlah) {
    // Menggunakan bubble sort
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (mahasiswa[j].ipk > mahasiswa[j + 1].ipk) {
                // Tukar posisi mahasiswa
                Mahasiswa temp = mahasiswa[j];
                mahasiswa[j] = mahasiswa[j + 1];
                mahasiswa[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa(Mahasiswa* mahasiswa, int jumlah) {
    cout << "\n+------------------------+------------+-------+" << endl;
    cout << "| Nama                   | NIM        | IPK   |" << endl;
    cout << "+------------------------+------------+-------+" << endl;
    
    for (int i = 0; i < jumlah; i++) {
        cout << "| ";
        cout.width(22);
        cout << left << mahasiswa[i].nama;
        cout << " | ";
        cout.width(10);
        cout << left << mahasiswa[i].nim;
        cout << " | ";
        cout.width(5);
        cout << fixed;
        cout.precision(2);
        cout << mahasiswa[i].ipk;
        cout << " |" << endl;
    }
    cout << "+------------------------+------------+-------+" << endl;
}

int main() {
    const int JUMLAH_MHS = 4; // Untuk NIM genap
    Mahasiswa mahasiswa[JUMLAH_MHS];
    
    cout << "=== SOAL 3: Struct + Array (NIM GENAP) ===" << endl;
    cout << "Input data " << JUMLAH_MHS << " mahasiswa:" << endl;
    
    // Input data mahasiswa
    for (int i = 0; i < JUMLAH_MHS; i++) {
        cout << "\nMahasiswa ke-" << (i + 1) << ":" << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, mahasiswa[i].nama);
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "IPK: ";
        cin >> mahasiswa[i].ipk;
    }
    
    cout << "\nData mahasiswa sebelum diurutkan:";
    tampilkanMahasiswa(mahasiswa, JUMLAH_MHS);
    
    urutkanIPK(mahasiswa, JUMLAH_MHS);
    
    cout << "\nData mahasiswa setelah diurutkan berdasarkan IPK (ascending):";
    tampilkanMahasiswa(mahasiswa, JUMLAH_MHS);
    
    return 0;
}