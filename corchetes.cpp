//
// Created by maydelithzuniga on 15/10/2026.
//
#include <iostream>
#include <stack>
using namespace std;

bool validar( string s) {
    stack<char> cola;
    for (int i = 0; i < s.length(); i++) {
        if (s[i]=='(')
        cola.push(s[i]);
        else {
            if (cola.empty()) return false;
            cola.pop();
        }
    }
    if (cola.empty())
        return true;
    return false;
}

void cadenas(string s, int size) {
    if (s.length() == size) {
        if (validar(s)) {
            cout << s << endl;
        }
        return;
    }
    cadenas(s+"(", size);
    cadenas(s+")", size);
}


int main() {
    int n;
    cin >> n;
    int size=n*2;
    cadenas("(", size);




    return 0;
}