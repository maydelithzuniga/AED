//
// Created by maydelithzuniga on 30/10/2026.
//
/*
 G. Rompecabezas Deslizante
 time limit per test: 2 seconds
 memory limit per test: 256 megabytes

 Joel tiene un rompecabezas deslizante de 2 filas y 3 columnas con cinco
 fichas numeradas del 1 al 5 y un espacio vacío, que se escribe 0. En un
 movimiento, una ficha que está al lado del espacio vacío (arriba, abajo,
 izquierda o derecha) se desliza hacia él; el espacio queda donde estaba la
 ficha. El rompecabezas está resuelto cuando se ve así:

 1 2 3
 4 5 0

 Dada la posición actual, ¿cuál es la menor cantidad de movimientos para
 resolverlo?

 Input
 Cada una de las 2 líneas contiene 3 enteros separados por espacios: la
 posición actual del rompecabezas. Los seis números del 0 al 5 aparecen
 exactamente una vez.

 Output
 Imprime la menor cantidad de movimientos para resolver el rompecabezas,
 o -1 si es imposible.

 Ejemplo 1
 input:
 1 2 3
 4 0 5
 output:
 1

 Ejemplo 2
 input:
 2 1 3
 4 5 0
 output:
 -1

 Note
 En el primer ejemplo basta mover la ficha 5 hacia la izquierda... (según el
 enunciado: "hacia la derecha"; el espacio queda donde estaba la ficha).
 En el segundo, intercambiar dos fichas de un rompecabezas resuelto deja una
 posición que no se puede resolver con movimientos legales.

 ---------------------------------------------------------------------------
 IDEA:
 - Estado = permutación de 6 casillas, como string de 6 caracteres.
   Hay 6! = 720 estados como máximo.
 - BFS desde el estado inicial hasta "123450"; cada movimiento cuesta 1.
 - Vecinos: se intercambia el 0 con una casilla adyacente en la grilla 2x3
   (índice i -> fila i/3, columna i%3).
 - Si no se alcanza el objetivo, -1 (la mitad de las permutaciones no son
   alcanzables, como en el ejemplo 2).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string start = "";
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        start += char('0' + x);
    }
    string target = "123450";

    // adj[i] = casillas adyacentes a la casilla i en la grilla 2x3
    vector<vector<int>> adj(6);
    for (int i = 0; i < 6; i++) {
        int r = i / 3, c = i % 3;
        if (r > 0) adj[i].push_back(i - 3);
        if (r < 1) adj[i].push_back(i + 3);
        if (c > 0) adj[i].push_back(i - 1);
        if (c < 2) adj[i].push_back(i + 1);
    }

    map<string, int> dist;
    queue<string> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        string s = q.front();
        q.pop();
        if (s == target) {
            cout << dist[s] << "\n";
            return 0;
        }
        int z = s.find('0');
        for (int nb : adj[z]) {
            string t = s;
            swap(t[z], t[nb]);
            if (!dist.count(t)) {
                dist[t] = dist[s] + 1;
                q.push(t);
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}