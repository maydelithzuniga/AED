//
// Created by maydelithzuniga on 30/10/2026.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;                 // n pueblos, m caminos, k hospitales

    vector<int> hosp(k);
    for (int i = 0; i < k; i++) cin >> hosp[i];   // pueblos con hospital

    vector<vector<int>> g(n + 1);       // grafo: pueblos = nodos
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);              // caminos bidireccionales
        g[v].push_back(u);              // (repetidos no molestan en BFS)
    }

    vector<int> dist(n + 1, -1);        // -1 = no llega a ningún hospital
    queue<int> q;

    for (int h : hosp) {                // un hospital está a 0 pasos de sí mismo
        dist[h] = 0;
        q.push(h);                      // todos entran juntos = multifuente
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : g[x]) {            // cada camino = 1 paso
            if (dist[y] == -1) {        // primera vez que se llega = más cercano
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }

    for (int i = 1; i <= n; i++)        // respuesta de cada pueblo, del 1 al n
        cout << dist[i] << " \n"[i == n];
    return 0;
}