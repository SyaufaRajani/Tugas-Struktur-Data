#include <iostream>

using namespace std;

// Konfigurasi
#define MAX 5 
#define MAX_INPUTS 10 

// Struktur Data dan Pointer Global
struct Record { int id; };
Record Q[MAX];
int F = -1, R = -1; 

int main() {
    int count = 0;
    Record r;

    cout << "--- ENQUEUE RINGKAS (Kaps " << MAX << ", Maks " << MAX_INPUTS << ") ---\n";

    while (count++ < MAX_INPUTS) {
        if (R == MAX - 1) { // Cek Penuh
            cout << "\nAntrian Penuh. Stop pada " << count - 1 << " record.\n";
            break; 
        }

        cout << "\n[Rec " << count << "] ID: "; cin >> r.id; // Input
        
        if (F == -1) F = 0; // Setup Awal
        Q[++R] = r; 
        
        cout << "Record " << count << " (ID: " << r.id << ") di-Enqueue. R: " << R << ".\n";
    }

    if (count > MAX_INPUTS) {
        cout << "\nBatas pengisian 10 record tercapai. Selesai.\n";
    }
    
    return 0;
}
