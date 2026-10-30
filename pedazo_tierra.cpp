//
// Created by maydelithzuniga on 20/10/2026.
//
#include <iostream>
#include <vector>
using namespace std;

void encontrar (int n, int m,int x, int y, vector<vector<char>> &mapa, vector<vector<int>> &adyacencia) {
    if (n==(x-1) and m==(y-1)) {
        return;
    }
    //Arriba
    if (n>=1 and mapa[n-1][m]!='.' ) {
        adyacencia[n].push_back(m);
        mapa[n-1][m]='.';
        encontrar(n-1,m,x,y,mapa,adyacencia);
        mapa[n-1][m]='#';
    }
    //Abajo
    if ( n<laberinto.size()-1 and laberinto[n+1][m]!='#') {
        laberinto[n+1][m]='#';
        encontrar(n+1,m,contador,x,y,laberinto);
        laberinto[n+1][m]='.';
    }
    //Derecha
    if ( m<laberinto[0].size()-1 and laberinto[n][m+1]!='#') {
        laberinto[n][m+1]='#';
        encontrar(n,m+1,contador,x,y,laberinto);
        laberinto[n][m+1]='.';
    }
    //izquierda
    if ( m>0 and laberinto[n][m-1]!='#') {
        laberinto[n][m-1]='#';
        encontrar(n,m-1,contador,x,y,laberinto);
        laberinto[n][m-1]='.';
    }
}


int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> terreno(n, vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>terreno[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {

        }
    }
    vector<vector<int>> adyacencia(n);
    return 0;
}
