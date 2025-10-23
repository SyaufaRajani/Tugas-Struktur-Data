#include <iostream>

using namespace std;

// Definisikan ukuran maksimum kedua stack
const int MAX = 10;

// Deklarasi array dan pointer Top untuk Stack1 dan Stack2
int S1[MAX];
int Top1 = -1; // Stack1 kosong
int S2[MAX];
int Top2 = -1; // Stack2 kosong

// --- FUNGSI PUSH1 ---
void PUSH1(int data) {
    if (Top1 == MAX - 1) {
        cout << "Stack1 Penuh. PUSH1 Gagal." << endl;
    } else {
        S1[++Top1] = data;
        cout << "Data " << data << " di-PUSH ke Stack1 (TOP1: " << Top1 << ")." << endl;
    }
}

// --- FUNGSI POP1 ---
int POP1() {
    if (Top1 == -1) {
        cout << "Stack1 Kosong. POP1 Gagal." << endl;
        return -1; // Mengembalikan nilai error
    } else {
        int data_pop = S1[Top1--];
        cout << "Data " << data_pop << " di-POP dari Stack1 (TOP1: " << Top1 << ")." << endl;
        return data_pop;
    }
}

// --- FUNGSI PUSH2 ---
void PUSH2(int data) {
    if (Top2 == MAX - 1) {
        cout << "Stack2 Penuh. PUSH2 Gagal." << endl;
    } else {
        S2[++Top2] = data;
        cout << "Data " << data << " di-PUSH ke Stack2 (TOP2: " << Top2 << ")." << endl;
    }
}

// --- FUNGSI POP2 ---
int POP2() {
    if (Top2 == -1) {
        cout << "Stack2 Kosong. POP2 Gagal." << endl;
        return -1; // Mengembalikan nilai error
    } else {
        int data_pop = S2[Top2--];
        cout << "Data " << data_pop << " di-POP dari Stack2 (TOP2: " << Top2 << ")." << endl;
        return data_pop;
    }
}


int main() {
    cout << "--- Program Stack Ganda (Stack1 dan Stack2) ---" << endl;
    
    // UJI PUSH1
    cout << "\n[UJI PUSH1]" << endl;
    PUSH1(10); 
    PUSH1(20); 
    PUSH1(30);

    // UJI POP1
    cout << "\n[UJI POP1]" << endl;
    POP1(); // Mengeluarkan 30
    POP1(); // Mengeluarkan 20

    // UJI PUSH2
    cout << "\n[UJI PUSH2]" << endl;
    PUSH2(500);
    PUSH2(600);
    PUSH2(700);
    
    // UJI POP2
    cout << "\n[UJI POP2]" << endl;
    POP2(); // Mengeluarkan 700
    POP2(); // Mengeluarkan 600
    
    // Contoh status akhir
    cout << "\nStatus Akhir Top1: " << Top1 << endl;
    cout << "Status Akhir Top2: " << Top2 << endl;
    
    return 0;
}
