//
// Created by maydelithzuniga on 17/10/2026.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int partidas;
    cin>>partidas;
    vector <vector<long long int>> v;
    int x;
    while(partidas>0) {
        vector<long long int>v2;
        for (int i=0;i<2;i++) {
            cin>>x;
            v2.push_back(x);
        }
        v.push_back(v2);
        partidas--;
    }
    for (int i=0;i<v.size();i++) {
        stack<int> turnos;
        long long int k= v[i][0];
        long long int j= v[i][1];
        int turno=1;
        while (k>=j) {
            k-=j;
            turnos.push(turno);
            if (turno==1) {
                turno=2;
            }
            else {
                turno=1;
            }

        }
        if (turnos.top()==1) {
            cout << "Ian" << "\n";
        }
        else {
            cout << "Sergio" << "\n";
        }
    }


    return 0;
}