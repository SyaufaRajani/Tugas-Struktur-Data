#include <iostream>
using namespace std;
#define MAX 5
#define MAX_DELETES 10 
struct Record { int id; float val; };
Record Q[MAX] = {{1, 10.0}, {2, 20.0}, {3, 30.0}}; 
int front = 0; // Mulai dari 0 karena ada data
int rear = 2;  // Indeks elemen terakhir
int main() {
    int count = 0;
    cout << "--- DEQUEUE RINGKAS (Maks " << MAX_DELETES << " atau Kosong) ---\n";
    while (count++ < MAX_DELETES) {
        // Cek Kosong (Underflow): front = -1 atau front melewati rear
        if (front == -1 || front > rear) {
            cout << "\nAntrian Kosong. Stop delete pada " << count - 1 << " record.\n";
            // Setelah kosong, reset pointer ke -1 untuk status bersih
            if (front > rear) front = rear = -1; 
            break; 
        }
        Record deleted_record = Q[front++]; 
        
        cout << "Record " << count << " (ID: " << deleted_record.id 
             << ") di-DEQUEUE. Front Baru: " << front << ".\n";
    }

    if (count > MAX_DELETES) {
        cout << "\nBatas delete " << MAX_DELETES << " record tercapai. Selesai.\n";
    }
    
    cout << "Status Akhir: Front=" << front << ", Rear=" << rear << endl;

    return 0;
}
