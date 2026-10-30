//
// Created by maydelithzuniga on 30/10/2026.
//Idea: BFS sobre las casillas 1..N. Cada turno es una arista: desde x puedes ir a x+d para d en 1..D con x+d ≤ N. Si la casilla destino es especial (a_i), te teletransportas a b_i en el mismo turno. Como no hay cadenas (ningún b_i es un a_j), basta un solo salto de teletransporte.

//Cada turno cuesta 1, así que BFS da el mínimo. Complejidad O(N·D) = 10^7, entra bien.

//etalle: la casilla 1 nunca es especial (a_i ≥ 2), y N tampoco (a_i ≤ N-1), así que no hay problema en los extremos.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D, k;
    cin >> N >> D >> k;

    vector<int> to(N + 1, 0);   // to[a] = b si a es especial, 0 si no
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        to[a] = b;
    }

    vector<int> dist(N + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == N) break;
        for (int d = 1; d <= D; d++) {
            int y = x + d;
            if (y > N) break;
            if (to[y]) y = to[y];
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }

    cout << dist[N] << "\n";
    return 0;
}