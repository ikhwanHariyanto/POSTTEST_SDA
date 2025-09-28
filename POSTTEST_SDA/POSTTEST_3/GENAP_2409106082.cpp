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

// Node untuk Double Linked List
struct Node {
    JadwalPenerbangan jadwal;
    Node* next;
    Node* prev;  // Pointer ke node sebelumnya
};

// Variabel global
Node* head = nullptr;
Node* tail = nullptr;  // Pointer ke node terakhir
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
    
    cout << "\n+===================================+" << endl;
    cout << "|     TAMBAH JADWAL PENERBANGAN     |" << endl;
    cout << "+===================================+" << endl;
    
    // Generate kode penerbangan otomatis
    nodeBaru->jadwal.kodePenerbangan = buatKodePenerbangan();
    cout << "Kode Penerbangan (otomatis): " << nodeBaru->jadwal.kodePenerbangan << endl;
    
    cout << "Masukkan tujuan: ";
    cin.ignore();
    getline(cin, nodeBaru->jadwal.tujuan);
    
    cout << "Masukkan status (Tepat Waktu/Terlambat/Naik Pesawat): ";
    getline(cin, nodeBaru->jadwal.status);
    
    nodeBaru->next = nullptr;
    nodeBaru->prev = nullptr;
    counterJadwal++;
    
    // Jika linked list kosong
    if (head == nullptr) {
        head = nodeBaru;
        tail = nodeBaru;
    } else {
        // Tambah di akhir (setelah tail)
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
    }
    
    cout << ">> Jadwal penerbangan berhasil ditambahkan!" << endl;
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
    
    cout << "\n+=====================================+" << endl;
    cout << "|     SISIPKAN JADWAL PENERBANGAN     |" << endl;
    cout << "+=====================================+" << endl;
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
        nodeBaru->prev = nullptr;
        if (head != nullptr) {
            head->prev = nodeBaru;
        }
        head = nodeBaru;
        if (tail == nullptr) {
            tail = nodeBaru;
        }
    } else {
        Node* temp = head;
        int hitung = 1;
        
        while (temp != nullptr && hitung < posisi) {
            temp = temp->next;
            hitung++;
        }
        
        if (temp == nullptr) {
            // Posisi melebihi panjang, tambah di akhir
            cout << "Posisi melebihi panjang list. Menambahkan di akhir." << endl;
            tail->next = nodeBaru;
            nodeBaru->prev = tail;
            nodeBaru->next = nullptr;
            tail = nodeBaru;
        } else {
            // Insert di tengah atau akhir
            nodeBaru->next = temp;
            nodeBaru->prev = temp->prev;
            
            if (temp->prev != nullptr) {
                temp->prev->next = nodeBaru;
            } else {
                head = nodeBaru;
            }
            temp->prev = nodeBaru;
        }
    }
    
    cout << ">> Jadwal penerbangan berhasil disisipkan!" << endl;
}

// Fungsi untuk menghapus jadwal paling awal (Delete First)
void hapusJadwalAwal() {
    cout << "\n+===================================+" << endl;
    cout << "|     HAPUS JADWAL PALING AWAL      |" << endl;
    cout << "+===================================+" << endl;
    
    if (isEmpty()) {
        cout << "!! Tidak ada jadwal untuk dihapus!" << endl;
        return;
    }
    
    Node* temp = head;
    cout << "Menghapus jadwal: " << temp->jadwal.kodePenerbangan 
         << " - " << temp->jadwal.tujuan << endl;
    
    if (head == tail) {
        // Hanya ada satu node
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    
    delete temp;
    cout << ">> Jadwal paling awal berhasil dihapus!" << endl;
}

// Fungsi untuk update status penerbangan (Fungsi paling kompleks)
void updateStatusPenerbangan() {
    cout << "\n+===================================+" << endl;
    cout << "|     UPDATE STATUS PENERBANGAN     |" << endl;
    cout << "+===================================+" << endl;
    
    if (isEmpty()) {
        cout << "!! Tidak ada jadwal penerbangan!" << endl;
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
            cout << "+-------------------------------------+" << endl;
            cout << "| Kode Penerbangan: " << left << setw(17) << temp->jadwal.kodePenerbangan << "|" << endl;
            cout << "| Tujuan: " << left << setw(27) << temp->jadwal.tujuan << "|" << endl;
            cout << "| Status saat ini: " << left << setw(19) << temp->jadwal.status << "|" << endl;
            cout << "+-------------------------------------+" << endl;
            
            string statusBaru;
            cout << "\nMasukkan status baru: ";
            getline(cin, statusBaru);
            
            string statusLama = temp->jadwal.status;
            temp->jadwal.status = statusBaru;
            
            cout << "\n>> Status berhasil diupdate!" << endl;
            cout << "Status lama: " << statusLama << endl;
            cout << "Status baru: " << temp->jadwal.status << endl;
            break;
        }
        temp = temp->next;
    }
    
    if (!ditemukan) {
        cout << "!! Jadwal dengan kode penerbangan '" << kodeCarang << "' tidak ditemukan!" << endl;
    }
}

// Fungsi untuk menampilkan detail data berdasarkan kode penerbangan atau tujuan
void tampilkanDetailData() {
    cout << "\n+===================================+" << endl;
    cout << "|       TAMPILKAN DETAIL DATA       |" << endl;
    cout << "+===================================+" << endl;
    
    if (isEmpty()) {
        cout << "!! Tidak ada jadwal penerbangan!" << endl;
        return;
    }
    
    string keyword;
    cout << "Masukkan kode penerbangan atau tujuan yang ingin dicari: ";
    cin.ignore();
    getline(cin, keyword);
    
    Node* temp = head;
    bool ditemukan = false;
    
    cout << "\nHasil pencarian untuk: \"" << keyword << "\"" << endl;
    cout << "+===============================================================+" << endl;
    
    while (temp != nullptr) {
        // Cek apakah keyword cocok dengan kode penerbangan atau tujuan
        if (temp->jadwal.kodePenerbangan.find(keyword) != string::npos || 
            temp->jadwal.tujuan.find(keyword) != string::npos) {
            
            if (!ditemukan) {
                cout << "|                   DETAIL JADWAL DITEMUKAN                    |" << endl;
                cout << "+===============================================================+" << endl;
                ditemukan = true;
            }
            
            cout << "| Kode Penerbangan: " << left << setw(43) << temp->jadwal.kodePenerbangan << "|" << endl;
            cout << "| Tujuan: " << left << setw(51) << temp->jadwal.tujuan << "|" << endl;
            cout << "| Status: " << left << setw(51) << temp->jadwal.status << "|" << endl;
            cout << "+===============================================================+" << endl;
        }
        temp = temp->next;
    }
    
    if (!ditemukan) {
        cout << "|                     TIDAK ADA DATA DITEMUKAN                 |" << endl;
        cout << "+===============================================================+" << endl;
    }
}

// Fungsi untuk menampilkan semua jadwal dari depan
void tampilkanSemuaJadwal() {
    cout << "\n+==============================================================================+" << endl;
    cout << "|                          SEMUA JADWAL PENERBANGAN                           |" << endl;
    cout << "+==============================================================================+" << endl;
    
    if (isEmpty()) {
        cout << "!! Tidak ada jadwal penerbangan!" << endl;
        return;
    }
    
    Node* temp = head;
    int nomor = 1;
    
    cout << "+-----+---------------+-------------------------+--------------------+" << endl;
    cout << "| No. |     Kode      |         Tujuan          |       Status       |" << endl;
    cout << "+-----+---------------+-------------------------+--------------------+" << endl;
    
    while (temp != nullptr) {
        cout << "| " << left << setw(3) << nomor++
             << " | " << left << setw(13) << temp->jadwal.kodePenerbangan
             << " | " << left << setw(23) << temp->jadwal.tujuan
             << " | " << left << setw(18) << temp->jadwal.status << " |" << endl;
        temp = temp->next;
    }
    cout << "+-----+---------------+-------------------------+--------------------+" << endl;
}

// Fungsi baru untuk menampilkan jadwal dari belakang (traversal mundur)
void tampilkanJadwalMundur() {
    cout << "\n+==============================================================================+" << endl;
    cout << "|                    JADWAL PENERBANGAN (DARI BELAKANG)                       |" << endl;
    cout << "+==============================================================================+" << endl;
    
    if (isEmpty()) {
        cout << "!! Tidak ada jadwal penerbangan!" << endl;
        return;
    }
    
    Node* temp = tail;  // Mulai dari tail
    int nomor = 1;
    
    cout << "+-----+---------------+-------------------------+--------------------+" << endl;
    cout << "| No. |     Kode      |         Tujuan          |       Status       |" << endl;
    cout << "+-----+---------------+-------------------------+--------------------+" << endl;
    
    while (temp != nullptr) {
        cout << "| " << left << setw(3) << nomor++
             << " | " << left << setw(13) << temp->jadwal.kodePenerbangan
             << " | " << left << setw(23) << temp->jadwal.tujuan
             << " | " << left << setw(18) << temp->jadwal.status << " |" << endl;
        temp = temp->prev;  // Bergerak ke node sebelumnya
    }
    cout << "+-----+---------------+-------------------------+--------------------+" << endl;
}

// Fungsi untuk membersihkan semua data
void clearList() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    counterJadwal = 1;
    cout << ">> Semua jadwal telah dihapus!" << endl;
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n+=================================================================+" << endl;
    cout << "|                      FLIGHT SCHEDULE SYSTEM                    |" << endl;
    cout << "|                     DOUBLE LINKED LIST                         |" << endl;
    cout << "+=================================================================+" << endl;
    cout << "|                    [ " << left << setw(20) << (nama + " - " + nim) << " ]                    |" << endl;
    cout << "+=================================================================+" << endl;
    cout << "| 1. Tambah Jadwal Penerbangan                                   |" << endl;
    cout << "| 2. Sisipkan Jadwal Penerbangan                                 |" << endl;
    cout << "| 3. Hapus Jadwal Paling Awal                                    |" << endl;
    cout << "| 4. Update Status Penerbangan                                   |" << endl;
    cout << "| 5. Tampilkan Semua Jadwal (Depan -> Belakang)                  |" << endl;
    cout << "| 6. Tampilkan Semua Jadwal (Belakang -> Depan)                  |" << endl;
    cout << "| 7. Tampilkan Detail Data                                       |" << endl;
    cout << "| 8. Hapus Semua Jadwal                                          |" << endl;
    cout << "| 0. Keluar                                                      |" << endl;
    cout << "+=================================================================+" << endl;
    cout << "Pilih menu (0-8): ";
}

int main() {
    cout << "+===============================================================+" << endl;
    cout << "|              SISTEM JADWAL PENERBANGAN                       |" << endl;
    cout << "|                   DOUBLE LINKED LIST VERSION                 |" << endl;
    cout << "+===============================================================+" << endl;
    cout << "\nMasukkan identitas Anda:" << endl;
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
                tampilkanJadwalMundur();
                break;
            case 7:
                tampilkanDetailData();
                break;
            case 8:
                clearList();
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan sistem!" << endl;
                cout << "Sampai jumpa lagi!" << endl;
                clearList(); // Bersihkan memory sebelum keluar
                break;
            default:
                cout << "!! Pilihan tidak valid! Silakan pilih 0-8." << endl;
        }
        
        if (pilihan != 0) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
        
    } while (pilihan != 0);
    
    return 0;
}