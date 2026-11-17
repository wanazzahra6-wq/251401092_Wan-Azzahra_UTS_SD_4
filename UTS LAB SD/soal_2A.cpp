#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Masukkan jumlah node: ";
    cin >> n;

    cout << "Masukkan nilai node:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nHasil penelusuran (dari kecil ke besar): ";
    inorder(root);
    cout << endl;

    void hapusNode(int nilaiHapus) {
    if (head == NULL) return;

    if (head->nilai == nilaiHapus) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->nilai != nilaiHapus) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
    } else {
        cout << "Nilai " << nilaiHapus << " tidak ditemukan!" << endl;
    }
}
    return 0;
    
}