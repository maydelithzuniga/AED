//
// Created by maydelithzuniga on 30/10/2026.
//Idea: BFS sobre los códigos como números de 0 a 10^w - 1 (máximo 10 000 estados). Desde cada código, cada una de las w ruedas se puede girar +1 o -1 (con vuelta), dando hasta 2w vecinos. Se prohíben los códigos de la lista. Si s o t están prohibidos, la respuesta es -1.

//Detalle: hay que tratar el código como cadena de exactamente w dígitos (con ceros a la izquierda), así que lo manejo como entero y extraigo cada dígito con 10^pos.

//Complejidad: O(10^w · 2w), trivial.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w;
    string s, t;
    cin >> w >> s >> t;

    int k;
    cin >> k;

    int total = 1;
    for (int i = 0; i < w; i++) total *= 10;

    vector<char> ban(total, 0);
    for (int i = 0; i < k; i++) {
        string c;
        cin >> c;
        ban[stoi(c)] = 1;
    }

    int S = stoi(s), T = stoi(t);

    if (ban[S] || ban[T]) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> dist(total, -1);
    queue<int> q;
    dist[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == T) break;
        int p = 1;
        for (int pos = 0; pos < w; pos++) {
            int d = (x / p) % 10;
            for (int delta : {1, 9}) {          // +1 y -1 (mod 10)
                int nd = (d + delta) % 10;
                int y = x - d * p + nd * p;
                if (!ban[y] && dist[y] == -1) {
                    dist[y] = dist[x] + 1;
                    q.push(y);
                }
            }
            p *= 10;
        }
    }

    cout << dist[T] << "\n";
    return 0;
}