#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi untuk memasukkan data ke dalam stack (push)
// Parameter: top (pointer ke puncak stack), data (karakter yang akan dimasukkan)
void push(Node*& top, char data) {
    // Buat node baru dengan data dan next menunjuk ke top sekarang
    Node* newNode = new Node{data, top};
    // Update top agar menunjuk ke node baru (node baru jadi puncak)
    top = newNode;
}

// Fungsi untuk mengeluarkan data dari stack (pop)
// Parameter: top (pointer ke puncak stack)
// Return: karakter yang dikeluarkan dari stack
char pop(Node*& top) {
    // Jika stack kosong, return karakter null
    if (top == nullptr) return '\0';
    
    // Simpan pointer ke node yang akan dihapus
    Node* temp = top;
    // Ambil data dari node tersebut
    char poppedValue = temp->data;
    // Geser top ke node berikutnya
    top = top->next;
    // Hapus node lama dari memori
    delete temp;
    // Return data yang diambil
    return poppedValue;
}

// Fungsi untuk membalik string menggunakan stack
// Parameter: s (string yang akan dibalik)
// Return: string yang sudah dibalik
string reverseString(string s) {
    Node* stackTop = nullptr;  // Inisialisasi stack kosong
    string reversed = "";       // String untuk menampung hasil
    
    // LANGKAH 1: Push semua karakter ke stack
    // Loop untuk setiap karakter dalam string s
    for (int i = 0; i < s.length(); i++) {
        // Masukkan karakter ke-i ke dalam stack
        push(stackTop, s[i]);
    }
    
    // LANGKAH 2: Pop semua karakter dari stack
    // Karena stack bersifat LIFO, karakter akan keluar dalam urutan terbalik
    while (stackTop != nullptr) {
        // Ambil karakter dari stack dan tambahkan ke string reversed
        reversed += pop(stackTop);
    }
    
    // Return string yang sudah dibalik
    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;
    // Output yang diharapkan: ataD rutкurtS
    return 0;
}

/* 
 * PENJELASAN CARA KERJA:
 * 
 * 1. String "Struktur Data" akan diproses karakter per karakter
 * 2. Setiap karakter di-push ke stack:
 *    Stack: S -> t -> r -> u -> k -> t -> u -> r ->   -> D -> a -> t -> a
 * 3. Saat di-pop, karakter keluar dari belakang (LIFO):
 *    Output: a -> t -> a -> D ->   -> r -> u -> t -> k -> u -> r -> t -> S
 * 4. Hasil akhir: "ataD rutкurtS"
 */