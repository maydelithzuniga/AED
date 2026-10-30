//
// Created by maydelithzuniga on 27/10/2026.
//
#include <iostream>
#include <vector>
using namespace std;

// NUEVO: verificar que todas las aristas estén en una componente
//int inicio=-1;
//for (int i=1;i<=n;i++) if (!g[i].empty()) {inicio=i;break;}
//if (inicio!=-1) dfs(inicio);
//for (int i=1;i<=n;i++) {
    //if (!g[i].empty() && !visto[i]) {
        //cout<<"IMPOSIBLE"<<endl;
        //return 0;
    

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    int u,v;

    for (int i=0;i<m;i++) {
        cin>>u>>v;
        if (u==v) {g[u].push_back(v); g[u].push_back(v);continue;}
        g[u].push_back(v);
        g[v].push_back(u);
    }



    int impar=0;
    for (int i=1;i<=n;i++) {
        int cantidad=g[i].size();
        if (cantidad%2!=0) {
            impar++;
        }
    }
    if (impar==2) {
        cout<<"CAMINO"<<endl;
    }
    else if (impar==0) {
        cout<<"CIRCUITO"<<endl;
    }
    else {
        cout<<"IMPOSIBLE"<<endl;
    }


    return 0;
}