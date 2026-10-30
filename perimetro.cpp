//
// Created by maydelithzuniga on 27/10/2026.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> g(n,vector<char>(m));
    map<int,int> v;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>g[i][j];
        }
    }
    int perimetro=0;
    int contador=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            contador=0;
            if (g[i][j]=='#') {
                int arriba=i-1;
                int abajo=i+1;
                int izquierda=j-1;
                int derecha=j+1;
                if (arriba!=-1 and g[arriba][j]=='#') {
                    contador++;
                }
                else {
                    perimetro++;
                }
                if (abajo!=n and g[abajo][j]=='#') {
                    contador++;
                }
                else {
                    perimetro++;
                }
                if (izquierda!=-1 and g[i][izquierda]=='#') {
                    contador++;
                }
                else {
                    perimetro++;
                }
                if (derecha!=m and g[i][derecha]=='#') {
                    contador++;
                }
                else {
                    perimetro++;
                }
            }
            else {
                continue;
            }
            v[contador]++;
        }
    }
    cout<<perimetro<<" ";
    for(int i=0;i<=4;i++) {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
