#include <stdio.h>
#include <stdlib.h>

// Definisikan struktur node
struct nod {
    struct nod *left;
    char data;
    struct nod *right;
};

// Typedef untuk mempermudah penulisan
typedef struct nod NOD;
typedef NOD POKOK; // POKOK (Pohon) adalah alias untuk NOD

// Typedef untuk boolean (karena C standar tidak punya tipe bool sebelum C99)
typedef enum { FALSE = 0, TRUE = 1 } BOOL;

// Fungsi untuk membuat node baru
// NodBaru(char item)
NOD *NodBaru(char item) {
    NOD *n;
    // Alokasi memori
    n = (NOD*) malloc(sizeof(NOD));
    
    if (n != NULL) {
        n->data = item;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

// Fungsi untuk menginisialisasi pohon menjadi kosong
// BinaPokok(POKOK **T)
void BinaPokok(POKOK **T) {
    *T = NULL;
}

// Fungsi untuk mengecek apakah pohon kosong
// PokokKosong(POKOK *T)
BOOL PokokKosong(POKOK *T) {
    return ((BOOL)(T == NULL));
}

// Fungsi untuk menambah node (Hanya menambahkan ke pointer yang ditunjuk)
// TambahNod(NOD **p, char item)
void TambahNod(NOD **p, char item) {
    NOD *n;
    n = NodBaru(item); // Buat node baru
    *p = n;           // Hubungkan pointer p ke node baru
}

// Fungsi Traversal Pre-Order: Root -> Left -> Right
// preOrder(POKOK *T)
void preOrder(POKOK *T) {
    if (!PokokKosong(T)) {
        printf("%c ", T->data);
        preOrder(T->left);
        preOrder(T->right);
    }
}

// Fungsi Traversal In-Order: Left -> Root -> Right
// inOrder(POKOK *T)
void inOrder(POKOK *T) {
    if (!PokokKosong(T)) {
        inOrder(T->left);
        printf("%c ", T->data);
        inOrder(T->right);
    }
}

// Fungsi Traversal Post-Order: Left -> Right -> Root
// postOrder(POKOK *T)
void postOrder(POKOK *T) {
    if (!PokokKosong(T)) {
        postOrder(T->left);
        postOrder(T->right);
        printf("%c ", T->data);
    }
}


// Program utama (main function)
int main() {
    POKOK *kelapa;
    char buah; // Variabel 'buah' tidak terpakai, bisa diabaikan atau dihapus

    // 1. Inisialisasi Pohon
    BinaPokok(&kelapa); // 'kelapa' menjadi NULL

    // 2. Membangun Struktur Pohon
    // Root: 'M'
    TambahNod(&kelapa, 'M');

    // Level 1
    // kelapa->left = 'E'
    TambahNod(&kelapa->left, 'E'); 
    // kelapa->right = 'I'
    TambahNod(&kelapa->right, 'I'); 

    // Level 2 (Cabang Kiri)
    // kelapa->left->right = 'L'
    TambahNod(&kelapa->left->right, 'L'); 

    // Struktur Pohon yang terbentuk:
    //      M
    //     / \
    //    E   I
    //     \
    //      L
    
    // 3. Tampilkan Hasil Traversal
    printf("--- Hasil Traversal Pohon Biner ---\n");
    
    printf("Tampilan secara PreOrder: ");
    preOrder(kelapa);
    
    printf("\nTampilan secara InOrder: ");
    inOrder(kelapa);
    
    printf("\nTampilan secara PostOrder: "); // Perbaikan: di kode sumber Anda tertulis PreOrder lagi, seharusnya PostOrder
    postOrder(kelapa);
    
    printf("\n\n");
    
    return 0;
}
