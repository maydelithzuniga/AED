//
// Created by maydelithzuniga on 30/10/2026.
//
/*
 D. Robot que Gira
 time limit per test: 2 seconds
 memory limit per test: 256 megabytes

 Ian programa un robot que se mueve por un laberinto de n filas y m columnas.
 Cada casilla es libre (.) o es una pared (#). El robot empieza en la casilla
 (1,1) mirando hacia la derecha (hacia la columna 2) y debe llegar a la
 casilla (n,m), mirando en cualquier dirección.

 El robot entiende tres instrucciones, y cada una cuesta una acción:
   - avanzar: pasa a la casilla vecina hacia la que mira, si esa casilla
     existe y es libre;
   - izquierda: gira 90 grados a la izquierda sin moverse;
   - derecha: gira 90 grados a la derecha sin moverse.

 ¿Cuál es la menor cantidad de acciones para llegar a (n,m)?

 Input
 La primera línea contiene dos enteros n y m (1 <= n, m <= 1000).
 Cada una de las siguientes n líneas contiene una cadena de m caracteres
 '.' o '#'. Las casillas (1,1) y (n,m) son libres.

 Output
 Imprime la menor cantidad de acciones, o -1 si es imposible llegar.

 Ejemplo 1
 input:
 1 3
 ...
 output:
 2

 Ejemplo 2
 input:
 2 2
 .#
 ..
 output:
 4

 ---------------------------------------------------------------------------
 IDEA:
 - Estado = (fila, columna, dirección): n*m*4 <= 4*10^6 estados.
 - Cada acción cuesta 1, así que BFS da el mínimo.
 - Direcciones: 0 = derecha, 1 = abajo, 2 = izquierda, 3 = arriba.
   derecha = (d+1)%4, izquierda = (d+3)%4.
 - Transiciones desde (r,c,d): girar a la izquierda, girar a la derecha,
   avanzar (si la casilla destino existe y es libre).
 - Respuesta: mínimo dist en (n-1, m-1, d) para cualquier d (el BFS la
   encuentra al sacar el primer estado de esa casilla).
 - Complejidad O(n*m*4).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    const int dr[4] = {0, 1, 0, -1};
    const int dc[4] = {1, 0, -1, 0};

    // id = (r*m + c)*4 + d
    vector<int> dist(n * m * 4, -1);
    vector<int> q;
    q.reserve(n * m * 4);

    dist[0] = 0;                 // (0,0) mirando a la derecha (d = 0)
    q.push_back(0);

    for (size_t head = 0; head < q.size(); head++) {
        int id = q[head];
        int d = id & 3;
        int cell = id >> 2;
        int r = cell / m, c = cell % m;

        if (r == n - 1 && c == m - 1) {   // llegó a (n,m): primera vez = mínimo
            cout << dist[id] << "\n";
            return 0;
        }

        // girar izquierda y derecha
        for (int nd : {(d + 3) & 3, (d + 1) & 3}) {
            int nid = (cell << 2) | nd;
            if (dist[nid] == -1) {
                dist[nid] = dist[id] + 1;
                q.push_back(nid);
            }
        }

        // avanzar
        int nr = r + dr[d], nc = c + dc[d];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == '.') {