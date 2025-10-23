#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
int S[MAX_SIZE];
int Top = -1; 
int main() {
    int data;
    cout << "--- PUSH Data Sampai Stack Penuh (MAX: " << MAX_SIZE << " elemen) ---" << endl;
    while (Top < MAX_SIZE - 1) { 
        cout << "Masukkan data ke Stack (Indeks Top saat ini: " << Top << "): ";
        if (!(cin >> data)) {
            cerr << "Input tidak valid (harus angka). Proses PUSH dihentikan." << endl;
            break; 
        }
        Top++;
        S[Top] = data;
        cout << "Data " << data << " berhasil di-PUSH." << endl;
    }
    if (Top == MAX_SIZE - 1) {
        cout << "\nStack Penuh! Tidak dapat menyimpan data lagi. Kapasitas tercapai." << endl;
    } else {
        cout << "\nProses PUSH dihentikan karena input tidak valid." << endl;
    }
    cout << "Status Stack: " << Top + 1 << " elemen terisi." << endl;

    return 0;
}
