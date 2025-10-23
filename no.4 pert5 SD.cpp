#include <iostream>

using namespace std;

// Asumsi deklarasi dan pengisian data sudah dilakukan di tempat lain:
const int MAX = 10;
int S1[MAX] = {10, 20, 30, 40, 50}; // Contoh data awal (5 elemen)
int Top1 = 4; // Top menunjuk ke indeks 4 (data 50)

int main() {
    cout << "--- POP dan Cetak Stack1 Sampai Kosong ---" << endl;

    if (Top1 == -1) {
        cout << "Stack1 sudah kosong." << endl;
        return 0;
    }

    cout << "Data yang di-POP secara berurutan (LIFO):" << endl;
    
    // Loop selama Stack belum kosong (Top1 != -1)
    while (Top1 != -1) { 
        // POP: Ambil data dari S1[Top1] dan cetak, lalu turunkan Top1
        cout << "  -> " << S1[Top1--] << endl;
    }

    cout << "\nStack1 sudah berhasil dikosongkan. Proses selesai.?" << endl;
    
    return 0;
}
