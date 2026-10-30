//
// Created by maydelithzuniga on 30/10/2026.
//
/*
 E. Rompiendo paredes
 time limit per test: 2 seconds
 memory limit per test: 256 megabytes

 Miguel debe cruzar un terreno de n filas y m columnas desde la casilla (1,1)
 (esquina superior izquierda) hasta la casilla (n,m) (esquina inferior
 derecha). Las casillas son libres (.) o tienen una pared (#). Miguel puede
 pasar a una casilla vecina (arriba, abajo, izquierda o derecha); para entrar
 a una casilla con pared debe romperla, y romper una pared cuesta una
 herramienta. Una pared rota queda libre, pero como Miguel nunca necesita
 pasar dos veces por la misma casilla, eso no importa.

 Calcula el menor número de paredes que Miguel debe romper para llegar de
 (1,1) a (n,m). Las casillas (1,1) y (n,m) son libres.

 Input
 La primera línea contiene dos enteros n y m (1 <= n, m <= 1000, n*m >= 2).
 Cada una de las siguientes n líneas contiene una cadena de m caracteres
 '.' o '#'. Las casillas (1,1) y (n,m) son '.'.

 Output
 Imprime un único entero: el menor número de paredes que hay que romper.

 Ejemplo 1
 input:
 5 6
 ..#.#.
 .##.#.
 .#..#.
 .####.
 ......
 output:
 0

 Ejemplo 2
 input:
 5 5
 ..#..
 ###.#
 ..#..
 .###.
 .....
 output:
 1

 (El enunciado tiene un tercer ejemplo 3x3 que no se alcanza a ver.)

 ---------------------------------------------------------------------------
 IDEA:
 - Grafo de casillas con costo al ENTRAR: 1 si la casilla destino es '#',
   0 si es '.'.
 - Es un camino mínimo con pesos 0/1 -> 0-1 BFS con deque.
   Peso 0: push_front. Peso 1: push_back.
 - Respuesta: dist[n-1][m-1].
 - Complejidad O(n*m).
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

    const int INF = 1e9;
    vector<int> dist(n * m, INF);
    deque<int> dq;

    dist[0] = 0;
    dq.push_back(0);

    while (!dq.empty()) {
        int id = dq.front();
        dq.pop_front();
        int r = id / m, c = id % m;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

            int w = (g[nr][nc] == '#') ? 1 : 0;   // costo de entrar
            int nid = nr * m + nc;

            if (dist[id] + w < dist[nid]) {
                dist[nid] = dist[id] + w;
                if (w == 0) dq.push_front(nid);
                else dq.push_back(nid);
            }
        }
    }

    cout << dist[n * m - 1] << "\n";
    return 0;
}