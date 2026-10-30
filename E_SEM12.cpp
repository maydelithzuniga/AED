//
// Created by maydelithzuniga on 30/10/2026.
//
/*
 C. Equipos Rivales
 time limit per test: 2 seconds
 memory limit per test: 256 megabytes

 Para un torneo escolar, Ivett tiene que repartir a n estudiantes en dos
 equipos, el rojo y el azul (un equipo puede quedar vacío). Hay m rivalidades
 entre parejas de estudiantes, y dos estudiantes rivales no pueden quedar en
 el mismo equipo.

 Si es imposible, imprime NO. Si es posible, imprime SI seguido del número de
 formas distintas de repartir a los estudiantes en los dos equipos, módulo
 10^9 + 7. Dos repartos son distintos si algún estudiante cambia de equipo
 (el equipo rojo y el azul son distintos).

 Input
 La primera línea contiene dos enteros n y m (1 <= n <= 2*10^5, 0 <= m <= 2*10^5).
 Cada una de las siguientes m líneas contiene dos enteros u y v
 (1 <= u, v <= n, u != v): los estudiantes u y v son rivales.
 Puede haber rivalidades repetidas.

 Output
 Imprime NO si no existe un reparto válido, o SI x con x el número de
 repartos módulo 10^9 + 7.

 Ejemplo 1
 input:
 7 4
 1 2
 2 3
 3 4
 5 6
 output:
 SI 8

 Ejemplo 2
 input:
 5 4
 1 2
 2 3
 3 1
 4 5
 output:
 NO

 Note
 En el primer ejemplo hay grupos de estudiantes conectados por rivalidades
 ({1,2,3,4}, {5,6} y el aislado {7}): son 3 grupos y cada uno se puede
 repartir de 2 formas, así que hay 2^3 = 8 repartos. En el segundo ejemplo
 los estudiantes 1, 2 y 3 son rivales entre sí y no se pueden repartir en
 solo dos equipos.

 ---------------------------------------------------------------------------
 IDEA:
 - Grafo con estudiantes como nodos y rivalidades como aristas.
 - Un reparto válido existe sii el grafo es bipartito (sin ciclos impares).
 - Cada componente conexa bipartita se colorea de 2 formas (se puede
   intercambiar rojo/azul). Los aislados también cuentan como componente.
 - Respuesta: 2^(#componentes) mod 1e9+7.
 - BFS con coloreo, O(n + m).
*/

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> color(n + 1, -1);   // -1 sin visitar, 0 rojo, 1 azul
    long long ans = 1;

    for (int s = 1; s <= n; s++) {
        if (color[s] != -1) continue;

        ans = ans * 2 % MOD;        // nueva componente: 2 formas
        color[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : g[x]) {
                if (color[y] == -1) {
                    color[y] = color[x] ^ 1;
                    q.push(y);
                } else if (color[y] == color[x]) {
                    cout << "NO\n";  // ciclo impar
                    return 0;
                }
            }
        }
    }

    cout << "SI " << ans << "\n";
    return 0;
}