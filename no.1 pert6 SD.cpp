#include <iostream>
using namespace std;
#define MAX 5 
#define MAX_INPUTS 10 
struct Record { int id; float val; };
Record Q[MAX];
int front = -1, rear = -1; 

int main() {
    int count = 0;
    Record r;

    cout << "--- ENQUEUE RINGKAS (Kaps " << MAX << ", Maks " << MAX_INPUTS << ") ---\n";

    while (count++ < MAX_INPUTS) {
        if (rear == MAX - 1) {
            cout << "\nAntrian Penuh. Stop pada " << count - 1 << " record.\n";
            break; 
        }

        cout << "\n[Rec " << count << "] ID: "; cin >> r.id;
        cout << "  Nilai: "; cin >> r.val;

        if (front == -1) front = 0;
        Q[++rear] = r; 
        
        cout << "Record " << count << " (ID: " << r.id << ") di-Enqueue. Rear: " << rear << ".\n";
    }

    if (count > MAX_INPUTS) {
        cout << "\nBatas pengisian 10 record tercapai. Selesai.\n";
    }
    
    return 0;
}
