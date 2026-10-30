//
// Created by maydelithzuniga on 13/10/2026.
//
#include <iostream>
#include <vector>
using namespace std;

void cantidad_conjuntos(int i, int suma, vector<int> &conjunto, int &contador) {
    if (suma<0) return;
    if (i == conjunto.size()) {
        if (suma == 0) 
            contador++;
            return;

    }
     cantidad_conjuntos(i+1, suma-conjunto[i], conjunto, contador); cantidad_conjuntos(i+1, suma, conjunto, contador);
}

int main() {
    int cantidad;
    cin >> cantidad;
    int suma;
    cin >> suma;
    vector<int> conjunto;
    int x;
    for (int i = 0; i < cantidad; i++) {
        cin>>x;
        conjunto.push_back(x);
    }
    int contador=0;
    cantidad_conjuntos(0, suma, conjunto, contador);
    cout<<contador<<"\n";

    return 0;
}
