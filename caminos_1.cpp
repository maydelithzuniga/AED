#include <iostream>
#include <vector>
using namespace std;

void encontrar (int n, int m, int &contador, int x, int y, vector<vector<char> > &laberinto) {
    if (n==(x-1) and m==(y-1)) {
        contador++;
        return;
    }
    //Arriba
    if (n>=1 and laberinto[n-1][m]!='#' ) {
        laberinto[n-1][m]='#';
        encontrar(n-1,m,contador,x,y,laberinto);
        laberinto[n-1][m]='.';
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


int main () {
    int n;
    int m;
    cin>>n>>m;
    vector<vector<char>> laberinto(n, vector<char>(m));;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>laberinto[i][j];
        }
    }
    laberinto[0][0] = '#';                         // <-- esta línea
    int contador = 0;
    encontrar(0,0,contador,n,m,laberinto);
    cout << contador << endl;




    return 0;
}