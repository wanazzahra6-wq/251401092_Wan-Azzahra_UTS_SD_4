#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Stack {
    char data[MAX];
    int top = -1;

    void push(char c) {
        if (top < MAX - 1) {
            data[++top] = c;
        }
    }

    char pop() {
        if (top >= 0) {
            return data[top--];
        }
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;
    string kata, kataDibalik = "";

    cout << "Masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        s.push(kata[i]);
    }

    while (!s.isEmpty()) {
        kataDibalik += s.pop();
    }

    cout << "Kata dibalik: " << kataDibalik << endl;
    if (kata == kataDibalik) {
        cout << "Kesimpulan : Kata ini palindrom" << endl;
    } else {
        cout << "Kesimpulan : Bukan palindrom" << endl;
    }

    return 0;
}

