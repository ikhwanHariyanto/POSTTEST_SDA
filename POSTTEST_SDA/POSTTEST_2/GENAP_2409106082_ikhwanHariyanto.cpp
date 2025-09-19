#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struktur data untuk jadwal penerbangan
struct JadwalPenerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
};

// Node untuk Single Linked List
struct Node {
    JadwalPenerbangan jadwal;
    Node* next;
};

// Variabel global
Node* head = nullptr;
string nama, nim;
int counterJadwal = 1; // untuk membuat kode penerbangan unik

// Fungsi untuk mengecek apakah linked list kosong
bool isEmpty() {
    return head == nullptr;
}

// Fungsi untuk membuat kode penerbangan unik
string buatKodePenerbangan() {
    string kodeBase = "JT-082";
    if (counterJadwal == 1) {
        return kodeBase;
    } else {
        return kodeBase + "-" + to_string(counterJadwal - 1);
    }
}

// Fungsi untuk menambah jadwal penerbangan (Add Last)
void tambahJadwal() {
    Node* nodeBaru = new Node;
    
    cout << "\n=== TAMBAH JADWAL PENERBANGAN ===" << endl;
    
    // Generate kode penerbangan otomatis
    nodeBaru->jadwal.kodePenerbangan = buatKodePenerbangan();
    cout << "Kode Penerbangan (otomatis): " << nodeBaru->jadwal.kodePenerbangan << endl;
    
    cout << "Masukkan tujuan: ";
    cin.ignore();
    getline(cin, nodeBaru->jadwal.tujuan);
    
    cout << "Masukkan status (Tepat Waktu/Terlambat/Naik Pesawat): ";
    getline(cin, nodeBaru->jadwal.status);
    
    nodeBaru->next = nullptr;
    counterJadwal++;
    
    // Jika linked list kosong
    if (head == nullptr) {
        head = nodeBaru;
    } else {
        // Traversal ke node terakhir
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
    
    cout << "Jadwal penerbangan berhasil ditambahkan!" << endl;
}

// Fungsi untuk menyisipkan jadwal di posisi tertentu (Add Specific)
void sisipkanJadwal() {
    if (isEmpty()) {
        cout << "Linked list kosong. Menambahkan sebagai jadwal pertama." << endl;
        tambahJadwal();
        return;
    }
    
    // Posisi berdasarkan digit terakhir NIM + 1 (2 + 1 = 3)
    int posisi = 3;
    
    cout << "\n=== SISIPKAN JADWAL PENERBANGAN ===" << endl;
    cout << "Jadwal akan disisipkan di posisi: " << posisi << endl;
    
    Node* nodeBaru = new Node;
    
    // Generate kode penerbangan otomatis
    nodeBaru->jadwal.kodePenerbangan = buatKodePenerbangan();
    cout << "Kode Penerbangan (otomatis): " << nodeBaru->jadwal.kodePenerbangan << endl;
    
    cout << "Masukkan tujuan: ";
    cin.ignore();
    getline(cin, nodeBaru->jadwal.tujuan);
    
    cout << "Masukkan status (Tepat Waktu/Terlambat/Naik Pesawat): ";
    getline(cin, nodeBaru->jadwal.status);
    
    counterJadwal++;
    
    if (posisi <= 1) {
        // Insert di awal
        nodeBaru->next = head;
        head = nodeBaru;
    } else {
        Node* temp = head;
        int hitung = 1;
        
        while (temp != nullptr && hitung < posisi - 1) {
            temp = temp->next;
            hitung++;
        }
        
        if (temp == nullptr) {
            cout << "Posisi melebihi panjang list. Menambahkan di akhir." << endl;
            // Tambah di akhir
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            nodeBaru->next = nullptr;
            temp->next = nodeBaru;
        } else {
            nodeBaru->next = temp->next;
            temp->next = nodeBaru;
        }
    }
    
    cout << "Jadwal penerbangan berhasil disisipkan!" << endl;
}

// Fungsi untuk menghapus jadwal paling awal (Delete First)
void hapusJadwalAwal() {
    cout << "\n=== HAPUS JADWAL PALING AWAL ===" << endl;
    
    if (isEmpty()) {
        cout << "Tidak ada jadwal untuk dihapus!" << endl;
        return;
    }
    
    Node* temp = head;
    cout << "Menghapus jadwal: " << temp->jadwal.kodePenerbangan 
         << " - " << temp->jadwal.tujuan << endl;
    
    head = head->next;
    delete temp;
    
    cout << "Jadwal paling awal berhasil dihapus!" << endl;
}

// Fungsi untuk update status penerbangan (Fungsi paling kompleks)
void updateStatusPenerbangan() {
    cout << "\n=== UPDATE STATUS PENERBANGAN ===" << endl;
    
    if (isEmpty()) {
        cout << "Tidak ada jadwal penerbangan!" << endl;
        return;
    }
    
    string kodeCarang;
    cout << "Masukkan kode penerbangan yang ingin diupdate: ";
    cin.ignore();
    getline(cin, kodeCarang);
    
    Node* temp = head;
    bool ditemukan = false;
    
    // Mencari jadwal dengan kode penerbangan yang dimaksud
    while (temp != nullptr) {
        if (temp->jadwal.kodePenerbangan == kodeCarang) {
            ditemukan = true;
            cout << "\nJadwal ditemukan:" << endl;
            cout << "Kode Penerbangan: " << temp->jadwal.kodePenerbangan << endl;
            cout << "Tujuan: " << temp->jadwal.tujuan << endl;
            cout << "Status saat ini: " << temp->jadwal.status << endl;
            
            string statusBaru;
            cout << "\nMasukkan status baru: ";
            getline(cin, statusBaru);
            
            string statusLama = temp->jadwal.status;
            temp->jadwal.status = statusBaru;
            
            cout << "\nStatus berhasil diupdate!" << endl;
            cout << "Status lama: " << statusLama << endl;
            cout << "Status baru: " << temp->jadwal.status << endl;
            break;
        }
        temp = temp->next;
    }
    
    if (!ditemukan) {
        cout << "Jadwal dengan kode penerbangan '" << kodeCarang << "' tidak ditemukan!" << endl;
    }
}

// Fungsi untuk menampilkan semua jadwal
void tampilkanSemuaJadwal() {
    cout << "\n=== SEMUA JADWAL PENERBANGAN ===" << endl;
    
    if (isEmpty()) {
        cout << "Tidak ada jadwal penerbangan!" << endl;
        return;
    }
    
    Node* temp = head;
    int nomor = 1;
    
    cout << left << setw(5) << "No." 
         << setw(15) << "Kode" 
         << setw(25) << "Tujuan" 
         << setw(20) << "Status" << endl;
    cout << string(65, '=') << endl;
    
    while (temp != nullptr) {
        cout << left << setw(5) << nomor++
             << setw(15) << temp->jadwal.kodePenerbangan
             << setw(25) << temp->jadwal.tujuan
             << setw(20) << temp->jadwal.status << endl;
        temp = temp->next;
    }
    cout << string(65, '=') << endl;
}

// Fungsi untuk membersihkan semua data
void clearList() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    counterJadwal = 1;
    cout << "Semua jadwal telah dihapus!" << endl;
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n" << string(65, '=') << endl;
    cout << "|" << setw(31) << "FLIGHT SCHEDULE SYSTEM" << setw(33) << "|" << endl;
    cout << "|" << setw(15) << "[ " << nama << " - " << nim << " ]" << setw(25) << "|" << endl;
    cout << string(65, '=') << endl;
    cout << "| 1. Tambah Jadwal Penerbangan" << setw(36) << "|" << endl;
    cout << "| 2. Sisipkan Jadwal Penerbangan" << setw(34) << "|" << endl;
    cout << "| 3. Hapus Jadwal Paling Awal" << setw(37) << "|" << endl;
    cout << "| 4. Update Status Penerbangan" << setw(36) << "|" << endl;
    cout << "| 5. Tampilkan Semua Jadwal" << setw(39) << "|" << endl;
    cout << "| 6. Hapus Semua Jadwal" << setw(43) << "|" << endl;
    cout << "| 0. Keluar" << setw(55) << "|" << endl;
    cout << string(65, '=') << endl;
    cout << "Pilih menu: ";
}

int main() {
    cout << "=== SISTEM JADWAL PENERBANGAN ===" << endl;
    cout << "Masukkan identitas Anda:" << endl;
    cout << "Nama: ";
    getline(cin, nama);
    cout << "NIM: ";
    getline(cin, nim);
    
    int pilihan;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambahJadwal();
                break;
            case 2:
                sisipkanJadwal();
                break;
            case 3:
                hapusJadwalAwal();
                break;
            case 4:
                updateStatusPenerbangan();
                break;
            case 5:
                tampilkanSemuaJadwal();
                break;
            case 6:
                clearList();
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan sistem!" << endl;
                clearList(); // Bersihkan memory sebelum keluar
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        
        if (pilihan != 0) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
        
    } while (pilihan != 0);
    
    return 0;
}