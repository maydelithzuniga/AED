//
// Created by maydelithzuniga on 22/10/2026.
//
#include <iostream>
#include <vector>
using namespace std;

void mayor_rango(vector<int> &v,int max, int comienza, int termina) {
    if (comienza == termina) {
        max=v[comienza];
    }
    else {
        
    }
}

int main() {

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin>>v[i];
    }

    return 0;
}