// Asumsi: int S[MAX_SIZE] memiliki data, dan int Top menunjuk ke elemen teratas
#include <iostream>

using namespace std;

// Asumsi deklarasi global untuk konteks contoh
const int MAX_SIZE = 10;
int S[MAX_SIZE] = {10, 20, 30, 40, 50}; // Contoh data awal
int Top = 4; // Berarti ada 5 elemen (indeks 0 sampai 4)

int main() {
    cout << "--- POP Data Sampai Stack Kosong ---" << endl;

    if (Top == -1) {
        cout << "Stack saat ini sudah kosong. Tidak ada yang di-POP." << endl;
    } else {
        cout << "Memulai proses POP dan mencetak data..." << endl;
        
        while (Top != -1) { // Lanjutkan selama stack belum kosong
            int popped_data = S[Top];
            
            // Proses POP: Kurangi Top
            Top--; 
            
            // Cetak ke layar
            cout << "  -> POP: " << popped_data << " (Top baru: " << Top << ")" << endl;
        }

        cout << "\nStack sudah Kosong! Proses POP Selesai.?" << endl;
    }

    return 0;
}
