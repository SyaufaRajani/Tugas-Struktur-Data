#include <iostream>
using namespace std;

#define MAX 5 

struct Record { int id; };
Record Q[MAX];
int F = -1, R = -1; 

void Insert(int id) {
    if ((R + 1) % MAX == F) { cout << "Penuh. Gagal (ID: " << id << ").\n"; return; }
    if (F == -1) F = 0;
    Q[R = (R + 1) % MAX] = {id}; // Padat!
    cout << "Insert (ID: " << id << "). F=" << F << ", R=" << R << ".\n";
}

void Delete() {
    if (F == -1) { cout << "Kosong. Delete Gagal.\n"; return; }
    
    int id = Q[F].id;
    
    if (F == R) { F = R = -1; cout << "Delete (ID: " << id << "). Kosong.\n"; }
    else { F = (F + 1) % MAX; cout << "Delete (ID: " << id << "). F=" << F << ", R=" << R << ".\n"; }
}

int main() {
    cout << "--- CIRCULAR QUEUE MINI ---\n";
    Insert(10); Insert(20); Insert(30); 
    Delete(); Delete();
    Insert(60); Insert(70); Insert(80); // Penuh di 80
    Insert(90); // Gagal
    return 0;
}
