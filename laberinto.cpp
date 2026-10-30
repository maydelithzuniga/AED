//
// Created by maydelithzuniga on 28/10/2026.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector <vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>v[i][j];
        }
    }
    queue<pair<int,int>> cola;
    vector<int> dc={1,-1,0,0};
    vector<int> dn={0,0,1,-1};
    pair<int,int> entrada;
    pair<int,int> salida;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j]=='S') {
                entrada={i,j};
            }
            else if (v[i][j]=='E') {
                salida={i,j};
            }
        }
    }
    vector<vector<int>> distancia(n,vector<int>(m,0));
    vector<vector<bool>> usado(n,vector<bool>(m,false));
    cola.push(entrada);
    pair<int,int> par;
    distancia[entrada.first][entrada.second]=0;
    usado[entrada.first][entrada.second]=true;
    while (!cola.empty()) {
        par=cola.front();
        cola.pop();
        for (int i = 0; i < 4; i++) {
            int x=par.first + dc[i];
            int y=par.second+dn[i];
            if (x>=0 and x<n and y>=0 and y<m) {
                if (usado[x][y]==false and v[x][y]!='#') {
                    usado[x][y]=true;
                    distancia[x][y]=distancia[par.first][par.second]+1;
                    cola.push({x,y});
                }
                else {
                    continue;
                }
            }
            else {
                continue;
            }

        }
    }
    if (distancia[salida.first][salida.second]==0) {
        cout<<"-1"<<endl;
    }
    else {
        cout<<distancia[salida.first][salida.second]<<endl;
    }
    return 0;
}
