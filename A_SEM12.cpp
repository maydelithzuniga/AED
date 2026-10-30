//
// Created by maydelithzuniga on 30/10/2026.
//
#include <bits/stdc++.h>
using namespace std;

int p[200005], vs[200005], es[200005];

int find(int x) {
    while (p[x] != x) {
        p[x] = p[p[x]];
        x = p[x];
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        vs[i] = 1;
        es[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int a = find(u), b = find(v);
        if (a == b) {
            es[a]++;
        } else {
            // unir b dentro de a
            p[b] = a;
            vs[a] += vs[b];
            es[a] += es[b] + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (find(i) == i && es[i] > vs[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "SI\n";
    return 0;
}