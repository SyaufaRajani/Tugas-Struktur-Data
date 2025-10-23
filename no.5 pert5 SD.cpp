#include <iostream>

using namespace std;

// Asumsi deklarasi dan pengisian data sudah dilakukan di tempat lain:
const int MAX = 10;
int S2[MAX] = {100, 200, 300, 400, 500}; // Contoh data awal (5 elemen)
int Top2 = 4; // Top menunjuk ke indeks 4 (data 500)

int main() {
    cout << "--- POP dan Cetak Stack2 Sampai Kosong ---" << endl;

    if (Top2 == -1) {
        cout << "Stack2 sudah kosong." << endl;
        return 0;
    }

    cout << "Data yang di-POP secara berurutan (LIFO):" << endl;
    
    // Loop selama Stack belum kosong (Top2 != -1)
    while (Top2 != -1) { 
        // POP: Ambil data dari S2[Top2] dan cetak, lalu turunkan Top2
        cout << "  -> " << S2[Top2--] << endl;
    }

    cout << "\nStack2 sudah berhasil dikosongkan. Proses selesai.?" << endl;
    
    return 0;
}
