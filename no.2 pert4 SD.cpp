#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
int S[MAX_SIZE];
int Top = -1; 
int main() {
    int data;
    cout << "--- Program Stack: PUSH sampai Penuh, POP sampai Kosong ---" << endl;
    cout << "Kapasitas Stack: " << MAX_SIZE << " elemen." << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n[FASE 1: PUSH DATA]" << endl;
    while (Top < MAX_SIZE - 1) { 
        cout << "Input data (999=End): ";
        if (!(cin >> data)) break; 
        if (data == 999) {
            cout << "Input 999 terdeteksi. Proses PUSH Selesai." << endl;
            break;
        }
        S[++Top] = data;
        cout << "  -> Data " << data << " berhasil di-PUSH (Top=" << Top << ")." << endl;
    }
    if (Top == MAX_SIZE - 1) {
        cout << "\n--- Stack Penuh! Proses PUSH Selesai. ---" << endl;
    }
    cout << "\n[FASE 2: POP DATA]" << endl;
    if (Top == -1) {
        cout << "Stack sudah kosong, tidak ada data untuk di-POP." << endl;
    } else {
        while (Top != -1) { 
            int popped_data = S[Top];
            Top--; 
            cout << "  -> POP: " << popped_data << " (dicetak ke layar)" << endl;
        }
        cout << "--- Stack sudah Kosong! Proses Selesai. ---" << endl;
    }
    return 0;
}
