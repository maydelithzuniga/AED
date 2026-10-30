//
// Created by maydelithzuniga on 24/09/2026.
//
#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    cin>>n;
    queue<pair<string, int>> fila;
    int tiempo_limite=0;
    cin>>tiempo_limite;
    string nombre;
    int numero;
    for (int i = 0; i < n; i++) {
        cin>>nombre;
        cin>>numero;
        fila.push(make_pair(nombre, numero));

    }
    int tiempo_total=0;
    int valor=0;
    string nombre_2;
    while (!fila.empty()) {
        if (fila.front().second<=tiempo_limite) {
            tiempo_total+=fila.front().second;
            cout<<fila.front().first<<" "<<tiempo_total<<endl;
            fila.pop();
        }
        else {
            tiempo_total= tiempo_total + tiempo_limite;
            valor=fila.front().second-tiempo_limite;
            nombre_2=fila.front().first;
            fila.pop();
            fila.push(make_pair(nombre_2, valor));
        }

    }


    return 0;

}