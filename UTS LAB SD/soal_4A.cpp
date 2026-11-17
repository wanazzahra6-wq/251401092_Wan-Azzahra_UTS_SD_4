#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* buatNode(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

Node* insertBST(Node* root, int nilai) {
    if (root == NULL) {
        return buatNode(nilai);
    }
    if (nilai < root->data) {
        root->left = insertBST(root->left, nilai);
    } else if (nilai > root->data) {
        root->right = insertBST(root->right, nilai);
    }
    return root;
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int cariMinimal(Node* root) {
    if (root == NULL) return -1;
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int cariMaksimal(Node* root) {
    if (root == NULL) return -1;
    Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

int main() {
    Node* root = NULL;
    int angka;

    cout << "Masukan (akhiri dengan 0): ";
    while (cin >> angka && angka != 0) {
        root = insertBST(root, angka);
    }

    cout << "\nIn-Order       : ";
    inOrder(root);
    cout << endl;

    if (root != NULL) {
        cout << "Nilai terkecil : " << cariMinimal(root) << endl;
        cout << "Root           : " << root->data << endl;
    }

    return 0;
}