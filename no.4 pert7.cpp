#include <iostream>
using namespace std;
#define MAX 5
#define MAX_DELETES 10 
struct Record { int id; };
Record Q[MAX] = {{10, 10}, {20, 20}, {30, 30}}; 
int F = 0; // Front menunjuk ke elemen pertama (indeks 0)
int R = 2; // Rear menunjuk ke elemen terakhir (indeks 2)
int main() {
    int count = 0;
    cout << "--- DEQUEUE RINGKAS (Maks " << MAX_DELETES << " atau Kosong) ---\n";

    while (count++ < MAX_DELETES) {
        // Cek Kosong (Underflow): F = -1 atau F melewati R
        if (F == -1 || F > R) { 
            cout << "\nAntrian Kosong. Stop delete pada " << count - 1 << " record.\n";
            // Reset pointer jika logikanya kosong
            if (F > R) F = R = -1; 
            break; 
    }
        Record deleted = Q[F++]; 
        
        cout << "Record " << count << " (ID: " << deleted.id 
             << ") di-DEQUEUE. F Baru: " << F << ".\n";
    }

    if (count > MAX_DELETES) {
        cout << "\nBatas delete " << MAX_DELETES << " record tercapai. Selesai.\n";
    }
    
    cout << "Status Akhir: F=" << F << ", R=" << R << endl;

    return 0;
}
