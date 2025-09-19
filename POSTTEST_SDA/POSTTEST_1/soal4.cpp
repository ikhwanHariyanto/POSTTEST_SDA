#include <iostream>
using namespace std;

// Fungsi untuk menukar dua variabel menggunakan reference (untuk NIM genap)
void tukarNilai(int &a, int &b) {
    cout << "Melakukan pertukaran menggunakan reference (&)..." << endl;
    
    int temp = a;
    a = b;
    b = temp;
    
    cout << "Pertukaran berhasil dilakukan!" << endl;
}

// Fungsi untuk menampilkan nilai
void tampilkanNilai(int a, int b, const string& keterangan) {
    cout << keterangan << endl;
    cout << "Nilai A: " << a << endl;
    cout << "Nilai B: " << b << endl;
    cout << "------------------------" << endl;
}

int main() {
    int nilaiA, nilaiB;
    
    cout << "=== SOAL 4: Pointer pada Fungsi (NIM GENAP) ===" << endl;
    cout << "Program untuk menukar dua variabel integer menggunakan reference (&)" << endl;
    
    // Input dua nilai
    cout << "\nMasukkan dua nilai integer:" << endl;
    cout << "Nilai A: ";
    cin >> nilaiA;
    cout << "Nilai B: ";
    cin >> nilaiB;
    
    tampilkanNilai(nilaiA, nilaiB, "\nNilai SEBELUM pertukaran:");
    
    tukarNilai(nilaiA, nilaiB);
    
    tampilkanNilai(nilaiA, nilaiB, "\nNilai SESUDAH pertukaran:");
    
    cout << "Program selesai!" << endl;
    
    return 0;
}