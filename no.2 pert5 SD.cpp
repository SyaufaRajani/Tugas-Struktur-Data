#include <iostream>

using namespace std;

const int MAX = 5; 
int S1[MAX], Top1 = -1; // Stack 1
int S2[MAX], Top2 = -1; // Stack 2

void PUSH1(int d) {
    if (Top1 < MAX - 1) {
        S1[++Top1] = d;
        cout << "PUSH1: " << d << " disimpan. (Top1: " << Top1 << ")" << endl;
    } else {
        cout << "STACK1 PENUH. PUSH1 Gagal untuk data " << d << "." << endl;
    }
}

int POP1() {
    if (Top1 != -1) {
        int d = S1[Top1--]; 
        cout << "POP1: " << d << " dikeluarkan. (Top1: " << Top1 << ")" << endl;
        return d;
    } else {
        cout << "STACK1 KOSONG. POP1 Gagal." << endl;
        return -1;
    }
}

void PUSH2(int d) {
    if (Top2 < MAX - 1) {
        S2[++Top2] = d;
        cout << "PUSH2: " << d << " disimpan. (Top2: " << Top2 << ")" << endl;
    } else {
        cout << "STACK2 PENUH. PUSH2 Gagal untuk data " << d << "." << endl;
    }
}

int POP2() {
    if (Top2 != -1) {
        int d = S2[Top2--]; 
        cout << "POP2: " << d << " dikeluarkan. (Top2: " << Top2 << ")" << endl;
        return d;
    } else {
        cout << "STACK2 KOSONG. POP2 Gagal." << endl;
        return -1;
    }
}


int main() {
    cout << "--- DEMO STACK GANDA (MAX=" << MAX << ") ---" << endl;
    
    cout << "\n[UJI PUSH1 & POP1]" << endl;
    PUSH1(10); PUSH1(20); PUSH1(30); 
    POP1(); POP1(); 

    cout << "\n[UJI PUSH2 & POP2]" << endl;
    PUSH2(100); PUSH2(200); PUSH2(300);
    PUSH2(400); PUSH2(500); 
    PUSH2(600); // Test Penuh
    POP2(); POP2(); 
    
    cout << "\nStatus Akhir Top1: " << Top1 << endl;
    cout << "Status Akhir Top2: " << Top2 << endl;
    
    return 0;
}
