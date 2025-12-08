#include <iostream>

// Menggunakan namespace standar untuk mempermudah penulisan
using namespace std;

// 1. DEFINISI STRUKTUR NODE
struct Node {
    char data;
    Node* left;
    Node* right;

    // Constructor untuk membuat Node baru
    Node(char val) {
        data = val;
        left = nullptr; // Menggunakan nullptr untuk C++ modern
        right = nullptr;
    }
};

// --- FUNGSI TRAVERSAL ---

// 2. FUNGSI PREORDER (Root -> Kiri -> Kanan)
void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " "; // Kunjungi Root
    preOrder(root->left);      // Kunjungi Kiri
    preOrder(root->right);     // Kunjungi Kanan
}

// 3. FUNGSI INORDER (Kiri -> Root -> Kanan)
void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);       // Kunjungi Kiri
    cout << root->data << " "; // Kunjungi Root
    inOrder(root->right);      // Kunjungi Kanan
}

// 4. FUNGSI POSTORDER (Kiri -> Kanan -> Root)
void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);     // Kunjungi Kiri
    postOrder(root->right);    // Kunjungi Kanan
    cout << root->data << " "; // Kunjungi Root
}

// --- FUNGSI UTAMA ---
int main() {
    // Berdasarkan rekonstruksi pohon dari soal: R(Root), A(R.Left), E(R.Right), S(A.Left), I(S.Left), T(S.Right)

    // 5. PEMBANGUNAN POHON (INPUT NODE BARU)
    // Membuat node Root
    Node* root = new Node('R');

    // Level 1
    root->left = new Node('A');
    root->right = new Node('E');

    // Level 2 (Anak Kiri dari A)
    Node* A_node = root->left;
    A_node->left = new Node('S');

    // Level 3 (Anak Kiri dan Kanan dari S)
    Node* S_node = A_node->left;
    S_node->left = new Node('I');
    S_node->right = new Node('T');

    // 6. HASIL TRAVERSAL
    cout << "### HASIL TRAVERSAL POHON ###" << endl;
    cout << "------------------------------" << endl;

    // PreOrder (Target: R A S I T E)
    cout << "Tampilan secara PreOrder : ";
    preOrder(root);
    cout << endl;
    cout << "Target: R A S I T E" << endl;

    // InOrder (Target: I S T A R E)
    cout << "\nTampilan secara InOrder  : ";
    inOrder(root);
    cout << endl;
    cout << "Target: I S T A R E" << endl;

    // PostOrder (Target: I T S A E R)
    cout << "\nTampilan secara PostOrder: ";
    postOrder(root);
    cout << endl;
    cout << "Target: I T S A E R" << endl;
    
    // Jangan lupa membersihkan memori yang dialokasikan (meskipun untuk program kecil ini tidak krusial)
    // Dalam kasus nyata, fungsi delete (atau smart pointers) harus digunakan.
    // ... delete root, dll.
    
    return 0;
}
