#include <iostream>
#include <limits>

using namespace std;

const int MAX_SIZE = 10;
int S[MAX_SIZE];
int Top = -1; 

int main() {
    int data;

    cout << "--- Stack (Max 10) ---" << endl;
    cout << ">= 60: PUSH | < 60: POP | 999: Selesai" << endl;

    while (true) {
        cout << "\nInput: ";
        if (!(cin >> data)) {
            cerr << "Input invalid. Stop." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }

        if (data == 999) {
            cout << "Proses Selesai." << endl;
            break;
        }

        if (data >= 60) { // PUSH
            if (Top < MAX_SIZE - 1) { 
                S[++Top] = data;
                cout << "PUSH " << data << "." << endl;
            } else { 
                cout << "Stack Penuh. Stop." << endl;
                break;
            }
        } else { // POP
            if (Top != -1) { 
                cout << "POP " << S[Top--] << "." << endl;
            } else { 
                cout << "Stack Kosong. Stop." << endl;
                break;
            }
        }
    }

    if (Top != -1) {
        cout << "\nSisa Stack (" << Top + 1 << " elem): ";
        for (int i = 0; i <= Top; i++) {
            cout << S[i] << (i == Top ? "" : " | ");
        }
        cout << endl;
    }
    return 0;
}
