#include <iostream>
using namespace std;
#define MAX 5

class Queue {
private:
    int front, rear;
    int ele[MAX];

public:
    Queue() // Inisialisasi queue
    {
        front = 0;
        rear = -1;
    }
    
    // Deklarasi method yang hilang/diperlukan
    bool isFull();
    bool isEmpty();
    void insertQueue(int item);
    int deleteQueue(int *item);
};

// --- Implementasi Method ---

bool Queue::isFull() {
    // Linear Queue Penuh jika rear mencapai batas array
    return rear == MAX - 1;
}

bool Queue::isEmpty() {
    // Linear Queue Kosong jika front > rear atau rear = -1
    return front > rear || rear == -1;
}

void Queue::insertQueue(int item) {
    if (isFull()) {
        cout << "\nQueue Overflow. Item " << item << " tidak bisa disisipkan." << endl;
        return;
    }
    // Jika queue baru pertama kali diisi, front sudah 0 dari inisialisasi.
    // Kita hanya perlu memajukan rear.
    ele[++rear] = item;
    cout << "\nItem disisipkan: " << item;
}

int Queue::deleteQueue(int *item) {
    if (isEmpty()) {
        cout << "\nQueue Underflow" << endl;
        // Atur ulang pointer jika sudah benar-benar kosong
        if (front > rear) front = 0, rear = -1; 
        return -1;
    }
    
    *item = ele[front++];
    
    // Jika front melewati rear setelah dequeue, reset pointer untuk inisialisasi bersih
    if (front > rear) {
        front = 0;
        rear = -1;
    }
    return 0;
}

int main() {
    int item = 0;
    Queue q = Queue();
    
    cout << "--- OPERASI INSERT ---" << endl;
    q.insertQueue(10); // R=0
    q.insertQueue(20); // R=1
    q.insertQueue(30); // R=2
    q.insertQueue(40); // R=3
    q.insertQueue(50); // R=4 (Queue Penuh)
    q.insertQueue(60); // Overflow (akan gagal)
    
    cout << "\n\n--- OPERASI DELETE ---";
    
    if(q.deleteQueue( &item) == 0)  // Hapus 10. F=1
        cout << "\nItem dihapus : " << item;
        
    if(q.deleteQueue( &item) == 0)  // Hapus 20. F=2
        cout << "\nItem dihapus : " << item;
        
    if(q.deleteQueue( &item) == 0)  // Hapus 30. F=3
        cout << "\nItem dihapus : " << item;
        
    if(q.deleteQueue( &item) == 0)  // Hapus 40. F=4
        cout << "\nItem dihapus : " << item;
        
    if(q.deleteQueue( &item) == 0)  // Hapus 50. F=5. (F > R, Queue Kosong & di-reset)
        cout << "\nItem dihapus : " << item;
        
    if(q.deleteQueue( &item) == 0)  // Underflow (akan gagal)
        cout << "\nItem dihapus : " << item;
        
    cout << endl;
    return 0;
}
